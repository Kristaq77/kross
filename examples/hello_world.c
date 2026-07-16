// -------------------------------------
#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(800, 600);
  kw_init(kv, " Hello World");
  kw_target_fps(60);
  // --------------
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);
    // --------------
    kv_rect(kv, 400-25, 300-25, 50, 50, KLEAN_YELLOW);
    // --------------
    kv_stop(kv);
  }

  kv_free(kv);
  kw_free();
  return 0;
}
// -------------------------------------
