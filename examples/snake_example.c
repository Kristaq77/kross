// -------------------------------------
#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"
#include <stdlib.h>
#include <stdbool.h>
// -------------------------------------
int main(void)
{
  const int MAX_COLS         = 16;
  const int MAX_ROWS         = 10;
  const int MAX_PARTS        = MAX_COLS*MAX_ROWS;
  const int SQUARE_SIZE      = 80;
  const int APPLE_SIZE       = SQUARE_SIZE;
  const int STROKE_THICKNESS = 3;
  const float MOVE_DURATION  = 0.15;
  // --------------
  Kolor background_kolor  = KLEAN_BLACK;
  Kolor grid_kolor        = KLEAN_GRAY;
  Kolor snake_kolor       = KLEAN_YELLOW;
  Kolor apple_kolor       = KLEAN_RED;
  // --------------
  typedef enum GameState {
    GAME_PLAYING,
    GAME_WAITING,
    GAME_OVER,
  } GameState;
  // --------------
  typedef enum SnakeDirection {
    UP,
    DOWN,
    LEFT,
    RIGHT,
  } SnakeDirection;
  // --------------
  typedef struct SnakePart {
    int col;
    int row;
    int pre_col;
    int pre_row;
  } SnakePart;
  // --------------
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Snake");
  kw_target_fps(60);
  // --------------
  GameState state;
  SnakeDirection dir;
  SnakeDirection last_moved_dir;
  size_t count;
  SnakePart parts[MAX_PARTS];
  SnakePart *head;
  // --------------
  Kolor lerped_kolor;
  float key_timer;
  float time_moved;
  float snake_t;
  // --------------
  float apple_col;
  float apple_row;
  float apple_timer;
  bool  apple_has_spawned;
  float death_timer;
  bool needs_reset = true;
  // --------------
  while (!kw_should_close())
  {
    if (needs_reset)
    {
      state = GAME_PLAYING;
      dir = RIGHT;
      last_moved_dir = RIGHT;
      count = 2;
      // --------------
      key_timer   = 0;
      time_moved  = 0;
      snake_t     = 0;
      apple_col   = 0;
      apple_row   = 0;
      apple_timer = 0;
      apple_has_spawned = false;
      death_timer = 0;
      lerped_kolor = snake_kolor;
      // --------------
      for (size_t i = 0; i < MAX_PARTS; ++i) parts[i] = (SnakePart){0};
      // --------------
      for (size_t i = 0; i < count; ++i)
      {
        parts[i].col = MAX_COLS/2+i;
        parts[i].row = MAX_ROWS/2;
        parts[i].pre_col = MAX_COLS/2+i;
        parts[i].pre_row = MAX_ROWS/2;
      }
      
      head = &(parts[0]);
      needs_reset = false;
    }

    kv_start(kv);
    kv_fill(kv, background_kolor);
    // --------------
    if (state == GAME_PLAYING)
    {
      key_timer   += kw_delta()*4;
      apple_timer += kw_delta()*3;
      time_moved  += kw_delta();
      snake_t      = time_moved/MOVE_DURATION;
      // --------------
      if (ki_down(KI_W) && last_moved_dir != DOWN && key_timer > 0.5)       { key_timer = 0; dir = UP;    }
      else if (ki_down(KI_A) && last_moved_dir != RIGHT && key_timer > 0.5) { key_timer = 0; dir = LEFT;  }
      else if (ki_down(KI_S) && last_moved_dir != UP && key_timer > 0.5)    { key_timer = 0; dir = DOWN;  }
      else if (ki_down(KI_D) && last_moved_dir != LEFT && key_timer > 0.5)  { key_timer = 0; dir = RIGHT; }
      // --------------
      if (!apple_has_spawned)
      {
        bool valid_spot = false;
        while (!valid_spot)
        {
          apple_col = rand()%MAX_COLS;
          apple_row = rand()%MAX_ROWS;
          valid_spot = true;
          // --------------
          for (size_t i = 0; i < count; ++i)
          {
            if (parts[i].col == apple_col && parts[i].row == apple_row)
            {
              valid_spot = false;
              break;
            }
          }
        }

        apple_has_spawned = true;
      }

      if (apple_has_spawned && head->col == apple_col && head->row == apple_row)
      {
        apple_col = MAX_COLS*2;
        apple_row = MAX_ROWS*2;
        apple_has_spawned = false;
        apple_timer = 0;
        // --------------
        if (count < MAX_PARTS) count++;
        // --------------
        SnakePart tail = parts[count-2];
        parts[count-1] = (SnakePart){tail.col, tail.row, tail.col, tail.row};
        lerped_kolor = kl_lerp(apple_kolor, snake_kolor, snake_t*5);
      }

      if (snake_t >= 1)
      {
        for (size_t i = count-1; i != 0; --i)
        {
          parts[i].pre_col = parts[i].col;
          parts[i].pre_row = parts[i].row;
          parts[i].col = parts[i-1].col;
          parts[i].row = parts[i-1].row;
        }

        // --------------
        head->pre_col = head->col;
        head->pre_row = head->row;
        // --------------
        if (dir == UP)    head->row--;
        if (dir == LEFT)  head->col--;
        if (dir == DOWN)  head->row++;
        if (dir == RIGHT) head->col++;
        // --------------
        last_moved_dir = dir;
        // --------------
        if (head->col < 0 || head->col >= MAX_COLS || head->row < 0 || head->row >= MAX_ROWS) state = GAME_OVER;
        // --------------
        for (size_t i = 1; i < count; ++i)
        {
          if ((int)head->col == (int)parts[i].col && (int)head->row == (int)parts[i].row) state = GAME_OVER;
        }
        // --------------
        lerped_kolor = snake_kolor;
        time_moved = 0;
        snake_t = 0;
      }
    }

    if (apple_timer > 1)  apple_timer = 1;
    // --------------
    int apple_x = apple_col*SQUARE_SIZE;
    int apple_y = apple_row*SQUARE_SIZE;
    // --------------
    Kolor apple_kolor_lerped = {apple_kolor.r, apple_kolor.g, apple_kolor.b, (uint8_t)(apple_timer*255)};
    // --------------
    kv_rect(kv, apple_x, apple_y, APPLE_SIZE, APPLE_SIZE, apple_kolor_lerped);
    kv_grid(kv, 0, 0, MAX_COLS, MAX_ROWS, SQUARE_SIZE, STROKE_THICKNESS, grid_kolor);
    // --------------
    int axis[MAX_PARTS];
    // --------------
    for (size_t i = 0; i < count; ++i)
    {
      if (parts[i].pre_col != parts[i].col)      axis[i] = 1;
      else if (parts[i].pre_row != parts[i].row) axis[i] = 2;
      else                                        axis[i] = 0;
    }

    for (size_t i = 0; i < count; ++i)
    {
      float lerpc = km_lerp(parts[i].pre_col, parts[i].col, snake_t);
      float lerpr = km_lerp(parts[i].pre_row, parts[i].row, snake_t);
      // --------------
      int x = lerpc*SQUARE_SIZE;
      int y = lerpr*SQUARE_SIZE;
      // --------------
      kv_rect(kv, x, y, SQUARE_SIZE, SQUARE_SIZE, lerped_kolor);
      // --------------
      if (i + 1 < count && axis[i] != 0 && axis[i+1] != 0 && axis[i] != axis[i+1])
      {
        int px = (int)(parts[i].pre_col * SQUARE_SIZE);
        int py = (int)(parts[i].pre_row * SQUARE_SIZE);
        // --------------
        kv_rect(kv, px, py, SQUARE_SIZE, SQUARE_SIZE, lerped_kolor);
      }
    }

    if (state == GAME_OVER)
    {
      death_timer += kw_delta();
      float fade = KMIN(death_timer/1.0f, 0.85f);
      Kolor overlay_kolor = {0, 0, 0, (uint8_t)(fade*255)};
      // --------------
      kv_rect(kv, 0, 0, kv->w, kv->h, overlay_kolor);
      // --------------
      if (ki_down(KI_R)) needs_reset = true; 
    }

    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
// -------------------------------------
