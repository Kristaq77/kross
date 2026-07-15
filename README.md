# kross
This project is my painful 1-year journey through C and computer graphics.                                                           
Kross is a software rasterizer with a tiny math "library", color manipulation, interpolation, procedural noise, and whatever else I ended up needing along the way.

It is meant to be read, so I dont wanna hear any complaints when this thing runs at 60 seconds per frame instead of 60 frames per second.
It is very, very heavily commented, with comments and explanations that I wish I had starting out.

This project is dedicated to God and Orthodox Christianity, as a small thank you for everything I have been given in life.  
I wont be accepting contributions because this is a personal project, and I want it to stay that way.

Hello World example:

```c
#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"

int main(void)
{
  Kanvas* kv = kv_init(800, 600);
  kw_init(kv, " Hello World");
  kw_target_fps(60);

  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);

    kv_rect(kv, 400-25, 300-25, 50, 50, KLEAN_YELLOW);

    kv_stop(kv);
  }

  kv_free(kv);
  kw_free();
  return 0;
}
