// -------------------------------------
#include <math.h>
#include <stdlib.h>
#include <time.h>
// -------------------------------------
#define KROSS_IMPLEMENTATION
#include "kross.h"
// -------------------------------------
typedef struct Seed {
  int x, y;
  Kolor kl;
} Seed;
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Voronoi Diagram");
  kw_target_fps(60);
  // --------------
  Kolor kolors[] = {KLEAN_BLUE,   KLEAN_RED,    KLEAN_YELLOW, 
                    KLEAN_ORANGE, KLEAN_PURPLE, KLEAN_GREEN};
  // --------------
  srand((unsigned int)time(NULL));
  // --------------
  Seed seeds[15];
  // --------------
  for (int i = 0; i < 15; ++i)
  {
    seeds[i].x = rand()%kv->w;
    seeds[i].y = rand()%kv->h;
    seeds[i].kl = kolors[i%6];
  }
  while (!kw_should_close())
  {
    kv_start(kv);

    for (int dy = 0; dy < (int)kv->h; ++dy)
    {
      for (int dx = 0; dx < (int)kv->w; ++dx)
      {
        Kolor seed_kolor = KLEAN_BLACK;
        int shortest = 2000000;
        // --------------
        for (size_t i = 0; i < 15; ++i)
        {
          int x = seeds[i].x;
          int y = seeds[i].y;
          // --------------
          int dist = (dx-x) * (dx-x) + (dy-y) * (dy-y);
          // --------------
          if (dist < shortest)
          {
            shortest = dist;
            seed_kolor = seeds[i].kl;
          }
        }

        kv_pixel(kv, dx, dy, seed_kolor);
      }
    }

    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
// -------------------------------------
