#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"

int main(void)
{
  Kanvas* kv = kv_init(800, 600);
  kw_init(kv, "Title");
  int n = 360;

  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);

    for (int i = 0; i < n; ++i)
    {
      int x0 = i * kv->w / n;
      int x1 = (i + 1) * kv->w / n;
      int width = x1 - x0;

      float hue = (float)i/(float)n;
      float sat = 0.75f;
      float val = 1.0f;
      
      Kolor kl = kl_from_hsv(hue, sat, val);
      kv_rect(kv, x0, 0, width, kv->h, kl);
    }

    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
