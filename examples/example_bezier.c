// -------------------------------------
#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"
#include <stdlib.h>
#include <stdbool.h>
// -------------------------------------
typedef struct Points {
  Vek2 items[50];
  size_t count;
} Points;
// -------------------------------------
void points_append(Points* points, Vek2 value)
{
  if (points->count >= sizeof(points->items)/(sizeof(points->items[0]))) return;
  points->items[points->count++] = value;
}
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Bezier Example");
  kw_target_fps(60);
  Points points = {0};
  // --------------
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KROSS_KLEAN_BLACK);
    // --------------
    if (ki_once(KI_MOUSE_LEFT))
    {
      Vek2 mouse = ki_mouse_pos();
      points_append(&points, mouse);
    }

    for (size_t i = 0; i < points.count; ++i)
    {
      Vek2 pos = points.items[i];
      Vek2 size = {30, 30};
      Vek2 centered_pos = km_vek2_sub(pos, km_vek2_scale(size, 0.5));
      // --------------
      kv_rectv(kv, centered_pos, size, KROSS_KLEAN_YELLOW);
    }

    for (size_t i = 0; i+2 < points.count; i+=2)
    {
      Vek2 p1 = points.items[i];
      Vek2 control_p = points.items[i+1];
      Vek2 p2 = points.items[i+2];
      // --------------
      const size_t resolution = 30;
      kv_line_bezier_quad(kv, p1, control_p, p2, resolution, 3, KROSS_KLEAN_RED);
      // --------------
      if (ki_down(KI_TAB))
      {
        kv_linev(kv, p1, control_p, 1, KROSS_KLEAN_GREEN);
        kv_linev(kv, control_p, p2, 1, KROSS_KLEAN_GREEN);
        // --------------
        for (size_t j = 0; j <= resolution; ++j)
        {
          float t = (float)j/(float)resolution;
          Vek2 a = km_vek2_lerp(p1, control_p, t);
          Vek2 b = km_vek2_lerp(control_p, p2, t);
          // --------------
          kv_linev(kv, a, b, 1, KROSS_KLEAN_BLUE);
          // --------------
          Vek2 size = {4, 4};
          kv_rectv(kv, km_vek2_sub(a, km_vek2_scale(size, 0.5)), size, KROSS_KLEAN_BLUE);
          kv_rectv(kv, km_vek2_sub(b, km_vek2_scale(size, 0.5)), size, KROSS_KLEAN_BLUE);
        }
      }
    }

    if (ki_once(KI_R)) points.count = 0;
    // --------------
    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
// -------------------------------------
