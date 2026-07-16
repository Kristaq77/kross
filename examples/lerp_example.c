#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"

int main(void)
{
  // --------------
  Kanvas* kanvas = kv_init(600, 400);
  kw_init(kanvas, "Lerp");
  kw_target_fps(60);
  // --------------
  Kolor kolor     = {0};
  Kolor kolor_inv = {0};
  // --------------
  size_t rectw = 70;
  size_t recth = 70;
  // --------------
  int start_x = 0;
  int end_x = kanvas->w-rectw;
  // --------------
  int y = kanvas->h-recth;
  // --------------
  float move_duration = 5;
  float time_moved = 0;
  float lerp_t = 0;
  // --------------
  while (!kw_should_close())
  {
    // --------------
    kv_start(kanvas);
    kv_fill(kanvas, KLEAN_BLACK);
    // --------------
    // Eye candy.
    // --------------
    kv_line(kanvas, 0, 0, kanvas->w, 0, 3, kolor);
    kv_line(kanvas, 0, kanvas->h, kanvas->w, kanvas->h, 3, kolor);
    kv_line(kanvas, 0, 0, 0, kanvas->h, 3, kolor_inv);
    kv_line(kanvas, kanvas->w, 0, kanvas->w, kanvas->h, 3, kolor_inv);
    // --------------
    time_moved += kw_delta();
    lerp_t = time_moved/move_duration;
    lerp_t = kross_math_clampf(lerp_t, 0, 1);
    // --------------
    float lerp_x     = km_lerp(start_x, end_x, lerp_t);
    float lerp_x_inv = km_lerp(end_x, start_x, lerp_t);
    // --------------
    kolor     = kl_lerp(KLEAN_YELLOW, KLEAN_RED, lerp_t);
    kolor_inv = kl_lerp(KLEAN_RED, KLEAN_YELLOW, lerp_t);
    // --------------
    kv_rect(kanvas, lerp_x, y, rectw, recth, kolor);
    kv_rect(kanvas, lerp_x_inv, 0, rectw, recth, kolor_inv);
    // --------------
    if (lerp_t >= 1 && ki_once(KI_R)) time_moved = 0;
    // --------------
    kv_stop(kanvas);
    // --------------
  }

  kw_free();
  kv_free(kanvas);
}
