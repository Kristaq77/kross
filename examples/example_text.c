// -------------------------------------
#define KROSS_IMPLEMENTATION
#include "kross.h"
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Voronoi Diagram");
  kw_target_fps(60);
  // --------------
  const char* text = "Kristaq77/Kross";
  int len = kv_text_measure(text, 6);
  Kolor kolors[] = {KLEAN_RED, KLEAN_YELLOW, KLEAN_BLUE, KLEAN_GREEN};
  // --------------
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);
    // --------------
    kv_text_multi(kv, kv->w/2-len/2, kv->h*0.5f, text, 6, 4, kolors);
    // --------------
    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
