// -------------------------------------
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>
// -------------------------------------
#define KROSS_IMPLEMENTATION
#include "kross.h"
// -------------------------------------
typedef struct Points {
  Vek2 items[50];
  size_t count;
} Points;
// -------------------------------------
// WARNING: THE CODE AHEAD IS A MESS.
// -------------------------------------
void points_append(Points* points, Vek2 value)
{
  if (points->count >= sizeof(points->items)/(sizeof(points->items[0]))) return;
  points->items[points->count++] = value;
}
// -------------------------------------
void text_centered(Kanvas* kv, int y, int size, Kolor kolor, const char* text, ...)
{
  char buf[64];
  va_list args;
  va_start(args, text);
  vsnprintf(buf, sizeof(buf), text, args);
  va_end(args);
  // --------------
  int w = kv_text_measure(buf, size);
  kv_text(kv, (kv->w-w)/2, y, buf, size, kolor);
}
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Bezier Example");
  kw_target_fps(60);
  // --------------
  Points points = {0};
  size_t resolution = 30;
  bool tab_pressed_once = false;
  int res_hint_timer = 0;
  int discover_hint_timer = 0;
  // --------------
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);
    // --------------
    Vek2 mouse = ki_mouse_pos();
    // --------------
    if (ki_once(KI_MOUSE_LEFT)) points_append(&points, mouse);
    // --------------
    if (ki_once(KI_UP))
    {
      resolution += 2;
      res_hint_timer = 90;
    }
    if (ki_once(KI_DOWN))
    {
      resolution = (resolution > 2) ? resolution-2 : 2;
      res_hint_timer = 90;
    }
    if (res_hint_timer > 0) res_hint_timer--;
    // --------------
    bool show_construction = ki_down(KI_TAB);
    if (show_construction) tab_pressed_once = true;
    if (ki_up(KI_TAB) && tab_pressed_once) discover_hint_timer = 150;
    // --------------
    for (size_t i = 0; i < points.count; ++i)
    {
      Vek2 pos = points.items[i];
      Vek2 size = {30, 30};
      Vek2 centered_pos = km_vek2_sub(pos, km_vek2_scale(size, 0.5f));
      Kolor kolor = KLEAN_YELLOW;
      // --------------
      kv_rectv(kv, centered_pos, size, kolor);
      // --------------
      char label[16];
      snprintf(label, sizeof(label), "%zu", i);
      int label_w = kv_text_measure(label, 1);
      kv_text(kv, (int)(pos.x-label_w/2), (int)(pos.y-4), label, 1, KLEAN_BLACK);
    }
    for (size_t i = 0; i+2 < points.count; i+=2)
    {
      Vek2 p1 = points.items[i];
      Vek2 control_p = points.items[i+1];
      Vek2 p2 = points.items[i+2];
      // --------------
      kv_line_bezier_quad(kv, p1, control_p, p2, resolution, 3, KLEAN_RED);
      // --------------
      if (show_construction)
      {
        kv_linev(kv, p1, control_p, 1, KLEAN_GREEN);
        kv_linev(kv, control_p, p2, 1, KLEAN_GREEN);
        // --------------
        for (size_t j = 0; j <= resolution; ++j)
        {
          float t = (float)j/(float)resolution;
          Vek2 a = km_vek2_lerp(p1, control_p, t);
          Vek2 b = km_vek2_lerp(control_p, p2, t);
          // --------------
          kv_linev(kv, a, b, 1, KLEAN_BLUE);
          // --------------
          Vek2 size = {4, 4};
          kv_rectv(kv, km_vek2_sub(a, km_vek2_scale(size, 0.5f)), size, KLEAN_BLUE);
          kv_rectv(kv, km_vek2_sub(b, km_vek2_scale(size, 0.5f)), size, KLEAN_BLUE);
        }
      }
    }
    if (ki_once(KI_R)) points.count = 0;
    // --------------
    if (res_hint_timer > 0)     text_centered(kv, 16, 3, KLEAN_WHITE, "RESOLUTION %zu", resolution);
    else if (points.count < 3)  text_centered(kv, 16, 3, KLEAN_WHITE, "LMB TO PLACE POINTS");
    else if (!tab_pressed_once) text_centered(kv, 16, 3, KLEAN_WHITE, "PRESS TAB, TRUST ME");
    else if (discover_hint_timer > 0)
    {
      discover_hint_timer--;
      text_centered(kv, 16, 3, KLEAN_WHITE, "UP/DOWN: CHANGE RESOLUTION");
    }
    else text_centered(kv, 16, 3, KLEAN_WHITE, "POINTS %zu/50 (R TO RESET)", points.count);
    // --------------
    kv_stop(kv);
  }
  
  kw_free();
  kv_free(kv);
  return 0;
}
// -------------------------------------
