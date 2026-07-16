#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"
#include <math.h>

// To be fully honest, this file was made with AI.
int main(void)
{
  Kanvas* kv = kv_init(640, 480);
  kw_init(kv, "MOLTEN VORTEX SIMULATOR");
  kw_target_fps(60);

  float t = 0.0f;
  int scale = 2;

  Kolor COLOR_BG    = { 12,  10,  15,  255 };
  Kolor COLOR_EMBER = { 140, 15,  25,  255 };
  Kolor COLOR_FLAME = { 240, 110, 20,  255 };
  Kolor COLOR_CORE  = { 255, 210, 120, 255 };

  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);
    
    t += 0.02f;
    if (t > 256.0f) t -= 256.0f;

    Vek2 mouse = ki_mouse_pos();
    if (mouse.x != mouse.x || mouse.y != mouse.y || (mouse.x == 0.0f && mouse.y == 0.0f))
    {
      mouse.x = kv->w/2.0f;
      mouse.y = kv->h/2.0f;
    }

// #pragma omp parallel for schedule(dynamic)
// If we want better performance, we can use openmp, which multithreads the loop for us.
// GCC comes with openmp prebuilt, so switch to gcc and type:
// gcc perlin_example.c -fopenmp -lGL -lglfw -lm -O2 -o perlin_example && ./perlin_example
    for (int y = 0; y < kv->h; y += scale)
    {
      for (int x = 0; x < kv->w; x += scale)
      {
        float dx = x-mouse.x;
        float dy = y-mouse.y;
        float dist = sqrtf(dx*dx + dy*dy);
        if (dist < 0.1f) dist = 0.1f; 
        
        float angle = atan2f(dy, dx);

        float twist = sinf(dist*0.04f - t*1.5f) * 0.6f;
        float nx = (x*0.015f) + cosf(angle+twist) * 0.5f;
        float ny = (y*0.015f) + sinf(angle+twist) * 0.5f;

        float n = km_noise_3d_fbm(nx, ny, t * 0.3f, 3, 2.0f, 0.5f, KROSS_NOISE_PERLIN);
        
        n = (n+1.0f) * 0.5f;
        if (n < 0.0f) n = 0.0f;
        if (n > 1.0f) n = 1.0f;

        Kolor c;
        if (n < 0.3f) 
        {
          float blend = n/0.3f;
          c.r = (unsigned char)(COLOR_BG.r + blend*(COLOR_EMBER.r-COLOR_BG.r));
          c.g = (unsigned char)(COLOR_BG.g + blend*(COLOR_EMBER.g-COLOR_BG.g));
          c.b = (unsigned char)(COLOR_BG.b + blend*(COLOR_EMBER.b-COLOR_BG.b));
        } 
        else if (n < 0.7f) 
        {
          float blend = (n - 0.3f) / 0.4f;
          c.r = (unsigned char)(COLOR_EMBER.r+blend*(COLOR_FLAME.r-COLOR_EMBER.r));
          c.g = (unsigned char)(COLOR_EMBER.g+blend*(COLOR_FLAME.g-COLOR_EMBER.g));
          c.b = (unsigned char)(COLOR_EMBER.b+blend*(COLOR_FLAME.b-COLOR_EMBER.b));
        } 
        else 
        {
          float blend = (n - 0.7f) / 0.3f;
          c.r = (unsigned char)(COLOR_FLAME.r + blend*(COLOR_CORE.r - COLOR_FLAME.r));
          c.g = (unsigned char)(COLOR_FLAME.g + blend*(COLOR_CORE.g - COLOR_FLAME.g));
          c.b = (unsigned char)(COLOR_FLAME.b + blend*(COLOR_CORE.b - COLOR_FLAME.b));
        }
        c.a = 255;

        for (int block_y = 0; block_y < scale; ++block_y)
        {
          for (int block_x = 0; block_x < scale; ++block_x)
          {
            int tx = x + block_x;
            int ty = y + block_y;
            if (tx < kv->w && ty < kv->h) kv_pixel(kv, tx, ty, c);
          }
        }
      }
    }

    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
