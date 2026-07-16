// -------------------------------------
#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Barycentric Triangle");
  kw_target_fps(60);
  //--------------
  Vek2 v0 = {kv->w*0.5f, kv->h*0.25f};
  Vek2 v1 = {kv->w*0.25f, kv->h*0.75f};
  Vek2 v2 = {kv->w-kv->w*0.25f, kv->h*0.75f};
  //--------------
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);
    //--------------
    kv_triangle_tricolor(kv, v0, v1, v2, KLEAN_RED, KLEAN_GREEN, KLEAN_BLUE);
    //--------------
    kv_stop(kv); 
  }

  kw_free();
  kv_free(kv);
}
