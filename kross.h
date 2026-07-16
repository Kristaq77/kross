// -------------------------------------
// MIT License
// Copyright (c) 2026 Kristaq                                                                 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// -------------------------------------
// PERSONAL DISCLAIMER
// The point of Kross is not to replace your game engine.
// The point is for you to read the source code, and learn graphics programming basics.
// The code is slow, but I have a solid excuse, *educational*.
// Do not forget to strip the prefix if you decide to use Kross. Trust me.
// Other than that, I hope you learn something from here :).
// -------------------------------------
// AI USE
// The rasterizer part of my library is all written by me.
// The GPU part of my library uses OpenGL to take what the CPU drew and put it on the screen,
// That part was coded by AI, and If you scroll to that section, (line: 2447), you will see why.
// -------------------------------------
#ifndef KROSS_H
#define KROSS_H
// -------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// -------------------------------------
#include <GLFW/glfw3.h>
// -------------------------------------
#define KROSS_KLEAN_WHITE     (Kolor){255, 255, 255, 255}
#define KROSS_KLEAN_BLACK     (Kolor){25,  25,  25,  255}
#define KROSS_KLEAN_GRAY      (Kolor){130, 130, 130, 255}
#define KROSS_KLEAN_RED       (Kolor){210, 80,  80,  255}
#define KROSS_KLEAN_BLUE      (Kolor){70,  130, 180, 255}
#define KROSS_KLEAN_GREEN     (Kolor){85,  150, 100, 255}
#define KROSS_KLEAN_PURPLE    (Kolor){125, 115, 155, 255}
#define KROSS_KLEAN_ORANGE    (Kolor){230, 145, 80,  255}
#define KROSS_KLEAN_YELLOW    (Kolor){240, 215, 120, 255}
#define KROSS_KLEAN_PINK      (Kolor){178, 121, 167, 255}
#define KROSS_KLEAN_CYAN      (Kolor){96,  153, 192, 255}
#define KROSS_KLEAN_BROWN     (Kolor){140, 120, 100, 255}
// -------------------------------------
#define KROSS_CYBER_WHITE     (Kolor){230, 255, 255, 255}
#define KROSS_CYBER_BLACK     (Kolor){5,   5,   15,  255}
#define KROSS_CYBER_GRAY      (Kolor){45,  50,  70,  255}
#define KROSS_CYBER_RED       (Kolor){255, 20,  20,  255}
#define KROSS_CYBER_BLUE      (Kolor){0,   150, 255, 255}
#define KROSS_CYBER_GREEN     (Kolor){57,  255, 20,  255}
#define KROSS_CYBER_PURPLE    (Kolor){180, 0,   255, 255}
#define KROSS_CYBER_ORANGE    (Kolor){255, 150, 0,   255}
#define KROSS_CYBER_YELLOW    (Kolor){255, 255, 0,   255}
#define KROSS_CYBER_PINK      (Kolor){255, 20,  147, 255}
#define KROSS_CYBER_CYAN      (Kolor){0,   255, 255, 255}
#define KROSS_CYBER_BROWN     (Kolor){160, 80,  40,  255}
// -------------------------------------
#define KROSS_GRUNGE_WHITE    (Kolor){190, 190, 180, 255}
#define KROSS_GRUNGE_BLACK    (Kolor){15,  15,  15,  255}
#define KROSS_GRUNGE_GRAY     (Kolor){80,  80,  80,  255}
#define KROSS_GRUNGE_RED      (Kolor){120, 10,  10,  255}
#define KROSS_GRUNGE_BLUE     (Kolor){40,  55,  90,  255}
#define KROSS_GRUNGE_GREEN    (Kolor){35,  60,  35,  255}
#define KROSS_GRUNGE_PURPLE   (Kolor){70,  35,  85,  255}
#define KROSS_GRUNGE_ORANGE   (Kolor){140, 70,  20,  255}
#define KROSS_GRUNGE_YELLOW   (Kolor){150, 130, 40,  255}
#define KROSS_GRUNGE_PINK     (Kolor){140, 60,  90,  255}
#define KROSS_GRUNGE_CYAN     (Kolor){50,  100, 110, 255}
#define KROSS_GRUNGE_BROWN    (Kolor){80,  50,  30,  255}
// -------------------------------------
#define KROSS_PASTEL_WHITE    (Kolor){255, 252, 250, 255}
#define KROSS_PASTEL_BLACK    (Kolor){70,  70,  85,  255}
#define KROSS_PASTEL_GRAY     (Kolor){200, 205, 215, 255}
#define KROSS_PASTEL_RED      (Kolor){255, 170, 170, 255}
#define KROSS_PASTEL_BLUE     (Kolor){170, 215, 235, 255}
#define KROSS_PASTEL_GREEN    (Kolor){150, 240, 180, 255}
#define KROSS_PASTEL_PURPLE   (Kolor){210, 180, 250, 255}
#define KROSS_PASTEL_ORANGE   (Kolor){255, 210, 160, 255}
#define KROSS_PASTEL_YELLOW   (Kolor){250, 250, 170, 255}
#define KROSS_PASTEL_PINK     (Kolor){255, 185, 200, 255}
#define KROSS_PASTEL_CYAN     (Kolor){180, 240, 240, 255}
#define KROSS_PASTEL_BROWN    (Kolor){200, 180, 160, 255}
// -------------------------------------
#define KROSS_SWAP(T, kr_a, kr_b) do { T _kross_tmp_t = kr_a; kr_a = kr_b; kr_b = _kross_tmp_t; } while (0)
#define KROSS_MIN(kre_a, kre_b) ((kre_a) < (kre_b)) ? (kre_a) : (kre_b)
#define KROSS_MAX(kre_a, kre_b) ((kre_a) > (kre_b)) ? (kre_a) : (kre_b)
#define KROSS_PI 3.141592653589793238462643383279502
// -------------------------------------
typedef struct Kolor  { uint8_t r, g, b, a;                              } Kolor;
typedef struct Kanvas { Kolor* pixels; uint32_t w, h; float x, y;        } Kanvas;
typedef struct Vek2   { float x, y;                                      } Vek2;
typedef struct Vek3   { float x, y, z;                                   } Vek3;
typedef struct Kamera { Vek2 target, target_dst; float zoom, smoothness; } Kamera;
typedef struct Rekt   { float x, y; size_t w, h;                         } Rekt;
// -------------------------------------
typedef enum KNoiseType  { KROSS_NOISE_VALUE, KROSS_NOISE_PERLIN                          } KNoiseType;
typedef enum KInterpType { KROSS_INTERP_NNI,  KROSS_INTERP_BILINEAR, KROSS_INTERP_BICUBIC } KInterpType;
typedef enum KInput {
  // --------------
  // Yes, I sat here and typed out every single one of these keycodes.
  // Do you know how boring it is to assign numbers to the alphabet?
  // It is the programming equivalent of doing lines in detention.
  // "I will not make a custom engine... I will not make a custom engine..."
  // --------------
  KROSS_INPUT_A            = 65,
  KROSS_INPUT_B            = 66,
  KROSS_INPUT_C            = 67,
  KROSS_INPUT_D            = 68,
  KROSS_INPUT_E            = 69,
  KROSS_INPUT_F            = 70,
  KROSS_INPUT_G            = 71,
  KROSS_INPUT_H            = 72,
  KROSS_INPUT_I            = 73,
  KROSS_INPUT_J            = 74,
  KROSS_INPUT_K            = 75,
  KROSS_INPUT_L            = 76,
  KROSS_INPUT_M            = 77,
  KROSS_INPUT_N            = 78,
  KROSS_INPUT_O            = 79,
  KROSS_INPUT_P            = 80,
  KROSS_INPUT_Q            = 81,
  KROSS_INPUT_R            = 82,
  KROSS_INPUT_S            = 83,
  KROSS_INPUT_T            = 84,
  KROSS_INPUT_U            = 85,
  KROSS_INPUT_V            = 86,
  KROSS_INPUT_W            = 87,
  KROSS_INPUT_X            = 88,
  KROSS_INPUT_Y            = 89,
  KROSS_INPUT_Z            = 90,
  KROSS_INPUT_0            = 48,
  KROSS_INPUT_1            = 49,
  KROSS_INPUT_2            = 50,
  KROSS_INPUT_3            = 51,
  KROSS_INPUT_4            = 52,
  KROSS_INPUT_5            = 53,
  KROSS_INPUT_6            = 54,
  KROSS_INPUT_7            = 55,
  KROSS_INPUT_8            = 56,
  KROSS_INPUT_9            = 57,
  KROSS_INPUT_SPACE        = 32,
  KROSS_INPUT_ENTER        = 257,
  KROSS_INPUT_ESCAPE       = 256,
  KROSS_INPUT_BACKSPACE    = 259,
  KROSS_INPUT_TAB          = 258,
  KROSS_INPUT_CAPS_LOCK    = 280,
  KROSS_INPUT_DELETE       = 261,
  KROSS_INPUT_INSERT       = 260,
  KROSS_INPUT_PAGE_UP      = 266,
  KROSS_INPUT_PAGE_DOWN    = 267,
  KROSS_INPUT_HOME         = 268,
  KROSS_INPUT_END          = 269,
  KROSS_INPUT_RIGHT        = 262,
  KROSS_INPUT_LEFT         = 263,
  KROSS_INPUT_DOWN         = 264,
  KROSS_INPUT_UP           = 265,
  KROSS_INPUT_LSHIFT       = 340,
  KROSS_INPUT_LCTRL        = 341,
  KROSS_INPUT_LALT         = 342,
  KROSS_INPUT_LSUPER       = 343,
  KROSS_INPUT_RSHIFT       = 344,
  KROSS_INPUT_RCTRL        = 345,
  KROSS_INPUT_RALT         = 346,
  KROSS_INPUT_RSUPER       = 347,
  KROSS_INPUT_F1           = 290,
  KROSS_INPUT_F2           = 291,
  KROSS_INPUT_F3           = 292,
  KROSS_INPUT_F4           = 293,
  KROSS_INPUT_F5           = 294,
  KROSS_INPUT_F6           = 295,
  KROSS_INPUT_F7           = 296,
  KROSS_INPUT_F8           = 297,
  KROSS_INPUT_F9           = 298,
  KROSS_INPUT_F10          = 299,
  KROSS_INPUT_F11          = 300,
  KROSS_INPUT_F12          = 301,
  KROSS_INPUT_GRAVE        = 96,
  KROSS_INPUT_MINUS        = 45,
  KROSS_INPUT_EQUAL        = 61,
  KROSS_INPUT_LBRACKET     = 91,
  KROSS_INPUT_RBRACKET     = 93,
  KROSS_INPUT_BACKSLASH    = 92,
  KROSS_INPUT_SEMICOLON    = 59,
  KROSS_INPUT_APOSTROPHE   = 39,
  KROSS_INPUT_COMMA        = 44,
  KROSS_INPUT_PERIOD       = 46,
  KROSS_INPUT_SLASH        = 47,
  KROSS_INPUT_MOUSE_1      = 0,
  KROSS_INPUT_MOUSE_2      = 1,
  KROSS_INPUT_MOUSE_3      = 2,
  KROSS_INPUT_MOUSE_4      = 3,
  KROSS_INPUT_MOUSE_5      = 4,
  KROSS_INPUT_MOUSE_6      = 5,
  KROSS_INPUT_MOUSE_7      = 6,
  KROSS_INPUT_MOUSE_8      = 7,
  KROSS_INPUT_MOUSE_LEFT   = 0,
  KROSS_INPUT_MOUSE_RIGHT  = 1,
  KROSS_INPUT_MOUSE_MIDDLE = 2
} KInput;
// -------------------------------------
void    kross_window_init(Kanvas* kv, const char* title);
void    kross_window_free(void);
bool    kross_window_should_close(void);
void    kross_target_fps(size_t fps);
float   kross_delta_time(void);
// -------------------------------------
bool    kross_input_down(KInput input);
bool    kross_input_once(KInput input);
bool    kross_input_up(KInput input);
Vek2    kross_input_mouse_pos(void);
// -------------------------------------
Kanvas* kross_kanvas_init(size_t width, size_t height);
Kanvas* kross_kanvas_load(const char* path);
void    kross_kanvas_start(Kanvas* kv);
void    kross_kanvas_stop(Kanvas* kv);
void    kross_kanvas_free(Kanvas* kv);
void    kross_kanvas_fill(Kanvas* kv, Kolor kolor);
void    kross_kanvas_fill_horz(Kanvas* kv, Kolor kl_left, Kolor kl_right);
void    kross_kanvas_fill_vert(Kanvas* kv, Kolor kl_top,  Kolor kl_bot);
Kanvas* kross_kanvas_copy(Kanvas* kv);
Kanvas* kross_kanvas_scale(Kanvas* kv, float scale, KInterpType interp);
Kanvas* kross_kanvas_rotate(Kanvas* kv, float angle_in_degrees, KInterpType interp);
Vek2    kross_kanvas_nrm(Kanvas* kv);
void    kross_kanvas_blit(Kanvas* kv_main, Kanvas* kv_sub);
void    kross_kanvas_blitr(Kanvas* kv_main, Rekt start, Rekt end, Kanvas* kv_sub);
void    kross_kanvas_blur(Kanvas* kv, size_t radius);
void    kross_kanvas_vignette(Kanvas* kv, size_t radius);
void    kross_kanvas_grayscale(Kanvas* kv);
void    kross_kanvas_invert(Kanvas* kv);
void    kross_kanvas_pixel(Kanvas* kv, int x, int y, Kolor kolor);
void    kross_kanvas_line(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, Kolor kolor);
void    kross_kanvas_linev(Kanvas* kv, Vek2 pos0, Vek2 pos1, size_t thicc, Kolor kolor);
void    kross_kanvas_line_arrow(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, size_t head_len, float head_angle, Kolor kolor);
void    kross_kanvas_line_arrowv(Kanvas* kv, Vek2 v0, Vek2 v1, size_t thicc, size_t head_len, float head_angle, Kolor kolor);
void    kross_kanvas_line_bezier_quad(Kanvas* kv, Vek2 p0, Vek2 cp, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor);
void    kross_kanvas_line_bezier_cube(Kanvas* kv, Vek2 p0, Vek2 cp0, Vek2 cp1, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor);
void    kross_kanvas_rect(Kanvas* kv, int x, int y, size_t width, size_t height, Kolor kolor);
void    kross_kanvas_rectv(Kanvas* kv, Vek2 pos, Vek2 size, Kolor kolor);
void    kross_kanvas_rectr(Kanvas* kv, Rekt rect, Kolor kolor);
void    kross_kanvas_rect_stroke(Kanvas* kv, int x, int y, size_t width, size_t height, size_t thicc, Kolor kolor);
void    kross_kanvas_rect_strokev(Kanvas* kv, Vek2 pos, Vek2 size, size_t thicc, Kolor kolor);
void    kross_kanvas_rect_stroker(Kanvas* kv, Rekt rect, size_t thicc, Kolor kolor);
void    kross_kanvas_circle(Kanvas* kv, int cx, int cy, size_t r, Kolor kolor);
void    kross_kanvas_circlev(Kanvas* kv, Vek2 center, size_t r, Kolor kolor);
void    kross_kanvas_circle_stroke(Kanvas* kv, int cx, int cy, size_t r, size_t thicc, Kolor kolor);
void    kross_kanvas_circle_strokev(Kanvas* kv, Vek2 center, size_t r, size_t thicc, Kolor kolor);
void    kross_kanvas_triangle(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kolor);
void    kross_kanvas_triangle_stroke(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, size_t thicc, Kolor kolor);
void    kross_kanvas_triangle_tricolor(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kl0, Kolor kl1, Kolor kl2);
void    kross_kanvas_grid(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, size_t thicc, Kolor kolor);
void    kross_kanvas_gridv(Kanvas* kv, Vek2 start, Vek2 colrow, size_t gap, size_t thicc, Kolor kolor);
void    kross_kanvas_board(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, Kolor kl0, Kolor kl1);
void    kross_kanvas_boardv(Kanvas* kv, Vek2 start, Vek2 colrow, size_t gap, Kolor kl0, Kolor kl1);
// -------------------------------------
Kamera* kross_kamera_init(Vek2 target, Vek2 target_dst, float zoom, float smoothness);
void    kross_kamera_free(Kamera* kr);
void    kross_kamera_zoom(Kamera* kr, float t);
void    kross_kamera_line(Kanvas* kv, Kamera* kr, int x0, int y0, int x1, int y1, size_t thicc, Kolor kolor);
void    kross_kamera_rect(Kanvas* kv, Kamera* kr, int x, int y, size_t width, size_t height, Kolor kolor);
void    kross_kamera_rectv(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 size, Kolor kolor);
void    kross_kamera_rectr(Kanvas* kv, Kamera* kr, Rekt rekt, Kolor kolor);
void    kross_kamera_rect_stroke(Kanvas* kv, Kamera* kr, int x, int y, size_t width, size_t height, size_t thicc, Kolor kolor);
void    kross_kamera_rect_strokev(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 size, size_t thicc, Kolor kolor);
void    kross_kamera_rect_stroker(Kanvas* kv, Kamera* kr, Rekt rekt, size_t thicc, Kolor kolor);
void    kross_kamera_circle(Kanvas* kv, Kamera* kr, int cx, int cy, size_t r, Kolor kolor);
void    kross_kamera_circlev(Kanvas* kv, Kamera* kr, Vek2 center, size_t r, Kolor kolor);
void    kross_kamera_circle_stroke(Kanvas* kv, Kamera* kr, int cx, int cy, size_t r, size_t thicc, Kolor kolor);
void    kross_kamera_triangle(Kanvas* kv, Kamera* kr, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kolor);
void    kross_kamera_triangle_tricolor(Kanvas* kv, Kamera* kr, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kl0, Kolor kl1, Kolor kl2);
void    kross_kamera_triangle_stroke(Kanvas* kv, Kamera* kr, Vek2 v0, Vek2 v1, Vek2 v2, size_t thicc, Kolor kolor);
void    kross_kamera_grid(Kanvas* kv, Kamera* kr, int x, int y, size_t cols, size_t rows, size_t gap, size_t thicc, Kolor kolor);
void    kross_kamera_gridv(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 colrow, size_t gap, size_t thicc, Kolor kolor);
void    kross_kamera_board(Kanvas* kv, Kamera* kr, int x, int y, size_t cols, size_t rows, size_t gap, Kolor kl0, Kolor kl1);
void    kross_kamera_boardv(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 colrow, size_t gap, Kolor kl0, Kolor kl1);
// -------------------------------------
Kolor   kross_kolor_lerp(Kolor start, Kolor end, float t);
Kolor   kross_kolor_cerp(Kolor kl0, Kolor kl1, Kolor kl2, Kolor kl3, float t);
Kolor   kross_kolor_blend(Kolor kl0, Kolor kl1);
Kolor   kross_kolor_scale(Kolor kolor, float scale);
Kolor   kross_kolor_invert(Kolor kolor);
Kolor   kross_kolor_grayscale(Kolor kolor);
Kolor   kross_kolor_get(Kanvas* kv, int x, int y);
bool    kross_kolor_compare_rgb(Kolor kl0, Kolor kl1);
bool    kross_kolor_compare_rgba(Kolor kl0, Kolor kl1);
Kolor   kross_kolor_from_hsv(float h, float s, float v);
Kolor   kross_kolor_from_hex(uint32_t hex);
Kolor   kross_kolor_from_cmyk(float c, float m, float y, float k);
// -------------------------------------
// --------------
// "Why PPM and TGA?" I hear you ask. "Why not PNG, you absolute Neanderthal?"
// Because PNG uses DEFLATE compression, and I would rather eat glass than write
// A custom zlib compression algorithm in pure C just to save a screenshot.
// PPM is literally just plain text: "P3, width, height, max_color, and raw RGB."
// If you open a PPM in a text editor, you can literally read the pixels.
// Its horribly bloated, but hey, it compiles in 5 lines of code.
void    kross_file_ppm_write(Kanvas* kv, const char* path);
Kanvas* kross_file_ppm_read(const char* path);
void    kross_file_tga_write(Kanvas* kv, const char* path);
Kanvas* kross_file_tga_read(const char* path);
// --------------
// -------------------------------------
Vek2    kross_math_vek2_zero(void);
Vek2    kross_math_vek2_one(void);
Vek2    kross_math_vek2_add(Vek2 v0, Vek2 v1);
Vek2    kross_math_vek2_addval(Vek2 v0, float value);
Vek2    kross_math_vek2_sub(Vek2 v0, Vek2 v1);
Vek2    kross_math_vek2_subval(Vek2 v0, float value);
float   kross_math_vek2_dot(Vek2 v0, Vek2 v1);
float   kross_math_vek2_cross(Vek2 v0, Vek2 v1);
float   kross_math_vek2_len(Vek2 v0);
Vek2    kross_math_vek2_min(Vek2 v0, Vek2 v1);
Vek2    kross_math_vek2_max(Vek2 v0, Vek2 v1);
Vek2    kross_math_vek2_nrm(Vek2 v0);
Vek2    kross_math_vek2_scale(Vek2 v0, float scalar);
Vek2    kross_math_vek2_rotate(Vek2 v0, Vek2 center, float angle);
Vek2    kross_math_vek2_lerp(Vek2 v0, Vek2 v1, float t);
Vek2    kross_math_vek2_kamera(Kamera* kr, Vek2 world);
Vek2    kross_math_vek2_screen2norm(Vek2 screen, Vek2 kv);
Vek2    kross_math_vek2_normal2screen(Vek2 normal, Vek2 kv);
Vek2    kross_math_vek2_cartesian2screen(Vek2 cartesian, Vek2 kv, float scale);
Vek2    kross_math_vek2_screen2cartesian(Vek2 screen, Vek2 kv, float scale);
Vek2    kross_math_vek2_screen2uv(Vek2 screen, Vek2 kv);
Vek2    kross_math_vek2_uv2screen(Vek2 uv, Vek2 kv);
Vek2    kross_math_bezier_quad(Vek2 p0, Vek2 cp, Vek2 p1, float t);
Vek2    kross_math_bezier_cube(Vek2 p0, Vek2 cp0, Vek2 cp1, Vek2 p1, float t);
// -------------------------------------
// --------------
// Let me be completely honest with you, this section is never used once in the library.
// Originally I wanted Kross to be a 2D and 3D software rasterizer,
// Then I realized that writing 3D from scratch means dealing with matrix projections,
// Clip spaces and depth buffers, things my tiny brain was not prepared for.
// So instead of deleting everything, I left the useless 3D vector math here.
// Its a tombstone for my dead dreams.
// (Who said Shakespeare died?).
Vek3    kross_math_vek3_zero(void);
Vek3    kross_math_vek3_one(void);
Vek3    kross_math_vek3_add(Vek3 v0, Vek3 v1);
Vek3    kross_math_vek3_addval(Vek3 v0, float value);
Vek3    kross_math_vek3_sub(Vek3 v0, Vek3 v1);
Vek3    kross_math_vek3_subval(Vek3 v0, float value);
Vek3    kross_math_vek3_scale(Vek3 v0, float scalar);
Vek3    kross_math_vek3_cross(Vek3 v0, Vek3 v1);
Vek3    kross_math_vek3_lerp(Vek3 v0, Vek3 v1, float t);
float   kross_math_vek3_dot(Vek3 v0, Vek3 v1);
float   kross_math_vek3_len(Vek3 v0);
Vek3    kross_math_vek3_min(Vek3 v0, Vek3 v1);
Vek3    kross_math_vek3_max(Vek3 v0, Vek3 v1);
Vek3    kross_math_vek3_nrm(Vek3 v0);
Vek3    kross_math_vek3_rotate_x(Vek3 v0, float angle);
Vek3    kross_math_vek3_rotate_y(Vek3 v0, float angle);
Vek3    kross_math_vek3_translate_x(Vek3 v0, float dx);
Vek3    kross_math_vek3_translate_y(Vek3 v0, float dy);
Vek3    kross_math_vek3_translate_z(Vek3 v0, float dz);
Vek2    kross_math_vek3_project(Vek3 v0);
float   kross_math_lerp(float start, float end, float t);
float   kross_math_cerp(float x0, float x1, float x2, float x3, float t);
// --------------
// -------------------------------------
float   kross_math_noise_2d(float x, float y, KNoiseType type);
float   kross_math_noise_2d_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type);
float   kross_math_noise_3d(float x, float y, float z, KNoiseType type);
float   kross_math_noise_3d_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type);
// -------------------------------------
// --------------
float   kross_math_cv_deg2rad(float angle_in_degrees);
float   kross_math_cv_rad2deg(float angle_in_radians);
// Humans like to think in degrees (0 to 360). 
// The C math library (<math.h>), however, lives in a pretentious world of Radians (0 to 2*PI).
// If you pass "90" into cos(), it will not give you 0. It will give you a garbage decimal.
// Use these functions to translate between "human brain" and "C math library."
// --------------
int     kross_math_clamp(int value, int min, int max);
float   kross_math_clampf(float value, float min, float max);
double  kross_math_clampd(double value, double min, double max);
bool    kross_math_hit_rect_rect(int rect0x, int rect0y, size_t rect0w, size_t rect0h, int rect1x, int rect1y, size_t rect1w, size_t rect1h);
bool    kross_math_hit_rect_rectv(Vek2 rect0, Vek2 rect0_size, Vek2 rect1, Vek2 rect1_size);
bool    kross_math_hit_rect_rectr(Rekt rekt0, Rekt rekt1);
bool    kross_math_hit_rect_circle(int rectx, int recty, size_t rectw, size_t recth, int cx, int cy, size_t r);
bool    kross_math_hit_rect_circlev(Vek2 rect, Vek2 rect_size, Vek2 center, size_t r);
bool    kross_math_hit_rect_circler(Rekt rekt, Vek2 center, size_t r);
// -------------------------------------
float   kross_math_ease_in_quad(float t);
float   kross_math_ease_out_quad(float t);
float   kross_math_ease_in_out_quad(float t);
float   kross_math_ease_in_quint(float t);
float   kross_math_ease_out_quint(float t);
float   kross_math_ease_in_out_quint(float t);
float   kross_math_ease_in_elastic(float t);
float   kross_math_ease_out_elastic(float t);
float   kross_math_ease_in_out_elastic(float t);
float   kross_math_ease_in_cubic(float t);
float   kross_math_ease_out_cubic(float t);
float   kross_math_ease_in_out_cubic(float t);
float   kross_math_ease_in_sine(float t);
float   kross_math_ease_out_sine(float t);
float   kross_math_ease_in_out_sine(float t);
float   kross_math_ease_in_expo(float t);
float   kross_math_ease_out_expo(float t);
float   kross_math_ease_in_out_expo(float t);
float   kross_math_ease_in_bounce(float t);
float   kross_math_ease_out_bounce(float t);
float   kross_math_ease_in_out_bounce(float t);
// -------------------------------------
#ifdef __cplusplus
}
#endif
#endif // KROSS_H
// -------------------------------------
#ifdef KROSS_STRIP_PREFIX
// -------------------------------------
#define KLEAN_WHITE                   KROSS_KLEAN_WHITE
#define KLEAN_BLACK                   KROSS_KLEAN_BLACK
#define KLEAN_GRAY                    KROSS_KLEAN_GRAY
#define KLEAN_RED                     KROSS_KLEAN_RED
#define KLEAN_BLUE                    KROSS_KLEAN_BLUE
#define KLEAN_GREEN                   KROSS_KLEAN_GREEN
#define KLEAN_PURPLE                  KROSS_KLEAN_PURPLE
#define KLEAN_ORANGE                  KROSS_KLEAN_ORANGE
#define KLEAN_YELLOW                  KROSS_KLEAN_YELLOW
#define KLEAN_PINK                    KROSS_KLEAN_PINK
#define KLEAN_CYAN                    KROSS_KLEAN_CYAN
#define KLEAN_BROWN                   KROSS_KLEAN_BROWN
// -------------------------------------
#define KCYBER_WHITE                  KROSS_CYBER_WHITE
#define KCYBER_BLACK                  KROSS_CYBER_BLACK
#define KCYBER_GRAY                   KROSS_CYBER_GRAY
#define KCYBER_RED                    KROSS_CYBER_RED
#define KCYBER_BLUE                   KROSS_CYBER_BLUE
#define KCYBER_GREEN                  KROSS_CYBER_GREEN
#define KCYBER_PURPLE                 KROSS_CYBER_PURPLE
#define KCYBER_ORANGE                 KROSS_CYBER_ORANGE
#define KCYBER_YELLOW                 KROSS_CYBER_YELLOW
#define KCYBER_PINK                   KROSS_CYBER_PINK
#define KCYBER_CYAN                   KROSS_CYBER_CYAN
#define KCYBER_BROWN                  KROSS_CYBER_BROWN
// -------------------------------------
#define KGRUNGE_WHITE                 KROSS_GRUNGE_WHITE
#define KGRUNGE_BLACK                 KROSS_GRUNGE_BLACK
#define KGRUNGE_GRAY                  KROSS_GRUNGE_GRAY
#define KGRUNGE_RED                   KROSS_GRUNGE_RED
#define KGRUNGE_BLUE                  KROSS_GRUNGE_BLUE
#define KGRUNGE_GREEN                 KROSS_GRUNGE_GREEN
#define KGRUNGE_PURPLE                KROSS_GRUNGE_PURPLE
#define KGRUNGE_ORANGE                KROSS_GRUNGE_ORANGE
#define KGRUNGE_YELLOW                KROSS_GRUNGE_YELLOW
#define KGRUNGE_PINK                  KROSS_GRUNGE_PINK
#define KGRUNGE_CYAN                  KROSS_GRUNGE_CYAN
#define KGRUNGE_BROWN                 KROSS_GRUNGE_BROWN
// -------------------------------------
#define KPASTEL_WHITE                 KROSS_PASTEL_WHITE
#define KPASTEL_BLACK                 KROSS_PASTEL_BLACK
#define KPASTEL_GRAY                  KROSS_PASTEL_GRAY
#define KPASTEL_RED                   KROSS_PASTEL_RED
#define KPASTEL_BLUE                  KROSS_PASTEL_BLUE
#define KPASTEL_GREEN                 KROSS_PASTEL_GREEN
#define KPASTEL_PURPLE                KROSS_PASTEL_PURPLE
#define KPASTEL_ORANGE                KROSS_PASTEL_ORANGE
#define KPASTEL_YELLOW                KROSS_PASTEL_YELLOW
#define KPASTEL_PINK                  KROSS_PASTEL_PINK
#define KPASTEL_CYAN                  KROSS_PASTEL_CYAN
#define KPASTEL_BROWN                 KROSS_PASTEL_BROWN
// -------------------------------------
#define KSWAP                         KROSS_SWAP
#define KMIN                          KROSS_MIN
#define KMAX                          KROSS_MAX
#define KPI                           KROSS_PI
// -------------------------------------
#define kw_init                       kross_window_init
#define kw_free                       kross_window_free
#define kw_should_close               kross_window_should_close
#define kw_target_fps                 kross_target_fps
#define kw_delta                      kross_delta_time
// -------------------------------------
#define kv_init                       kross_kanvas_init
#define kv_start                      kross_kanvas_start
#define kv_stop                       kross_kanvas_stop
#define kv_free                       kross_kanvas_free
#define kv_fill                       kross_kanvas_fill
#define kv_fill_horz                  kross_kanvas_fill_horz
#define kv_fill_vert                  kross_kanvas_fill_vert
#define kv_copy                       kross_kanvas_copy
#define kv_scale                      kross_kanvas_scale
#define kv_rotate                     kross_kanvas_rotate
#define kv_load                       kross_kanvas_load
#define kv_blit                       kross_kanvas_blit
#define kv_blitr                      kross_kanvas_blitr
#define kv_blur                       kross_kanvas_blur
#define kv_vignette                   kross_kanvas_vignette
#define kv_grayscale                  kross_kanvas_grayscale
#define kv_kolor_get                  kross_kolor_get
#define kv_invert                     kross_kanvas_invert
#define kv_pixel                      kross_kanvas_pixel
#define kv_line                       kross_kanvas_line
#define kv_linev                      kross_kanvas_linev
#define kv_line_arrow                 kross_kanvas_line_arrow
#define kv_line_arrowv                kross_kanvas_line_arrowv
#define kv_line_bezier_quad           kross_kanvas_line_bezier_quad
#define kv_line_bezier_cube           kross_kanvas_line_bezier_cube
#define kv_rect                       kross_kanvas_rect
#define kv_rectv                      kross_kanvas_rectv
#define kv_rectr                      kross_kanvas_rectr
#define kv_rect_stroke                kross_kanvas_rect_stroke
#define kv_rect_strokev               kross_kanvas_rect_strokev
#define kv_rect_stroker               kross_kanvas_rect_stroker
#define kv_circle                     kross_kanvas_circle
#define kv_circlev                    kross_kanvas_circlev
#define kv_circle_stroke              kross_kanvas_circle_stroke
#define kv_circle_strokev             kross_kanvas_circle_strokev
#define kv_triangle                   kross_kanvas_triangle
#define kv_triangle_tricolor          kross_kanvas_triangle_tricolor
#define kv_triangle_stroke            kross_kanvas_triangle_stroke
#define kv_grid                       kross_kanvas_grid
#define kv_gridv                      kross_kanvas_gridv
#define kv_board                      kross_kanvas_board
#define kv_boardv                     kross_kanvas_boardv
// -------------------------------------
#define kr_init                       kross_kamera_init
#define kr_free                       kross_kamera_free
#define kr_line                       kross_kamera_line
#define kr_linev                      kross_kamera_linev
#define kr_rect                       kross_kamera_rect
#define kr_rectv                      kross_kamera_rectv
#define kr_rectr                      kross_kamera_rectr
#define kr_rect_stroke                kross_kamera_rect_stroke
#define kr_rect_strokev               kross_kamera_rect_strokev
#define kr_rect_stroker               kross_kamera_rect_stroker
#define kr_circle                     kross_kamera_circle
#define kr_circlev                    kross_kamera_circlev
#define kr_circle_stroke              kross_kamera_circle_stroke
#define kr_circle_strokev             kross_kamera_circle_strokev
#define kr_triangle                   kross_kamera_triangle
#define kr_triangle_stroke            kross_kamera_triangle_stroke
#define kr_triangle_tricolor          kross_kamera_triangle_tricolor
#define kr_grid                       kross_kamera_grid
#define kr_gridv                      kross_kamera_gridv
#define kr_board                      kross_kamera_board
#define kr_boardv                     kross_kamera_boardv
// -------------------------------------
#define kl_blend                      kross_kolor_blend
#define kl_scale                      kross_kolor_scale
#define kl_lerp                       kross_kolor_lerp
#define kl_cerp                       kross_kolor_cerp
#define kl_invert                     kross_kolor_invert
#define kl_grayscale                  kross_kolor_grayscale
#define kl_compare_rgb                kross_kolor_compare_rgb
#define kl_compare_rgba               kross_kolor_compare_rgba
#define kl_from_hsv                   kross_kolor_from_hsv
#define kl_from_hsl                   kross_kolor_from_hsl
#define kl_from_cmyk                  kross_kolor_from_cmyk
#define kl_from_hex                   kross_kolor_from_hex
// -------------------------------------
#define kf_ppm_write                  kross_file_ppm_write
#define kf_ppm_read                   kross_file_ppm_read
#define kf_tga_write                  kross_file_tga_write
#define kf_tga_read                   kross_file_tga_read
// -------------------------------------
#define KI_A                          KROSS_INPUT_A
#define KI_B                          KROSS_INPUT_B
#define KI_C                          KROSS_INPUT_C
#define KI_D                          KROSS_INPUT_D
#define KI_E                          KROSS_INPUT_E
#define KI_F                          KROSS_INPUT_F
#define KI_G                          KROSS_INPUT_G
#define KI_H                          KROSS_INPUT_H
#define KI_I                          KROSS_INPUT_I
#define KI_J                          KROSS_INPUT_J
#define KI_K                          KROSS_INPUT_K
#define KI_L                          KROSS_INPUT_L
#define KI_M                          KROSS_INPUT_M
#define KI_N                          KROSS_INPUT_N
#define KI_O                          KROSS_INPUT_O
#define KI_P                          KROSS_INPUT_P
#define KI_Q                          KROSS_INPUT_Q
#define KI_R                          KROSS_INPUT_R
#define KI_S                          KROSS_INPUT_S
#define KI_T                          KROSS_INPUT_T
#define KI_U                          KROSS_INPUT_U
#define KI_V                          KROSS_INPUT_V
#define KI_W                          KROSS_INPUT_W
#define KI_X                          KROSS_INPUT_X
#define KI_Y                          KROSS_INPUT_Y
#define KI_Z                          KROSS_INPUT_Z
#define KI_0                          KROSS_INPUT_0
#define KI_1                          KROSS_INPUT_1
#define KI_2                          KROSS_INPUT_2
#define KI_3                          KROSS_INPUT_3
#define KI_4                          KROSS_INPUT_4
#define KI_5                          KROSS_INPUT_5
#define KI_6                          KROSS_INPUT_6
#define KI_7                          KROSS_INPUT_7
#define KI_8                          KROSS_INPUT_8
#define KI_9                          KROSS_INPUT_9
#define KI_SPACE                      KROSS_INPUT_SPACE
#define KI_ENTER                      KROSS_INPUT_ENTER
#define KI_ESCAPE                     KROSS_INPUT_ESCAPE
#define KI_BACKSPACE                  KROSS_INPUT_BACKSPACE
#define KI_TAB                        KROSS_INPUT_TAB
#define KI_CAPS_LOCK                  KROSS_INPUT_CAPS_LOCK
#define KI_DELETE                     KROSS_INPUT_DELETE
#define KI_INSERT                     KROSS_INPUT_INSERT
#define KI_PAGE_UP                    KROSS_INPUT_PAGE_UP
#define KI_PAGE_DOWN                  KROSS_INPUT_PAGE_DOWN
#define KI_HOME                       KROSS_INPUT_HOME
#define KI_END                        KROSS_INPUT_END
#define KI_RIGHT                      KROSS_INPUT_RIGHT
#define KI_LEFT                       KROSS_INPUT_LEFT
#define KI_DOWN                       KROSS_INPUT_DOWN
#define KI_UP                         KROSS_INPUT_UP
#define KI_LSHIFT                     KROSS_INPUT_LSHIFT
#define KI_LCTRL                      KROSS_INPUT_LCTRL
#define KI_LALT                       KROSS_INPUT_LALT
#define KI_LSUPER                     KROSS_INPUT_LSUPER
#define KI_RSHIFT                     KROSS_INPUT_RSHIFT
#define KI_RCTRL                      KROSS_INPUT_RCTRL
#define KI_RALT                       KROSS_INPUT_RALT
#define KI_RSUPER                     KROSS_INPUT_RSUPER
#define KI_F1                         KROSS_INPUT_F1
#define KI_F2                         KROSS_INPUT_F2
#define KI_F3                         KROSS_INPUT_F3
#define KI_F4                         KROSS_INPUT_F4
#define KI_F5                         KROSS_INPUT_F5
#define KI_F6                         KROSS_INPUT_F6
#define KI_F7                         KROSS_INPUT_F7
#define KI_F8                         KROSS_INPUT_F8
#define KI_F9                         KROSS_INPUT_F9
#define KI_F10                        KROSS_INPUT_F10
#define KI_F11                        KROSS_INPUT_F11
#define KI_F12                        KROSS_INPUT_F12
#define KI_GRAVE                      KROSS_INPUT_GRAVE
#define KI_MINUS                      KROSS_INPUT_MINUS
#define KI_EQUAL                      KROSS_INPUT_EQUAL
#define KI_LBRACKET                   KROSS_INPUT_LBRACKET
#define KI_RBRACKET                   KROSS_INPUT_RBRACKET
#define KI_BACKSLASH                  KROSS_INPUT_BACKSLASH
#define KI_SEMICOLON                  KROSS_INPUT_SEMICOLON
#define KI_APOSTROPHE                 KROSS_INPUT_APOSTROPHE
#define KI_COMMA                      KROSS_INPUT_COMMA
#define KI_PERIOD                     KROSS_INPUT_PERIOD
#define KI_SLASH                      KROSS_INPUT_SLASH
#define KI_MOUSE_1                    KROSS_INPUT_MOUSE_1
#define KI_MOUSE_2                    KROSS_INPUT_MOUSE_2
#define KI_MOUSE_3                    KROSS_INPUT_MOUSE_3
#define KI_MOUSE_4                    KROSS_INPUT_MOUSE_4
#define KI_MOUSE_5                    KROSS_INPUT_MOUSE_5
#define KI_MOUSE_6                    KROSS_INPUT_MOUSE_6
#define KI_MOUSE_7                    KROSS_INPUT_MOUSE_7
#define KI_MOUSE_8                    KROSS_INPUT_MOUSE_8
#define KI_MOUSE_LEFT                 KROSS_INPUT_MOUSE_LEFT
#define KI_MOUSE_RIGHT                KROSS_INPUT_MOUSE_RIGHT
#define KI_MOUSE_MIDDLE               KROSS_INPUT_MOUSE_MIDDLE
#define ki_down                       kross_input_down
#define ki_once                       kross_input_once
#define ki_up                         kross_input_up
#define ki_mouse_pos                  kross_input_mouse_pos
// -------------------------------------
#define km_vek2_add                   kross_math_vek2_add
#define km_vek2_addval                kross_math_vek2_addval
#define km_vek2_sub                   kross_math_vek2_sub
#define km_vek2_subval                kross_math_vek2_subval
#define km_vek2_scale                 kross_math_vek2_scale
#define km_vek2_rotate                kross_math_vek2_rotate
#define km_vek2_dot                   kross_math_vek2_dot
#define km_vek2_cross                 kross_math_vek2_cross
#define km_vek2_len                   kross_math_vek2_len
#define km_vek2_min                   kross_math_vek2_min
#define km_vek2_max                   kross_math_vek2_max
#define km_vek2_lerp                  kross_math_vek2_lerp
#define km_vek2_screen2norm           kross_math_vek2_screen2norm
#define km_vek2_normal2screen         kross_math_vek2_normal2screen
#define km_vek2_screen2cartesian      kross_math_vek2_screen2cartesian
#define km_vek2_screen2uv             kross_math_vek2_screen2uv
#define km_vek2_uv2screen             kross_math_vek2_uv2screen
#define km_vek2_cartesian2screen      kross_math_vek2_cartesian2screen
#define km_vek3_add                   kross_math_vek3_add
#define km_vek3_addval                kross_math_vek3_addval
#define km_vek3_sub                   kross_math_vek3_sub
#define km_vek3_subval                kross_math_vek3_subval
#define km_vek3_scale                 kross_math_vek3_scale
#define km_vek3_dot                   kross_math_vek3_dot
#define km_vek3_len                   kross_math_vek3_len
#define km_vek3_min                   kross_math_vek3_min
#define km_vek3_max                   kross_math_vek3_max
#define km_vek3_cross                 kross_math_vek3_cross
#define km_vek3_lerp                  kross_math_vek3_lerp
#define km_vek3_project               kross_math_vek3_project
#define km_vek3_translate_z           kross_math_vek3_translate_z
#define km_vek3_rotate_y              kross_math_vek3_rotate_y
#define km_vek3_rotate_x              kross_math_vek3_rotate_x
#define km_bezier_quad                kross_math_bezier_quad
#define km_bezier_cube                kross_math_bezier_cube
#define km_hit_rect_rect              kross_math_hit_rect_rect
#define km_hit_rect_rectv             kross_math_hit_rect_rectv
#define km_hit_rect_rectr             kross_math_hit_rect_rectr
#define km_hit_rect_circle            kross_math_hit_rect_circle
#define km_hit_rect_circlev           kross_math_hit_rect_circlev
#define km_hit_rect_circler           kross_math_hit_rect_circler
#define km_lerp                       kross_math_lerp
#define km_cerp                       kross_math_cerp
#define km_cv_deg2rad                 kross_math_cv_deg2rad
#define km_cv_rad2deg                 kross_math_cv_rad2deg
#define km_clamp                      kross_math_clamp
#define km_clampf                     kross_math_clampf
#define km_clampd                     kross_math_clampd
#define km_noise_2d                   kross_math_noise_2d
#define km_noise_2d_fbm               kross_math_noise_2d_fbm
#define km_noise_3d                   kross_math_noise_3d
#define km_noise_3d_fbm               kross_math_noise_3d_fbm
#define km_ease_in_quad               kross_math_ease_in_quad
#define km_ease_out_quad              kross_math_ease_out_quad
#define km_ease_in_out_quad           kross_math_ease_in_out_quad
#define km_ease_in_quint              kross_math_ease_in_quint
#define km_ease_out_quint             kross_math_ease_out_quint
#define km_ease_in_out_quint          kross_math_ease_in_out_quint
#define km_ease_in_elastic            kross_math_ease_in_elastic
#define km_ease_out_elastic           kross_math_ease_out_elastic
#define km_ease_in_out_elastic        kross_math_ease_in_out_elastic
#define km_ease_in_cubic              kross_math_ease_in_cubic
#define km_ease_out_cubic             kross_math_ease_out_cubic
#define km_ease_in_out_cubic          kross_math_ease_in_out_cubic
#define km_ease_in_sine               kross_math_ease_in_sine
#define km_ease_out_sine              kross_math_ease_out_sine
#define km_ease_in_out_sine           kross_math_ease_in_out_sine
#define km_ease_in_expo               kross_math_ease_in_expo
#define km_ease_out_expo              kross_math_ease_out_expo
#define km_ease_in_out_expo           kross_math_ease_in_out_expo
#define km_ease_in_bounce             kross_math_ease_in_bounce
#define km_ease_out_bounce            kross_math_ease_out_bounce
#define km_ease_in_out_bounce         kross_math_ease_in_out_bounce
// -------------------------------------
#endif // KROSS_STRIP_PREFIX
// -------------------------------------
#ifdef  KROSS_IMPLEMENTATION
#ifndef KROSS_IMPLEMENTATION_GUARD
#define KROSS_IMPLEMENTATION_GUARD
// -------------------------------------
Kanvas* kross_kanvas_init(size_t width, size_t height)
{
  Kanvas* k = malloc(sizeof(Kanvas));
  if (!k) return NULL;
  k->w = width;
  k->h = height;
  k->x = 0;
  k->y = 0;
  k->pixels = malloc(width*height*sizeof(Kolor));
  if (!k->pixels) { free(k); return NULL; }
  return k;
}
// -------------------------------------
Kanvas* kross_kanvas_load(const char* path)
{
  const char* dot = strrchr(path, '.');
  const char* extension = (dot && *(dot+1)) ? dot+1 : "";

  if (strcmp(extension, "ppm") == 0) return kross_file_ppm_read(path);
  if (strcmp(extension, "tga") == 0) return kross_file_tga_read(path);

  return NULL;
}
// -------------------------------------
void kross_kanvas_free(Kanvas* kv)
{
  if (kv->pixels) free(kv->pixels);
  if (kv)         free(kv);
}
// -------------------------------------
void kross_kanvas_pixel(Kanvas* kv, int x, int y, Kolor kolor)
{
  //--------------
  x = kross_math_clamp(x, 0, kv->w-1);
  y = kross_math_clamp(y, 0, kv->h-1);
  //--------------
  // This function does exactly what we explain above,
  // Under the hood, its just return kv->pixels[y*kv->w+x];
  Kolor kl = kross_kolor_get(kv, x, y);
  kv->pixels[y*kv->w+x] = kross_kolor_blend(kolor, kl);
  //--------------
}
// -------------------------------------
void kross_kanvas_invert(Kanvas* kv)
{
  //--------------
  // Bitwise XOR (^) is an easy way to impress cavemen like me.
  // I remember the first time I saw this was in a Tsoding video,
  // Watch Tsoding videos if you want to learn programming.
  // (Thank you Tsoding for the sponsor).
  //--------------
  // Anyway, how does this work? What is XOR?
  // XOR or eXclusive OR compares two bits,
  // it outputs 1 if the inputs are different, 0 if they are the same.
  //--------------
  // Wikipedia example:
  // 0 ^ 0 = 0
  // 1 ^ 1 = 0
  // 1 ^ 0 = 1
  // 0 ^ 1 = 1
  //--------------
  // Because of this, XORing any bit with 1 flips its value,
  // all the 0s become 1s and all the 1s become 0s.
  //--------------
  // Now lets show an actual example, with the color orange.
  // Red   = 255 (11111111 in binary)
  // Green = 165 (10100101 in binary)
  // Blue  =   0 (00000000 in binary)
  //--------------
  // Now, look what happens when we XOR each channel with 255:
  // (255 in binary is a solid wall of ones: 11111111).
  // (also we use 255 because thats the max value for an RGB channel).
  //
  //    RED CHANNEL:
  //    255:  1 1 1 1  1 1 1 1
  //  ^ 255:  1 1 1 1  1 1 1 1
  //  ------------------------
  //    New:  0 0 0 0  0 0 0 0  -> (Decimal: 0)
  //
  //    GREEN CHANNEL:
  //    165:  1 0 1 0  0 1 0 1
  //  ^ 255:  1 1 1 1  1 1 1 1
  //  ------------------------
  //    New:  0 1 0 1  1 0 1 0  -> (Decimal: 90)
  //
  //    BLUE CHANNEL:
  //    0  :  0 0 0 0  0 0 0 0
  //  ^ 255:  1 1 1 1  1 1 1 1
  //  ------------------------
  //    New:  1 1 1 1  1 1 1 1  -> (Decimal: 255)
  //
  // Our inverted color went from orange (255, 165, 0) to 
  // a sharp blue/cyan (0, 90, 255). 
  //--------------
  for (size_t i = 0; i < kv->w*kv->h; ++i)
  {
    kv->pixels[i].r ^= 255;
    kv->pixels[i].g ^= 255;
    kv->pixels[i].b ^= 255;
  }
  //--------------
}
// -------------------------------------
void kross_kanvas_fill(Kanvas* kv, Kolor kolor)
{
  //--------------
  // This is the simplest function in the library.
  // We want to paint the entire kanvas one solid color.
  //--------------
  // You might be wondering: "Wait, isnt the canvas 2D? 
  // Why arent we using an x and y loop here?"
  //--------------
  // In memory, a 2D image isnt actually a 2D grid, its just a massive 
  // 1D line of pixels laid out end-to-end (row 1, then row 2, etc).
  // When we dont care about specific X/Y coordinates and just want to 
  // hit every single pixel, a single 1D loop from 0 to width*height
  // is mathematically cleaner and slightly faster.
  //--------------
  for (size_t i = 0; i < kv->w*kv->h; ++i)
  {
    kv->pixels[i] = kolor;
  }
}
// -------------------------------------
void kross_kanvas_fill_horz(Kanvas* kv, Kolor kl_left, Kolor kl_right)
{
  //--------------
  // Now we actually care about coordinates (left half vs right half),
  // So we switch to a 2D nested loop. 
  //
  // Notice the order: the "y" loop (rows) is on the outside, 
  // And the "x" loops (columns) are on the inside. 
  // This is called "Row-Major Order" and it is EXACTLY how you 
  // Want to loop through images in C. 
  // 
  // Why? CPU Cache Locality. 
  // When the CPU grabs pixel(0,0) from RAM, it grabs the neighboring,
  // Pixels (1,0), (2,0), etc, at the same time and puts them in ultra-fast L1 cache.
  // By moving horizontally across the row, we read exactly from that cache.
  //--------------
  for (int y = 0; y < (int)kv->h; ++y)
  {
    for (int left_x = 0; left_x < (int)kv->w/2; ++left_x)
    {
      kross_kanvas_pixel(kv, left_x, y, kl_left);
    }

    for (int right_x = kv->w/2; right_x < (int)kv->w; ++right_x)
    {
      kross_kanvas_pixel(kv, right_x, y, kl_right);
    }
  }
}
// -------------------------------------
void kross_kanvas_fill_vert(Kanvas* kv, Kolor kl_bot, Kolor kl_top)
{ 
  //--------------
  // CHALLENGE
  //--------------
  // This code sucks performance wise (like most of my code).
  // Because it iterates column-first (x on the outer loop), it jumps across
  // Memory rows on every single pixel write, causing massive cache misses.
  //
  // I want you to rewrite this function so that it traverses the canvas row-by-row,
  // (horizontally), taking full advantage of CPU cache lines.
  //--------------
  for (int x = 0; x < (int)kv->w; ++x)
  {
    for (int top_y = 0; top_y < (int)kv->h/2; ++top_y)
    {
      kross_kanvas_pixel(kv, x, top_y, kl_top);
    }

    for (int bottom_y = kv->h/2; bottom_y < (int)kv->h; ++bottom_y)
    {
      kross_kanvas_pixel(kv, x, bottom_y, kl_bot);
    }
  }
}
// -------------------------------------
Kanvas* kross_kanvas_copy(Kanvas* kv)
{
  if (!kv || !kv->pixels) return NULL;
  Kanvas* tmp = kross_kanvas_init(kv->w, kv->h);

  for (int y = 0; y < (int)kv->h; ++y)
  {
    for (int x = 0; x < (int)kv->w; ++x)
    {
      tmp->pixels[y*kv->w+x] = kv->pixels[y*kv->w+x];
    }
  }

  return tmp;
}
// -------------------------------------
static Kanvas* kross_kanvas_scale_nni(Kanvas* kv, float scale)
{
  //--------------
  // NNI stands for Nearest Neighbor Interpolation.
  // If Bilinear Interpolation (the next function) is a smooth, blurry gradient,
  // NNI is crispy, blocky Minecraft pixel art.
  //--------------
  // Instead of doing complicated math to blend four pixels together, NNI just asks:
  // "If I map my new scaled coordinate back to the old original image, 
  // What is the single closest pixel I land on?"
  // Then it just steals that exact color. No blending, no fading.
  //--------------
  if (!kv || !kv->pixels || scale <= 0.0f) return NULL;
  Kanvas* scaled = kross_kanvas_init(kv->w*scale, kv->h*scale);
  if (!scaled) return NULL;
  if (scale == 1.0f) return scaled;
  //--------------
  // Just like we will do in Bilinear, we invert the scale once here.
  // Multiplying by 0.5 is faster for the CPU than dividing by 2.0 thousands of times.
  float scale_inv = 1.0f/scale;
  //--------------
  for (int y = 0; y < (int)scaled->h; ++y)
  {
    //--------------
    // The magic of Nearest Neighbor: casting a float to an int simply chops off 
    // the decimals (truncation). If `y * scale_inv` is 14.9, `src_y` just becomes 14.
    // We also make sure we dont accidentally ask for a pixel outside the image bounds.
    //--------------
    int src_y = (int)(y*scale_inv);
    if (src_y >= (int)kv->h) src_y = kv->h-1;
    //--------------
    // Pre-calculating the row offsets outside the X loop saves us from doing
    // a bunch of (y*width) multiplications inside the innermost loop.
    // Every little bit of performance counts, especially when this pea-brain is coding.
    //--------------
    int src_offset_y = src_y*kv->w;
    int dst_offset_y = y*scaled->w;
    //--------------
    for (int x = 0; x < (int)scaled->w; ++x)
    {
      //--------------
      // Find the nearest original X coordinate...
      int src_x = (int)(x*scale_inv);
      if (src_x >= (int)kv->w) src_x = kv->w-1;
      // ...and blindly copy it over. Fast, cheap, and blocky.
      scaled->pixels[dst_offset_y+x] = kv->pixels[src_offset_y+src_x];
      //--------------
    }
  }

  return scaled;
}
// -------------------------------------
static Kanvas* kross_kanvas_scale_bilinear(Kanvas* kv, float scale)
{
  //--------------
  // If you go on Youtube right now and search "Bilinear Interpolation",
  // Quite a few explanation videos will come up, and they will all say:
  // "Bilinear interpolation is easy, first we find 4 pixels, 
  // then we horizontally lerp from left to right,
  // and finally we lerp vertically from top to bottom and thats it",
  //--------------
  // Its like someone telling you rocket science is easy, grab a giant metal tube,
  // throw some fire inside and point it at the sky.
  // Or like saying quantum physics is easy, take a ball, put some atoms in it, make it go boom.
  // And thats how the atomic bomb was made.
  //--------------
  // They completely skip over the absolute nightmare that is the math.
  // "Just lerp it, bro!" 
  // Okay, but which 4 pixels?
  // When you are at the bottom-right edge of the texture,
  // Where is the "right" or "bottom" pixel?
  // It doesnt exist. You are looking into a void of unallocated memory.
  //--------------
  // And lets talk about the fractions.
  // To "just lerp," you need a weight (t) between 0.0 and 1.0.
  // Getting that weight requires mapping the pixel coordinate
  // of the new kanvas into a continuous floating-point coordinate on the old kanvas,
  // Subtracting the floor to get the fractional part, and keeping track of it for both axes.
  // And what even is lerp? What even is life? So many questions.
  //--------------
  // Firstly, lerp is a function which tells us how far along we are between two points.
  // Lerp is short for Linear Interpolation.
  // Secondly, finding t and those 4 pixels is not that hard, we will prove this below.
  // And from my own experience, Youtube is the last place to go to for learning graphics programming.
  // (Unless the video is from Tsoding, again, thank you Tsoding for the sponsor).
  //--------------
  if (!kv || !kv->pixels) return NULL;
  Kanvas* scaled = kross_kanvas_init(kv->w*scale, kv->h*scale);
  if (!scaled || scale <= 0.0f) return NULL;
  if (scale == 1.0f) return scaled;
  //--------------
  // We cache the inverted scale so we multiply instead of dividing.
  // Heres what I mean:
  // int src_x = x/scale; becomes int src_x = x*scale_inv;
  // Multiplication is a lot cheaper than division,
  // So we improve performance by only dividing once instead of thousands of times.
  //--------------
  float scale_inv = 1.0f/scale;
  //--------------
  // Firstly, we loop over the new scaled buffer,
  // The old buffer is used to bring pixels over.
  // Remember whenever we loop, y/row always first, gotta hold the caches hand.
  //--------------
  for (int y = 0; y < (int)scaled->h; ++y)
  {
    for (int x = 0; x < (int)scaled->w; ++x)
    {
      //--------------
      float src_x = x*scale_inv;
      float src_y = y*scale_inv;
      //--------------
      // Heres finding the pixels, this is what I was ranting about,
      // src_x may be a fractional number, something like 14.6,
      // x0 (top-left) would be 14, x1 is top-left + 1pixel, which becomes top-right,
      // Also we make sure that everything is inside the buffer, so we dont segfault.
      //--------------
      int x0 = floorf(src_x);
      int y0 = floorf(src_y);
      int x1 = (x0+1 < (int)kv->w)  ? x0+1 : x0;
      int y1 = (y0+1 < (int)kv->h)  ? y0+1 : y0;
      //--------------
      // Heres getting the weight for our lerps, now it actually seems simple,
      // We get x: 14.6 and remove x0:14 from it,
      // We are left with 0.6, so we are 60% of the way inside this pixel.
      // Heres a better visual representation:
      //
      // (x0: 14, y0)       (u: 0.6)       (x1:15, y0)
      //    *_______________________________*
      //    |                               |
      //    |                               |
      //    |                               |
      //    |                               |
      //    |                               |
      //    *_______________________________*
      // (x0, y1)                          (x1, y1)
      //
      // What we just did, Bilinear Interpolation, is used for many, many different things,
      // For example, we now have free knowledge of Value Noise, of pixel rotation,
      // Of u/v coordinates, all things which come up very frequently in graphics.
      //--------------
      float u = src_x-x0;
      float v = src_y-y0;
      //--------------
      // Actual Bilinear Interpolation uses u/v raw, but who cares?
      // We adjust u/v however we want, apply smoothstep,
      // Or in this case, Ken Perlins quintic function, because why not?
      //--------------
      float fade_u = kross_math_ease_in_out_quint(u);
      float fade_v = kross_math_ease_in_out_quint(v);
      //--------------
      // Does this make more sense now?
      // Its just the rectangle with the classic y*width+x formula.
      //--------------
      Kolor top_left      = kv->pixels[y0*kv->w+x0];
      Kolor top_right     = kv->pixels[y0*kv->w+x1];
      Kolor bottom_left   = kv->pixels[y1*kv->w+x0];
      Kolor bottom_right  = kv->pixels[y1*kv->w+x1];
      //--------------
      // Heres actually lerping from left to right.
      Kolor row_top       = kross_kolor_lerp(top_left, top_right, fade_u);
      Kolor row_bottom    = kross_kolor_lerp(bottom_left, bottom_right, fade_u);
      // Then from top to bottom.
      Kolor final_kolor   = kross_kolor_lerp(row_top, row_bottom, fade_v);
      // Then writing the kolor to the buffer.
      kross_kanvas_pixel(scaled, x, y, final_kolor);
      //--------------
    }
  }

  return scaled;
}
// -------------------------------------
static Kanvas* kross_kanvas_scale_bicubic(Kanvas* kv, float scale)
{
  //--------------
  // Here we go with Bicubic Interpolation,
  // This one is way more painful to implement,
  //--------------
  // Remember how Bilinear was looking at a 2x2 grid of 4 pixels? 
  // Bicubic looks at a 4x4 grid of sixteen pixels. 
  // Why? Because it doesnt just want to blend the colors,
  // It wants to analyze the *slope* of how the colors are changing,
  // So it can draw a smooth, continuous curve between them.
  //--------------
  // This fixes the blurry, fuzzy look of Bilinear, but it introduces "overshoot".
  // Because it creates a sharp curve, if you go from a pitch-black pixel next to 
  // a bright white pixel, the math curve will literally whip past white, causing 
  // a weird, artificial "halo" or ringing effect at sharp edges. 
  //--------------
  // To do this, we need a cubic weighting function, the most popular one is called the "Catmull-Rom" spline.
  // Instead of linear interpolation, we sample 4 pixels per row across 4 rows, 
  // perform 4 horizontal cubic blends, and then 1 vertical cubic blend on those results.
  // Thats 5 intense cubic calculations per channel, per pixel.
  //--------------
  // Here is the math layout of our 16-pixel hostage situation:
  //   p00   p10   p20   p30
  //    *_____*_____*_____*
  //   p01   p11   p21   p31    <-- Our actual target coordinate 
  //    *_____*__X__*_____*         is floating somewhere in the 
  //   p02   p12 | p22   p32        middle 2x2 grid (between p11 and p22)
  //    *_____*_____*_____*
  //   p03   p13   p23   p33
  //--------------
  // Notice something terrifying?
  // Our target is in the center, which means we need a padding of *one entire pixel*
  // Around our target in every direction. 
  // You know what this means? It means more fun out of bounds checking, yay :) (send help).
  //--------------
  // Personally, I still dont understand cubic interpolation, and you know what? Its okay.
  //--------------
  if (!kv || !kv->pixels) return NULL;
  Kanvas* scaled = kross_kanvas_init(kv->w*scale, kv->h*scale);
  if (!scaled || scale <= 0.0f) return NULL;
  if (scale == 1.0f) return scaled;
  //--------------
  float scale_inv = 1.0f/scale;
  //--------------
  for (int y = 0; y < (int)scaled->h; ++y)
  {
    for (int x = 0; x < (int)scaled->w; ++x)
    {
      //--------------
      // You might think (at least I did, but then again Im dumb so),
      // That Bicubic and Bilinear would be similar,
      // I thought, if Bilinear looks at a rectangle, Bicubic looks at a cube,
      // NOPE, Bicubic doesnt go into a deeper dimension,
      // It expands outwards on our flat 2D plane, like this:
      //
      // (x0, y0)      (x1, y0)      (x2, y0)      (x3, y0)
      // *_____________*_____________*_____________* row_top
      // |             |             |             |
      // *_____________*_____________*_____________* row_2nd
      // |             |      X      |             |
      // |             |     (Us)    |             |
      // *_____________*_____________*_____________* row_3rd
      // |             |             |             |
      // *_____________*_____________*_____________* row_bot
      // (x0, y3)      (x1, y3)      (x2, y3)      (x3, y3)
      // 
      // row_top is (x0-x3) with y0.
      // row_2nd is (x0-x3) with y1.
      // row_3rd is (x0-x3) with y2.
      // row_bot is (x0-x3) with y3.
      //--------------
      float src_x = x*scale_inv;
      float src_y = y*scale_inv;
      int base_x = floorf(src_x);
      int base_y = floorf(src_y);
      //--------------
      // Making sure we are safe here, because the Segfault gremlin loves unexpected surprises.
      int x0 = (base_x-1 >= 0) ? base_x-1 : 0;
      int y0 = (base_y-1 >= 0) ? base_y-1 : 0;
      int x1 = base_x;
      int y1 = base_y;
      int x2 = (base_x+1 < (int)kv->w) ? base_x+1 : base_x;
      int y2 = (base_y+1 < (int)kv->h) ? base_y+1 : base_y;
      int x3 = (base_x+2 < (int)kv->w) ? base_x+2 : x2;
      int y3 = (base_y+2 < (int)kv->h) ? base_y+2 : y2;
      //--------------
      float u = src_x-base_x;
      float v = src_y-base_y;
      //--------------
      // Everything else works the same way as Bilinear from here,
      // We get coordinates, then use an interpolation method,
      // Then write it to the buffer.
      //--------------
      Kolor row_top0 = kv->pixels[y0*kv->w+x0];
      Kolor row_top1 = kv->pixels[y0*kv->w+x1];
      Kolor row_top2 = kv->pixels[y0*kv->w+x2];
      Kolor row_top3 = kv->pixels[y0*kv->w+x3];
      //--------------
      Kolor row_2nd0 = kv->pixels[y1*kv->w+x0];
      Kolor row_2nd1 = kv->pixels[y1*kv->w+x1];
      Kolor row_2nd2 = kv->pixels[y1*kv->w+x2];
      Kolor row_2nd3 = kv->pixels[y1*kv->w+x3];
      //--------------
      Kolor row_3rd0 = kv->pixels[y2*kv->w+x0];
      Kolor row_3rd1 = kv->pixels[y2*kv->w+x1];
      Kolor row_3rd2 = kv->pixels[y2*kv->w+x2];
      Kolor row_3rd3 = kv->pixels[y2*kv->w+x3];
      //--------------
      Kolor row_bot0 = kv->pixels[y3*kv->w+x0];
      Kolor row_bot1 = kv->pixels[y3*kv->w+x1];
      Kolor row_bot2 = kv->pixels[y3*kv->w+x2];
      Kolor row_bot3 = kv->pixels[y3*kv->w+x3];
      //--------------
      // Now we cerp horizontally in linear order: left-right (0-1-2-3).
      Kolor row_top = kross_kolor_cerp(row_top0, row_top1, row_top2, row_top3, u);
      Kolor row_2nd = kross_kolor_cerp(row_2nd0, row_2nd1, row_2nd2, row_2nd3, u);
      Kolor row_3rd = kross_kolor_cerp(row_3rd0, row_3rd1, row_3rd2, row_3rd3, u);
      Kolor row_bot = kross_kolor_cerp(row_bot0, row_bot1, row_bot2, row_bot3, u);
      //--------------
      // Then we cerp vertically in linear order: top-bottom (top-2nd-3rd-bottom).
      Kolor row_final = kross_kolor_cerp(row_top, row_2nd, row_3rd, row_bot, v);
      // Then we write it to the buffer.
      kross_kanvas_pixel(scaled, x, y, row_final);
      //--------------
    }
  }

  return scaled;
}
// -------------------------------------
Kanvas* kross_kanvas_scale(Kanvas* kv, float scale, KInterpType interp)
{
  if (interp == KROSS_INTERP_NNI)      return kross_kanvas_scale_nni(kv, scale);
  if (interp == KROSS_INTERP_BILINEAR) return kross_kanvas_scale_bilinear(kv, scale);
  if (interp == KROSS_INTERP_BICUBIC)  return kross_kanvas_scale_bicubic(kv, scale);
  return NULL;
}
// -------------------------------------
static Kanvas* kross_kanvas_rotate_nni(Kanvas* kv, float angle_in_degrees)
{
  if (!kv || !kv->pixels || kv->w == 0 || kv->h == 0) return NULL;

  Kanvas* tmp = kross_kanvas_init(kv->w, kv->h);
  if (!tmp || !tmp->pixels) return NULL;

  float angle_in_radians = kross_math_cv_deg2rad(angle_in_degrees);

  float cos_angle = cosf(-angle_in_radians);
  float sin_angle = sinf(-angle_in_radians);

  for (int dy = 0; dy < (int)kv->h; ++dy)
  {
    for (int dx = 0; dx < (int)kv->w; ++dx)
    {
      float src_x = dx*cos_angle - dy*sin_angle;
      float src_y = dx*sin_angle + dy*cos_angle;

      src_x = kross_math_clampf(src_x, 0, kv->w-1);
      src_y = kross_math_clampf(src_y, 0, kv->h-1);

      int src_x_i = (int)roundf(src_x);
      int src_y_i = (int)roundf(src_y);

      src_x_i = kross_math_clamp(src_x_i, 0, (int)kv->w-1);
      src_y_i = kross_math_clamp(src_y_i, 0, (int)kv->h-1);

      Kolor kolor = kv->pixels[src_y_i*kv->w + src_x_i];

      kross_kanvas_pixel(tmp, dx, dy, kolor);
      //--------------
    }
  }

  return tmp;
}
// -------------------------------------
static Kanvas* kross_kanvas_rotate_bilinear(Kanvas* kv, float angle_in_degrees)
{
  if (!kv || !kv->pixels || kv->w == 0 || kv->h == 0) return NULL;
  Kanvas* tmp = kross_kanvas_init(kv->w, kv->h);
  if (!tmp || !tmp->pixels) return NULL;

  float angle_in_radians = kross_math_cv_deg2rad(angle_in_degrees);
  float cos_angle = cosf(-angle_in_radians);
  float sin_angle = sinf(-angle_in_radians);

  for (int dy = 0; dy < (int)kv->h; ++dy)
  {
    for (int dx = 0; dx < (int)kv->w; ++dx)
    {
      float src_x = dx*cos_angle - dy*sin_angle;
      float src_y = dx*sin_angle + dy*cos_angle;
      src_x = kross_math_clampf(src_x, 0, kv->w-1);
      src_y = kross_math_clampf(src_y, 0, kv->h-1);

      int x0 = floorf(src_x);
      int y0 = floorf(src_y);
      int x1 = (x0+1 < (int)kv->w) ? x0+1 : x0;
      int y1 = (y0+1 < (int)kv->h) ? y0+1 : y0;

      float u = src_x-x0;
      float v = src_y-y0;

      Kolor top_left  = kv->pixels[y0*kv->w + x0];
      Kolor top_right = kv->pixels[y0*kv->w + x1];
      Kolor bot_left  = kv->pixels[y1*kv->w + x0];
      Kolor bot_right = kv->pixels[y1*kv->w + x1];

      Kolor row_top = kross_kolor_lerp(top_left, top_right, u);
      Kolor row_bot = kross_kolor_lerp(bot_left, bot_right, u);
      Kolor final   = kross_kolor_lerp(row_top, row_bot, v);
      kross_kanvas_pixel(tmp, dx, dy, final);
    }
  }

  return tmp;
}
// -------------------------------------
static Kanvas* kross_kanvas_rotate_bicubic(Kanvas* kv, float angle_in_degrees)
{
  if (!kv || !kv->pixels || kv->w == 0 || kv->h == 0) return NULL;
  Kanvas* tmp = kross_kanvas_init(kv->w, kv->h);
  if (!tmp || !tmp->pixels) return NULL;

  float angle_in_radians = kross_math_cv_deg2rad(angle_in_degrees);
  float cos_angle = cosf(-angle_in_radians);
  float sin_angle = sinf(-angle_in_radians);

  for (int dy = 0; dy < (int)kv->h; ++dy)
  {
    for (int dx = 0; dx < (int)kv->w; ++dx)
    {
      float src_x = dx*cos_angle - dy*sin_angle;
      float src_y = dx*sin_angle + dy*cos_angle;
      src_x = kross_math_clampf(src_x, 0, kv->w-1);
      src_y = kross_math_clampf(src_y, 0, kv->h-1);

      int base_x = floorf(src_x);
      int base_y = floorf(src_y);
      int x0 = (base_x-1 >= 0) ? base_x-1 : 0;
      int y0 = (base_y-1 >= 0) ? base_y-1 : 0;
      int x1 = base_x;
      int y1 = base_y;
      int x2 = (base_x+1 < (int)kv->w) ? base_x+1 : base_x;
      int y2 = (base_y+1 < (int)kv->h) ? base_y+1 : base_y;
      int x3 = (base_x+2 < (int)kv->w) ? base_x+2 : x2;
      int y3 = (base_y+2 < (int)kv->h) ? base_y+2 : y2;

      float u = src_x-base_x;
      float v = src_y-base_y;

      Kolor row_top0 = kv->pixels[y0*kv->w+x0];
      Kolor row_top1 = kv->pixels[y0*kv->w+x1];
      Kolor row_top2 = kv->pixels[y0*kv->w+x2];
      Kolor row_top3 = kv->pixels[y0*kv->w+x3];

      Kolor row_2nd0 = kv->pixels[y1*kv->w+x0];
      Kolor row_2nd1 = kv->pixels[y1*kv->w+x1];
      Kolor row_2nd2 = kv->pixels[y1*kv->w+x2];
      Kolor row_2nd3 = kv->pixels[y1*kv->w+x3];

      Kolor row_3rd0 = kv->pixels[y2*kv->w+x0];
      Kolor row_3rd1 = kv->pixels[y2*kv->w+x1];
      Kolor row_3rd2 = kv->pixels[y2*kv->w+x2];
      Kolor row_3rd3 = kv->pixels[y2*kv->w+x3];

      Kolor row_bot0 = kv->pixels[y3*kv->w+x0];
      Kolor row_bot1 = kv->pixels[y3*kv->w+x1];
      Kolor row_bot2 = kv->pixels[y3*kv->w+x2];
      Kolor row_bot3 = kv->pixels[y3*kv->w+x3];
      //--------------
      Kolor row_top = kross_kolor_cerp(row_top0, row_top1, row_top2, row_top3, u);
      Kolor row_2nd = kross_kolor_cerp(row_2nd0, row_2nd1, row_2nd2, row_2nd3, u);
      Kolor row_3rd = kross_kolor_cerp(row_3rd0, row_3rd1, row_3rd2, row_3rd3, u);
      Kolor row_bot = kross_kolor_cerp(row_bot0, row_bot1, row_bot2, row_bot3, u);
      //--------------
      Kolor row_final = kross_kolor_cerp(row_top, row_2nd, row_3rd, row_bot, v);
      kross_kanvas_pixel(tmp, dx, dy, row_final);
    }
  }

  return tmp;
}
// -------------------------------------
Kanvas* kross_kanvas_rotate(Kanvas* kv, float angle_in_degrees, KInterpType interp)
{
  if (interp == KROSS_INTERP_NNI)      return kross_kanvas_rotate_nni(kv, angle_in_degrees);
  if (interp == KROSS_INTERP_BILINEAR) return kross_kanvas_rotate_bilinear(kv, angle_in_degrees);
  if (interp == KROSS_INTERP_BICUBIC)  return kross_kanvas_rotate_bicubic(kv, angle_in_degrees);
  return NULL;
}
// -------------------------------------
Vek2 kross_kanvas_nrm(Kanvas* kv)
{
  float nrm_x = (float)kv->x/(float)kv->w;
  float nrm_y = (float)kv->y/(float)kv->h;
  return (Vek2){nrm_x, nrm_y};
}
// -------------------------------------
void kross_kanvas_blit(Kanvas* kv_main, Kanvas* kv_sub)
{
  //--------------
  // Drawing a kanvas onto a kanvas,
  // Or the fancy word for it, "blitting",
  //
  // Let me just rant a little bit here,
  // Why kv_sub first? Why not kv_main as the first parameter?
  // Let me yap a little bit here, if these comments bother you,
  // Or they feel extra, please remove them, their existence is for entertainment,
  // If you only want knowledge, skip below :).
  //
  // We go back to the dinosaur ages, when Intel and AT&T were respected,
  // Two assembly variations, known as dialects were invented,
  // Because two tech giants wouldnt agree on how to copy a number,
  // Intel said, destination first, source second.
  // Intel Dialect; blit(where_it_goes, what_it_is)
  // Intel Dialect: blit(kv_main, player);
  //
  // AT&T  said, source first, destination second.
  // AT&T  Dialect: blit(what_it_is, where_it_goes);
  // AT&T  Dialect: blit(player, kv_main);
  //
  // For me, AT&Ts dialect is a lot easier to read,
  // "Draw the player onto kv_main".
  // Meanwhile Intels reads like,
  // "Onto kv_main kv, draw the player".
  //
  // Nowadays everyone speaks Intels Dialect because Intel won.
  // So we will also use Intels dialect, to get familiar with it.
  //--------------
  if (!kv_main || !kv_sub) return;
  if (kv_sub->w > kv_main->w || kv_sub->h > kv_main->h) return;
  if (kv_sub->x+kv_sub->w > kv_main->w || kv_sub->y+kv_sub->h > kv_main->h) return;
  //--------------
  for (int y = 0; y < (int)kv_sub->h; ++y)
  {
    for (int x = 0; x < (int)kv_sub->w; ++x)
    {
      //--------------
      int sub_i = y*kv_sub->w+x;
      int main_i = (y+kv_sub->y)*kv_main->w+(x+kv_sub->x);
      kv_main->pixels[main_i] = kv_sub->pixels[sub_i];
      //--------------
    }
  }
}
// -------------------------------------
void kross_kanvas_blitr(Kanvas* kv_main, Rekt start, Rekt end, Kanvas* kv_sub)
{
  //--------------
  // The ghetto version of Raylibs DrawTexturePro(),
  // Lets instantly hop into the explanation here,
  // To stretch or shrink our sprite, we calculate a scale factor.
  // Notice how we are going to loop through the destination rectangle (end.h, end.w).
  // Why loop the destination instead of the source?
  // Because if you scale an image up by looping through the source pixels,
  // you end up with empty "holes" in your drawing where no source pixel landed.
  // Looping the destination guarantees every single pixel on screen gets filled!
  //--------------
  float scale_x = (float)start.w/end.w;
  float scale_y = (float)start.h/end.h;
  //--------------
  for (int dy = 0; dy < (int)end.h; ++dy)
  {
    //--------------
    // Calculate where we are actually drawing on the main canvas.
    // If we are about to draw off the edge of the universe we skip it.
    // No segfault gremlin today, thank you very much.
    //--------------
    int end_y = (int)end.y+dy;
    if (0 > end_y || end_y >= (int)kv_main->h) continue; 
    //--------------
    // Now we use our scale factor to travel back in time and figure out 
    // which pixel from our source image belongs here. 
    // This is called "Nearest Neighbor" scaling.
    // It makes things beautifully crunchy and pixelated, just how the retro gods intended.
    //--------------
    int src_y = (int)(start.y+(dy*scale_y));
    if (0 > src_y || src_y >= (int)kv_sub->h) continue; 
    //--------------
    for (int dx = 0; dx < (int)end.w; ++dx)
    {
      //--------------
      int end_x = (int)end.x+dx;
      if (0 > end_x || end_x >= (int)kv_main->w) continue; 
      //--------------
      int src_x = (int)(start.x+(dx*scale_x));
      if (0 > src_x || src_x >= (int)kv_sub->w) continue; 
      //--------------
      // We meet with this formula again, and we will be meeting it many, many, many more times.
      size_t src_i = src_y*kv_sub->w+src_x;
      size_t dst_i = end_y*kv_main->w+end_x;
      //--------------
      kv_main->pixels[dst_i] = kross_kolor_blend(kv_sub->pixels[src_i], kv_main->pixels[dst_i]);
      //--------------
    }
  }
}
// -------------------------------------
void kross_kanvas_blur(Kanvas* kv, size_t radius)
{
  //--------------
  // This implementation of blur is called box-blur,
  // It is the simplest and the fastest blur algorithm.
  // There is also gaussian-blur, credit: Friedrich Gauss.
  // That version is mathematically heavier and slower but yields prettier, bloom-like results.
  // But we are simple people, and boxes get the job done.
  //--------------
  if (!kv || radius == 0) return;
  //--------------
  // First, we create a temporary copy of our entire canvas.
  // Why? Because if we calculate a blurred pixel and write it back into the same image,
  // the next pixel over will read that already blurred pixel for its own calculation.
  // The result? A weird, directional smear that looks like a bad watercolor painting.
  // We need an uncontaminated "read-only" source.
  //--------------
  Kanvas* tmp = kross_kanvas_copy(kv);
  if (!tmp) return;
  //--------------
  for (int y = 0; y < (int)kv->h; ++y)
  {
    for (int x = 0; x < (int)kv->w; ++x)
    {
      //--------------
      size_t total_r = 0, total_g = 0, total_b = 0;
      size_t px_count = 0;
      //--------------
      // This nested loop is the "box" in box-blur. 
      // We draw a square around our current pixel, determined by the radius.
      // A radius of 1 means we check a 3x3 grid.
      // A radius of 10 means a 21x21 grid, and your CPU will start to feel it.
      //--------------
      for (int off_y = -(int)radius; off_y <= (int)radius; ++off_y)
      {
        for (int off_x = -(int)radius; off_x <= (int)radius; ++off_x)
        {
          //--------------
          int target_x = x+off_x;
          int target_y = y+off_y;
          target_x = kross_math_clamp(target_x, 0, (int)kv->w-1);
          target_y = kross_math_clamp(target_y, 0, (int)kv->h-1);
          //--------------
          Kolor neighbor = kv->pixels[target_y*kv->w+target_x];
          total_r += neighbor.r;
          total_g += neighbor.g;
          total_b += neighbor.b;
          px_count++;
          //--------------
        }
      }
      //--------------
      tmp->pixels[y*tmp->w+x] = (Kolor){
        (uint8_t)(total_r/px_count),
        (uint8_t)(total_g/px_count),
        (uint8_t)(total_b/px_count),
        (uint8_t)(255)
      };
      //--------------
    }
  }
  //--------------
  memcpy(kv->pixels, tmp->pixels, kv->w*kv->h*sizeof(Kolor));
  free(tmp->pixels);
  free(tmp);
  //--------------
}
// -------------------------------------
void kross_kanvas_vignette(Kanvas* kv, size_t radius)
{
  //--------------
  // As much as I would like to complain about this one,
  // There really is no reason to,
  // I didnt watch any painful yt tutorials, because I didnt find any.
  // What I did is went StackOverflow hunting and found code,
  // Then changed the names, and here we are.
  // After looking at explanations online,
  // Vignette is a dark circle, that starts at the screen-center
  // Then expands outwards, as it expands it gets darker.
  // At the center it is completely see-through,
  // At the edges its completely dark.
  //--------------
  int cx = kv->w/2;
  int cy = kv->h/2;
  int sq_radius = radius*radius;
  //--------------
  for (int y = 0; y < (int)kv->h; ++y)
  {
    for (int x = 0; x < (int)kv->w; ++x)
    {
      //--------------
      int dx = cx-x;
      int dy = cy-y;
      int sq_distance = dx*dx+dy*dy;
      //--------------
      if (sq_distance <= sq_radius) continue;
      else
      {
        float factor = (float)sq_distance/(float)sq_radius;
        factor = kross_math_clampf(factor, 0, 1);
        float intensity = 1.0f-factor;
        Kolor kolor     = kross_kolor_get(kv, x, y);
        Kolor scaled    = kross_kolor_scale(kolor, intensity);
        kross_kanvas_pixel(kv, x, y, scaled);
      }
      //--------------
    }
  }
}
// -------------------------------------
void kross_kanvas_grayscale(Kanvas* kv)
{
  for (size_t i = 0; i < kv->w*kv->h; ++i)
  {
    kv->pixels[i] = kross_kolor_grayscale(kv->pixels[i]);
  }
}
// -------------------------------------
Kolor kross_kolor_get(Kanvas* kv, int x, int y)
{
  //--------------
  if (!kv) return (Kolor){0, 0, 0, 255};
  x = kross_math_clamp(x, 0, kv->w-1);
  y = kross_math_clamp(y, 0, kv->h-1);
  return kv->pixels[y*kv->w+x];
  //--------------
}
// -------------------------------------
void kross_kanvas_rect(Kanvas* kv, int x, int y, size_t width, size_t height, Kolor kolor)
{
  //--------------
  // Here we go, easily one of my favourite functions.
  // This function is where it all started out,
  // I was watching a Tsoding video on Olivec and I remember,
  // I copied his rect function word for word, bar for bar,
  // When I saw it work on that PPM file, it was pure magic.
  //
  // I changed it a few times before deciding to keep it like this,
  // This is how OpenGL/Vulkan renders rectangles, circles, polygons, etc,
  // A rectangle is two triangles, a circle is "infinte" triangles,
  // But really it depends on how many you want it to be, it can be 3, 8, 20.
  //--------------
  Vek2 top_left   = {x, y};
  Vek2 top_right  = {x+width, y};
  Vek2 bot_left   = {x, y+height};
  Vek2 bot_right  = {x+width, y+height};
  //--------------
  kross_kanvas_triangle(kv, top_left,  bot_left, top_right, kolor);
  kross_kanvas_triangle(kv, top_right, bot_left, bot_right, kolor);
  //--------------
}
// -------------------------------------
void kross_kanvas_rectv(Kanvas* kv, Vek2 pos, Vek2 size, Kolor kolor)
{
  //--------------
  // Peak library "development",
  // Take previous function, change parameter, fake new function.
  // Also for size {x: width, y: height}.
  //--------------
  kross_kanvas_rect(kv, (int)pos.x, (int)pos.y, (size_t)size.x, (size_t)size.y, kolor);
  //--------------
}
// -------------------------------------
void kross_kanvas_rectr(Kanvas* kv, Rekt rect, Kolor kolor)
{
  kross_kanvas_rect(kv, rect.x, rect.y, rect.w, rect.h, kolor);
}
// -------------------------------------
void kross_kanvas_rect_stroke(Kanvas* kv, int x, int y, size_t width, size_t height, size_t thicc, Kolor kolor)
{
  //--------------
  // For this one we draw 4 "thicc" sized rectangles that connect to each other.
  //--------------
  kross_kanvas_rect(kv, x, y, width, thicc, kolor);
  kross_kanvas_rect(kv, x, y+height-thicc, width, thicc, kolor);
  kross_kanvas_rect(kv, x, y+thicc, thicc, height-2*thicc, kolor);
  kross_kanvas_rect(kv, x+width-thicc, y+thicc, thicc, height-2*thicc, kolor);
  //--------------
}
// -------------------------------------
void kross_kanvas_rect_strokev(Kanvas* kv, Vek2 pos, Vek2 size, size_t thicc, Kolor kolor)
{
  // For size {x: width, y: height}
  kross_kanvas_rect_stroke(kv, (int)pos.x, (int)pos.y, (size_t)size.x, (size_t)size.y, thicc, kolor);
}
// -------------------------------------
void kross_kanvas_rect_stroker(Kanvas* kv, Rekt rect, size_t thicc, Kolor kolor)
{
  kross_kanvas_rect_stroke(kv, rect.x, rect.y, rect.w, rect.h, thicc, kolor);
}
// -------------------------------------
bool kross_hit_rect_rect(int rect0_x, int rect0_y, size_t rect0_w, size_t rect0_h, int rect1_x, int rect1_y, size_t rect1_w, size_t rect1_h)
{ 
  //--------------
  // Big thanks to jeffreythompson.org for this one,
  // I straight up copied his code and changed the names,
  // To cut this super short:
  //
  // These are called AABB (Axis-Aligned Bounding Box) collisions,
  // Why is it called that?
  // Because the edges of the box are "aligned" with the screens x/y axes.
  // To cut the fancy names, this is the simplest way to do collisions,
  // If you rotate your rectangle even slightly, the math does not work at all.
  // To check if the rectangles are colliding, we ask 4 confusing questions:
  //
  // Is the RIGHT edge of r1 to the RIGHT of the LEFT edge of r2?
  // Is the LEFT edge of r1 to the LEFT of the RIGHT edge of r2?
  // Is the BOTTOM edge of r1 BELOW the TOP edge of r2?
  // Is the TOP edge of r1 ABOVE the BOTTOM edge of r2?
  //
  // If all of these return to be true, then we are colliding.
  //--------------
  int r1_edge_right  = rect0_x+rect0_w;
  int r2_edge_right  = rect1_x+rect1_w;
  int r1_edge_bottom = rect0_y+rect0_h;
  int r2_edge_bottom = rect1_y+rect1_h;
  //--------------
  return (r1_edge_right  >= rect1_x && rect0_x <= r2_edge_right &&
          r1_edge_bottom >= rect1_y && rect0_y <= r2_edge_bottom);
  //--------------
}
// -------------------------------------
bool kross_hit_rect_rectv(Vek2 rect0, Vek2 rect0_size, Vek2 rect1, Vek2 rect1_size)
{
  return kross_hit_rect_rect((int)rect0.x, (int)rect0.y, (size_t)rect0_size.x, (size_t)rect0_size.y,
                             (int)rect1.x, (int)rect1.y, (size_t)rect1_size.x, (size_t)rect1_size.y);
}
// -------------------------------------
bool kross_hit_rect_rectr(Rekt rect0, Rekt rect1)
{
  return kross_hit_rect_rect(rect0.x, rect0.y, rect0.w, rect0.h, rect1.x, rect1.y, rect1.w, rect1.h);
}
// -------------------------------------
bool kross_hit_rect_circle(int rect_x, int rect_y, size_t rect_w, size_t rect_h, int cx, int cy, size_t r)
{
  //--------------
  int temp_x = cx;
  int temp_y = cy;
  int r_edge_right  = rect_x+rect_w;
  int r_edge_bottom = rect_y+rect_h;
  //--------------
  if       (cx < rect_x)        temp_x = rect_x;
  else if  (cx > r_edge_right)  temp_x = r_edge_right;
  if       (cy < rect_y)        temp_y = rect_y;
  else if  (cy > r_edge_bottom) temp_y = r_edge_bottom;
  //--------------
  int distx = cx-temp_x;
  int disty = cy-temp_y;
  return ((distx*distx+disty*disty) <= (int)(r*r));
  //--------------
}
// -------------------------------------
bool kross_hit_rect_circlev(Vek2 rect, Vek2 rect_size, Vek2 circle, size_t r)
{
  return kross_hit_rect_circle((int)rect.x, (int)rect.y, (size_t)rect_size.x, (size_t)rect_size.y, (int)circle.x, (int)circle.y, r);
}
// -------------------------------------
bool kross_hit_rect_circler(Rekt rect, Vek2 circle, size_t radius)
{
  return kross_hit_rect_circle((int)rect.x, (int)rect.y, rect.w, rect.h,
                                     (int)circle.x, (int)circle.y, radius);
}
// -------------------------------------
float kross_math_ease_in_quad(float t)
{
  return t*t;
}
// -------------------------------------
float kross_math_ease_out_quad(float t)
{
  return t*(2.0f-t);
}
// -------------------------------------
float kross_math_ease_in_out_quad(float t)
{
  return t < 0.5f ? 2*t*t : 1.0f - powf(-2*t + 2, 2)/2;
}
// -------------------------------------
float kross_math_ease_in_elastic(float t)
{
  const float c4 = (2*KROSS_PI)/3;

  return t == 0 ? 0 : t == 1 ? 1 : -powf(2, 10*t - 10) * sinf((t * 10.0f - 10.75f) * c4);
}
// -------------------------------------
float kross_math_ease_out_elastic(float t)
{
  return (float)(sinf(-13.0f*(t-1.0f)*(KROSS_PI/2.0f))*powf(2.0f, -10.0f*t)+1.0f);
}
// -------------------------------------
float kross_math_ease_in_out_elastic(float t)
{
  return (float)(sinf(-13.0f*(t-1.0f)*(KROSS_PI/2.0f))*powf(2.0f, -10.0f*t)+1.0f);
}
// -------------------------------------
float kross_math_ease_in_quint(float t)
{
  return t*t*t*t*t;
}
// -------------------------------------
float kross_math_ease_out_quint(float t)
{
  return 1.0f-powf(1.0f-t, 5.0f);
}
// -------------------------------------
float kross_math_ease_in_out_quint(float t)
{
  return t*t*t*(t*(t*6.0f-15.0f)+10.0f);
}
// -------------------------------------
float kross_math_ease_in_cubic(float t)
{
  return t*t*t;
}
// -------------------------------------
float kross_math_ease_out_cubic(float t)
{
  return 1.0f-powf(1.0f-t, 3.0f);
}
// -------------------------------------
float kross_math_ease_in_out_cubic(float t)
{
  return t < 0.5f ? 4.0f*t*t*t : 1.0f-powf(-2.0f*t+2.0f, 3.0f)/2.0f;
}
// -------------------------------------
float kross_math_ease_in_sine(float t)
{  
  return 1.0f-cosf((t*KROSS_PI)/2.0f);
}
// -------------------------------------
float kross_math_ease_out_sine(float t)
{
  return sinf((t*KROSS_PI)/2.0f);
}
// -------------------------------------
float kross_math_ease_in_out_sine(float t)
{
  return -(cosf(KROSS_PI*t) - 1.0f)/2.0f;
}
// -------------------------------------
float kross_math_ease_in_expo(float t)
{
  return t == 0.0f ? 0.0f : powf(2.0f, 10.0f*t - 10.0f);
}
// -------------------------------------
float kross_math_ease_out_expo(float t)
{
  return t == 1.0f ? 1.0f : 1.0f-powf(2.0f, -10.0f*t);
}
// -------------------------------------
float kross_math_ease_in_out_expo(float t)
{
  return t == 0.0f ? 0.0f : t == 1.0f ? 1.0f : t < 0.5f ? powf(2.0f, 20.0f*t - 10.0f)/2.0f
  : (2.0f-powf(2.0f, -20.0f*t + 10.0f))/2.0f;
}
// -------------------------------------
float kross_math_ease_in_bounce(float t)
{
  return 1.0f-kross_math_ease_out_bounce(1.0f-t);
}
// -------------------------------------
float kross_math_ease_out_bounce(float t)
{
  const float n1 = 7.5625f;
  const float d1 = 2.75f;

  if (t < 1.0f/d1) return n1*t*t;
  else if (t < 2.0f/d1) return n1*(t-1.5f/d1)*(t-1.5f/d1) + 0.75f;
  else if (t < 2.5f/d1) return n1*(t-2.25f/d1)*(t-2.25f/d1) + 0.9375f;
  else return n1 * (t - 2.625f/d1) * (t - 2.625f/d1) + 0.984375f;
}
// -------------------------------------
float kross_math_ease_in_out_bounce(float t)
{
  return t < 0.5f ? (1.0f-kross_math_ease_out_bounce(1.0f - 2.0f*t))/2.0f : (1.0f+kross_math_ease_out_bounce(2.0f*t - 1.0f))/2.0f;
}
// -------------------------------------
void kross_kanvas_circle(Kanvas* kv, int cx, int cy, size_t r, Kolor kolor)
{
  //--------------
  // Left-right.
  int left_x = cx-r;
  int right_x = cx+r;
  // Top-bottom.
  int top_y = cy-r;
  int bottom_y = cy+r;
  //--------------
  for (int y = top_y; y <= bottom_y; ++y)
  {
    if (0 <= y && y < (int) kv->h)
    {
      for (int x = left_x; x <= right_x; ++x)
      {
        if (0 <= x && x < (int) kv->w)
        {
          //--------------
          int x1 = x-cx;
          int y1 = y-cy;
          //--------------
          if (x1*x1 + y1*y1 <= (int)(r*r)) kross_kanvas_pixel(kv, x, y, kolor);
          //--------------
        }
      }
    }
  }
}
// -------------------------------------
void kross_kanvas_circlev(Kanvas* kv, Vek2 center, size_t radius, Kolor kolor)
{
  kross_kanvas_circle(kv, (int)center.x, (int)center.y, radius, kolor);
}
// -------------------------------------
void kross_kanvas_circle_stroke(Kanvas* kv, int cx, int cy, size_t r, size_t thicc, Kolor kolor)
{
  //--------------
  // Alright so the way to outline a circle,
  // Is to draw two, a big one, a smaller one, then fill the gap between them.
  // Now to control thickness its simple, 
  // take the radius of the big circle (r) and remove thickness from it,
  // Say we want to stroke a circle with radius 40 thickness 3,
  // r = 40, inner_r = 40-3 = 37. So the gap thats left is just thickness.
  // Heres what I mean:
  //              #######             
  //           ###       ###          
  //         ##             ##        
  //        #    OOOOOOOOO    #       
  //      ##   OO         OO   ##     
  //     #    O             O    #    
  //    #    O               O    #   
  //   #    O                 O    #  
  //   #    O                 O .  #  <-- A pixel (.) in the gap.
  //   #    O                 O    #  
  //    #    O               O    #   
  //     #    O             O    #    
  //      ##   OO         OO   ##     
  //        #    OOOOOOOOO    #       
  //         ##             ##        
  //           ###       ###          
  //              #######
  //--------------
  int left_x     = cx-r;
  int right_x   = cx+r;
  int top_y     = cy-r;
  int bottom_y   = cy+r;
  //--------------
  if (thicc > r) thicc = r;
  int inner = (r-thicc)*(r-thicc);
  int outer = r*r;
  //--------------
  for (int y = top_y; y <= bottom_y; ++y)
  {
    if (0 <= y && y < (int) kv->h)
    {
      for (int x = left_x; x <= right_x; ++x)
      {
        //--------------
        int x1 = x-cx;
        int y1 = y-cy;
        if (0 <= x && x < (int) kv->w)
        {
          // Making sure the pixels are smaller than outer but bigger than inner,
          // This means the pixel is inside of that point,
          // Which means we can fill it in.
          if (x1*x1 + y1*y1 <= outer && x1*x1 + y1*y1 >= inner)
          {
            kross_kanvas_pixel(kv, x, y, kolor);
          }
        }
        //--------------
      }
    }
  }
}
// -------------------------------------
void kross_kanvas_circle_strokev(Kanvas* kv, Vek2 center, size_t r, size_t thicc, Kolor kolor)
{
  kross_kanvas_circle_stroke(kv, (int)center.x, (int)center.y, r, thicc, kolor);
}
// -------------------------------------
static bool kross_math_triangle_edge_is_top_left(Vek2 start, Vek2 end)
{
  Vek2 edge = kross_math_vek2_sub(start, end);
  bool is_top_edge = edge.y == 0 && edge.x > 0;
  bool is_left_edge = edge.y < 0;
  return is_top_edge || is_left_edge;
}
// -------------------------------------
static int kross_math_triangle_edge_func(Vek2 p1, Vek2 p2, Vek2 px)
{
  Vek2 p12 = kross_math_vek2_sub(p1, p2);
  Vek2 p1px = kross_math_vek2_sub(px, p1);
  return p12.x*p1px.y - p12.y*p1px.x;
}
// -------------------------------------
void kross_kanvas_triangle(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kolor)
{
  //--------------
  // Welcome to the heart of the rasterizer,
  // To the most painful, yet most beautiful function in graphics programming,
  // For this one, I had the pleasure of following one of Pikumas guides,
  // If youve never heard of Pikuma or seen a video form him,
  // Then go. Im not gonna waste your time and clutter your brain on this one,
  // The best way to learn how triangle rasterizing works,
  // is to go and watch that hour long video.
  // The video is titled: "Triangle Rasterization - Pikuma".
  //--------------
  int min_x = KROSS_MIN(KROSS_MIN(v0.x, v1.x), v2.x);
  int min_y = KROSS_MIN(KROSS_MIN(v0.y, v1.y), v2.y);
  int max_x = KROSS_MAX(KROSS_MAX(v0.x, v1.x), v2.x);
  int max_y = KROSS_MAX(KROSS_MAX(v0.y, v1.y), v2.y);
  //--------------
  int bias0 = kross_math_triangle_edge_is_top_left(v0, v1) ? 0 : -1;
  int bias1 = kross_math_triangle_edge_is_top_left(v1, v2) ? 0 : -1;
  int bias2 = kross_math_triangle_edge_is_top_left(v2, v0) ? 0 : -1;
  //--------------
  for (int y = min_y; y <= max_y; ++y)
  {
    for (int x = min_x; x <= max_x; ++x)
    {
      //--------------
      int w0 = kross_math_triangle_edge_func(v0, v1, (Vek2){x, y}) + bias0;
      int w1 = kross_math_triangle_edge_func(v1, v2, (Vek2){x, y}) + bias1;
      int w2 = kross_math_triangle_edge_func(v2, v0, (Vek2){x, y}) + bias2;
      //--------------
      // If all weights are >= 0 then the pixel is inside the triangle.
      //--------------
      if (w0 >= 0 && w1 >= 0 && w2 >= 0) kross_kanvas_pixel(kv, x, y, kolor);
      //--------------
    }
  }
}
// -------------------------------------
void kross_kanvas_triangle_tricolor(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kl0, Kolor kl1, Kolor kl2)
{
  //--------------
  int min_x = KROSS_MIN(KROSS_MIN(v0.x, v1.x), v2.x);
  int min_y = KROSS_MIN(KROSS_MIN(v0.y, v1.y), v2.y);
  int max_x = KROSS_MAX(KROSS_MAX(v0.x, v1.x), v2.x);
  int max_y = KROSS_MAX(KROSS_MAX(v0.y, v1.y), v2.y);
  //--------------
  float area = kross_math_triangle_edge_func(v0, v1, v2);
  if (area <= 0) return;
  //--------------
  float karea = 1.0f/fabsf(area);
  //--------------
  int bias0 = kross_math_triangle_edge_is_top_left(v0, v1) ? 0 : -1;
  int bias1 = kross_math_triangle_edge_is_top_left(v1, v2) ? 0 : -1;
  int bias2 = kross_math_triangle_edge_is_top_left(v2, v0) ? 0 : -1;
  //--------------
  for (int y = min_y; y <= max_y; ++y)
  {
    for (int x = min_x; x <= max_x; ++x)
    {
      //--------------
      int w0 = kross_math_triangle_edge_func(v0, v1, (Vek2){x, y})+bias0;
      int w1 = kross_math_triangle_edge_func(v1, v2, (Vek2){x, y})+bias1;
      int w2 = kross_math_triangle_edge_func(v2, v0, (Vek2){x, y})+bias2;
      //--------------
      if (w0 >= 0 && w1 >= 0 && w2 >= 0)
      {
        //--------------
        float alpha = w0*karea;
        float beta  = w1*karea;
        float gamma = w2*karea;
        //--------------
        int r = alpha*kl0.r+beta*kl1.r+gamma*kl2.r;
        int g = alpha*kl0.g+beta*kl1.g+gamma*kl2.g;
        int b = alpha*kl0.b+beta*kl1.b+gamma*kl2.b;
        kross_kanvas_pixel(kv, x, y, (Kolor){r, g, b, 255});
        //--------------
      }
    }
  }
}
// -------------------------------------
void kross_kanvas_triangle_stroke(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, size_t thicc, Kolor kolor)
{
  kross_kanvas_linev(kv, v0, v1, thicc, kolor);
  kross_kanvas_linev(kv, v1, v2, thicc, kolor);
  kross_kanvas_linev(kv, v2, v0, thicc, kolor);
}
// -------------------------------------
void kross_kanvas_line(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, Kolor kolor)
{
  //--------------
  Vek2 start = {x0, y0};
  Vek2 end = {x1, y1};
  Vek2 dir = kross_math_vek2_sub(end, start);
  Vek2 perp = {-dir.y, dir.x};
  Vek2 perp_norm = kross_math_vek2_nrm(perp);
  //--------------
  float half_thickness = thicc/2.0f;
  Vek2 offset = kross_math_vek2_scale(perp_norm, half_thickness);
  //--------------
  Vek2 v0 = kross_math_vek2_add(start, offset);
  Vek2 v1 = kross_math_vek2_sub(start, offset);
  Vek2 v2 = kross_math_vek2_add(end, offset);
  Vek2 v3 = kross_math_vek2_sub(end, offset);
  //--------------
  kross_kanvas_triangle(kv, v0, v2, v1, kolor);
  kross_kanvas_triangle(kv, v1, v2, v3, kolor);
  //--------------
}
// -------------------------------------
void kross_kanvas_linev(Kanvas* kv, Vek2 pos0, Vek2 pos1, size_t thicc, Kolor kolor)
{
  kross_kanvas_line(kv, pos0.x, pos0.y, pos1.x, pos1.y, thicc, kolor);
}
// -------------------------------------
void kross_kanvas_line_arrow(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, size_t head_len, float head_angle, Kolor kolor)
{
  //--------------
  // This function is just math I dont understand.
  // I dont even remember where I copied this function.
  // All I did was change the names around and use my own functions.
  //--------------
  kross_kanvas_line(kv, x0, y0, x1, y1, thicc, kolor);
  float rad_angle = kross_math_cv_deg2rad(head_angle);
  float angle = atan2(y1-y0, x1-x0);
  //--------------
  int x2 = x1-(int)(head_len*cosf(angle-rad_angle));
  int y2 = y1-(int)(head_len*sinf(angle-rad_angle));
  int x3 = x1-(int)(head_len*cosf(angle+rad_angle));
  int y3 = y1-(int)(head_len*sinf(angle+rad_angle));
  //--------------
  kross_kanvas_line(kv, x1, y1, x2, y2, thicc, kolor);
  kross_kanvas_line(kv, x1, y1, x3, y3, thicc, kolor);
  //--------------
}
// -------------------------------------
void kross_kanvas_line_arrowv(Kanvas* kv, Vek2 v0, Vek2 v1, size_t thicc, size_t head_len, float head_angle, Kolor kolor)
{
  kross_kanvas_line_arrow(kv, v0.x, v0.y, v1.x, v1.y, thicc, head_len, head_angle, kolor);
}
// -------------------------------------
void kross_kanvas_line_bezier_quad(Kanvas* kv, Vek2 p0, Vek2 cp, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor)
{
  // Credit: Paul de Casteljau (the first developer of the curves).
  // Credit: Pierre Bezier (the guy they were named after).
  //--------------
  // Bezier curves sound scary, but they arent.
  // Let me give a yt type explanation first, then an actual explanation.
  // A bezier curve, is just nested lerps.
  // If you do not know what lerp is, look below.
  // So its a lerp that lerps between two other lerps.
  // This specific bezier curve, is a quadratic bezier curve,
  // So it has only one control point. Now, what is a control point?
  // Say we have a straight line, from p0 to p1.
  // This control point lives somewhere inside this line and it pulls the line,
  // Like the string of a bow, thats a bezier curve, its a straight line until,
  // A control point (our hand) goes and pulls on it, making it curve.
  //--------------
  // Lets code the bezier curve,
  // float intermediate0 = lerp(p0, cp, t).
  // Alright, many questions here,
  // First, what is lerp? Lerp, or Linear Interpolation,
  // Is a formula for finding how far along we are in between to points.
  // t is always from 0 to 1, if we say something like,
  // lerp(p0, p1, t: 0.5) then we will get the center of these two points.
  // If t was 0.0, we would be at p0, and if t was 1.0 we would be at p1.
  // Second, we lerp from p0 to the control point,
  // Why? Because this is what actually starts creating the curve.
  // float intermediate1 = lerp(cp, p1, t).
  // Now we lerp back from the control point, to the second point.
  // And at the very end, we lerp between these two intermediate values,
  // float p_final = lerp(intermediate0, intermediate1, t).
  // One last thing we have to go over is t, how do we find t?
  // Like we said above, t is progress along these points,
  // But how do we find t? Its pretty simple.
  // We know computers cant draw actual curves like we humans can.
  // So what they do instead, is draw many small lines and connect them together.
  // This is what creates the curve illusion.
  // And so to find t, lets say we want the bezier curve to be 30 small lines.
  // We loop 30 times and divide i/30. Thats t, thats our progress.
  // And you know whats really cool? Setting the "resolution" as we call it to 1.
  // What do you think is going to happen? :)
  //--------------
  Vek2 point_pre = p0;
  //--------------
  for (size_t i = 0; i <= resolution; ++i)
  {
    //--------------
    float t = (float)i/(float)resolution;
    Vek2 point_bez = kross_math_bezier_quad(p0, cp, p1, t);
    //--------------
    kross_kanvas_linev(kv, point_pre, point_bez, thicc, kolor);
    point_pre = point_bez;
    //--------------
  }
  //--------------
  // LEARNING RESOURCES: "Rasterizing Splines in C" - Tsoding.
  //--------------
}
// -------------------------------------
void kross_kanvas_line_bezier_cube(Kanvas* kv, Vek2 p0, Vek2 cp0, Vek2 cp1, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor)
{
  // Credit: Paul de Casteljau (the first developer of the curves).
  // Credit: Pierre Bezier (the guy they were named after).
  //--------------
  // Above we explained quadratic curves, now lets explain cubic curves.
  // They are the exact same thing, the exact same concept, with one more step.
  // Theres two control points, so its a more curved curve.
  // And again, we just lerp from the first point to the first control point, 
  // a = lerp(p0, cp0, t). Then from the first control point to the second,
  // b = lerp(cp0, cp1, t). Then from the second control point to the second point.
  // c = lerp(cp1, p1, t). And again, we lerp the lerps.
  // final0 = lerp(a, b, t).
  // final1 = lerp(b, c, t).
  // final  = lerp(final0, final1, t).
  // Done, thats the cubic bezier curve.
  //--------------
  Vek2 point_pre = p0;
  //--------------
  for (size_t i = 0; i <= resolution; ++i)
  {
    //--------------
    float t = (float)i/(float)resolution;
    Vek2 point_bez = kross_math_bezier_cube(p0, cp0, cp1, p1, t);
    //--------------
    kross_kanvas_linev(kv, point_pre, point_bez, thicc, kolor);
    point_pre = point_bez;
    //--------------
  }
  //--------------
  // LEARNING RESOURCES: "Rasterizing Splines in C" - Tsoding.
  //--------------
}
// -------------------------------------
void kross_kanvas_grid(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, size_t thicc, Kolor kolor)
{
  size_t width = cols*gap;
  size_t height = rows*gap;

  for (size_t row = 0; row <= rows; ++row)
  {
    int y1 = y+row*gap;
    kross_kanvas_line(kv, x, y1, x+width, y1, thicc, kolor);
  }

  for (size_t col = 0; col <= cols; ++col)
  {
    int x1 = x+col*gap;
    kross_kanvas_line(kv, x1, y, x1, y+height, thicc, kolor);
  }
}
// -------------------------------------
void kross_kanvas_board(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, Kolor kl0, Kolor kl1)
{
  if (cols == 0 || rows == 0 || gap == 0) return;

  for (size_t row = 0; row < rows; ++row)
  {
    for (size_t col = 0; col < cols; ++col)
    {
      Kolor c = (row+col)%2 == 0 ? kl0 : kl1;
      kross_kanvas_rect(kv, x + col*gap, y + row*gap, gap, gap, c);
    }
  }
}
// -------------------------------------
Kamera* kross_kamera_init(Vek2 target, Vek2 target_dst, float zoom, float smoothness)
{
  //--------------
  Kamera* kr = malloc(sizeof(Kamera));
  if (!kr) return NULL;
  //--------------
  kr->target     = target;
  kr->target_dst = target_dst;
  kr->zoom       = zoom;
  kr->smoothness = smoothness;
  return kr;
  //--------------
}
// -------------------------------------
void kross_kamera_free(Kamera* kr)
{
  // A whole function for a free() call.
  // Call me the next Terry A. Davis.
  if (kr) free(kr);
}
// -------------------------------------
// All the camera functions are just the kanvas functions with converted coordinates.
// -------------------------------------
void kross_kamera_line(Kanvas* kv, Kamera* kr, int x0, int y0, int x1, int y1, size_t thicc, Kolor kolor)
{
  Vek2 screen1 = kross_math_vek2_kamera(kr, (Vek2){x0, y0});
  Vek2 screen2 = kross_math_vek2_kamera(kr, (Vek2){x1, y1});
  size_t screen_thicc = thicc*kr->zoom;
  kross_kanvas_linev(kv, screen1, screen2, screen_thicc, kolor);
}
// -------------------------------------
void kross_kamera_rect(Kanvas* kv, Kamera* kr, int x, int y, size_t width, size_t height, Kolor kolor)
{
  Vek2 screen = kross_math_vek2_kamera(kr, (Vek2){x, y});
  size_t screen_width = width*kr->zoom;
  size_t screen_height = height*kr->zoom;
  kross_kanvas_rectv(kv, screen, (Vek2){screen_width, screen_height}, kolor);
}
// -------------------------------------
void kross_kamera_rectv(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 size, Kolor kolor)
{
  kross_kamera_rect(kv, kr, pos.x, pos.y, size.x, size.y, kolor);
}
// -------------------------------------
void kross_kamera_rectr(Kanvas* kv, Kamera* kr, Rekt rect, Kolor kolor)
{
  kross_kamera_rect(kv, kr, rect.x, rect.y, rect.w, rect.h, kolor);
}
// -------------------------------------
void kross_kamera_rect_stroke(Kanvas* kv, Kamera* kr, int x, int y, size_t width, size_t height, size_t thicc, Kolor kolor)
{
  Vek2 screen = kross_math_vek2_kamera(kr, (Vek2){x, y});
  size_t screen_width  = width*kr->zoom;
  size_t screen_height = height*kr->zoom;
  size_t screen_thicc  = thicc*kr->zoom;
  kross_kanvas_rect_strokev(kv, screen, (Vek2){screen_width, screen_height}, screen_thicc, kolor);
}
// -------------------------------------
void kross_kamera_rect_strokev(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 size, size_t thicc, Kolor kolor)
{
  kross_kamera_rect_stroke(kv, kr, pos.x, pos.y, size.x, size.y, thicc, kolor);
}
// -------------------------------------
void kross_kamera_rect_stroker(Kanvas* kv, Kamera* kr, Rekt rect, size_t thicc, Kolor kolor)
{
  kross_kamera_rect_stroke(kv, kr, rect.x, rect.y, rect.w, rect.h, thicc, kolor);
}
// -------------------------------------
void kross_kamera_circle(Kanvas* kv, Kamera* kr, int cx, int cy, size_t r, Kolor kolor)
{
  Vek2 screen = kross_math_vek2_kamera(kr, (Vek2){cx, cy});
  int screen_r = r*kr->zoom;
  kross_kanvas_circlev(kv, screen, screen_r, kolor);
}
// -------------------------------------
void kross_kamera_circlev(Kanvas* kv, Kamera* kr, Vek2 center, size_t r, Kolor kolor)
{
  kross_kamera_circle(kv, kr, center.x, center.y, r, kolor);
}
// -------------------------------------
void kross_kamera_circle_stroke(Kanvas* kv, Kamera* kr, int cx, int cy, size_t r, size_t thicc, Kolor kolor)
{
  Vek2 screen = kross_math_vek2_kamera(kr, (Vek2){cx, cy});
  int screen_r = r*kr->zoom;
  int screen_thicc = thicc*kr->zoom;
  kross_kanvas_circle_strokev(kv, screen, screen_r, screen_thicc, kolor);
}
// -------------------------------------
void kross_kamera_circle_strokev(Kanvas* kv, Kamera* kr, Vek2 center, size_t r, size_t thicc, Kolor kolor)
{
  kross_kamera_circle_stroke(kv, kr, center.x, center.y, r, thicc, kolor);
}
// -------------------------------------
void kross_kamera_triangle(Kanvas* kv, Kamera* kr, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kolor)
{
  Vek2 screen1 = kross_math_vek2_kamera(kr, v0);
  Vek2 screen2 = kross_math_vek2_kamera(kr, v1);
  Vek2 screen3 = kross_math_vek2_kamera(kr, v2);
  kross_kanvas_triangle(kv, screen1, screen2, screen3, kolor);
}
// -------------------------------------
void kross_kamera_triangle_tricolor(Kanvas* kv, Kamera* kr, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kl0, Kolor kl1, Kolor kl2)
{
  Vek2 screen1 = kross_math_vek2_kamera(kr, v0);
  Vek2 screen2 = kross_math_vek2_kamera(kr, v1);
  Vek2 screen3 = kross_math_vek2_kamera(kr, v2);
  kross_kanvas_triangle_tricolor(kv, screen1, screen2, screen3, kl0, kl1, kl2);
}
// -------------------------------------
void kross_kamera_triangle_stroke(Kanvas* kv, Kamera* kr, Vek2 v0, Vek2 v1, Vek2 v2, size_t thicc, Kolor kolor)
{
  kross_kamera_line(kv, kr, v0.x, v0.y, v1.x, v1.y, thicc, kolor);
  kross_kamera_line(kv, kr, v1.x, v1.y, v2.x, v2.y, thicc, kolor);
  kross_kamera_line(kv, kr, v2.x, v2.y, v0.x, v0.y, thicc, kolor);
}
// -------------------------------------
void kross_kamera_grid(Kanvas* kv, Kamera* kr, int x, int y, size_t cols, size_t rows, size_t gap, size_t thicc, Kolor kolor)
{
  Vek2 screen = kross_math_vek2_kamera(kr, (Vek2){x, y});
  size_t screen_thicc = thicc*kr->zoom;
  size_t screen_gap   = gap*kr->zoom;
  kross_kanvas_grid(kv, screen.x, screen.y, cols, rows, screen_gap, screen_thicc, kolor);
}
// -------------------------------------
void kross_kamera_gridv(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 colrow, size_t gap, size_t thicc, Kolor kolor)
{
  kross_kamera_grid(kv, kr, pos.x, pos.y, colrow.x, colrow.y, gap, thicc, kolor);
}
// -------------------------------------
void kross_kamera_board(Kanvas* kv, Kamera* kr, int x, int y, size_t cols, size_t rows, size_t gap, Kolor kl0, Kolor kl1)
{
  Vek2 screen = kross_math_vek2_kamera(kr, (Vek2){x, y});
  size_t screen_gap = gap*kr->zoom;
  kross_kanvas_board(kv, screen.x, screen.y, cols, rows, screen_gap, kl0, kl1);
}
// -------------------------------------
void kross_kamera_boardv(Kanvas* kv, Kamera* kr, Vek2 pos, Vek2 colrow, size_t gap, Kolor kl0, Kolor kl1)
{
  kross_kamera_board(kv, kr, pos.x, pos.y, colrow.x, colrow.y, gap, kl0, kl1);
}
// -------------------------------------
// Alright let me rant a little bit about Windows here.
// At first, when the library started, I was using OpenGL 3.2.
// When the time came to release it, I wanted it to be cross-platform,
// So it would work for Linux, MacOS, Windows, etc.
// Linux and Mac are not picky, whatever OpenGL you use, theyre okay with.
// Windows on the other hand, only exposes OpenGL 1.1 out of the box.
// The pea-brains at Microsoft literally decided to freeze OpenGL support completely.
// To use OpenGL 3.2 on Windows, I would need to use a tool like GLAD.
// -------------------------------------
// Now, why GLAD? Because, Windows does not let you statically link modern OpenGL functions.
// They arent in the headers, instead, the graphics driver has them hidden away.
// To get them, there are two ways:
// 1. Go insane and manually ask the driver for each functions memory address.
// 2. Use GLAD, guess where the name comes from.
// Now between these two options, I decided to go for the third, using OpenGL 1.1.
// Which is the only version Windows is okay with out of the box.
// I LITERALLY HAD TO FIND OPENGL 1.1 CODE ONLINE TO COPY BECAUSE I KNOW JACK ABOUT OPENGL.
// ALRIGHT? YOU KNOW WHAT THAT FEELS LIKE?
// IT FEELS LIKE PERFORMING DARK NECROMANCY ON A 30 YEAR OLD API CORPSE USING CHATGPT AS MY SPELL BOOK.
// (Just kidding, I used AI for this part. Yes, Im also a pea-brain,
// I remember struggling on the for loop which fills the screen with two different colors).
// To close it off, never read this section, its just boring outdated OpenGL code.
// -------------------------------------
GLFWwindow* window;
unsigned int canvas_tex_id;
double last_frame_time;
double target_fps_time = 0.0;
float delta_time = 0.0f;
float logical_w, logical_h;
bool keys[512] = { false };
bool keys_just[512] = { false };
bool keys_released[512] = { false };
bool mouse_buttons[8] = { false };
bool mouse_just[8] = { false };
bool mouse_released[8] = { false };
// -------------------------------------
float kross_delta_time(void)
{
  return delta_time;
}
// -------------------------------------
void kross_target_fps(size_t fps)
{
  if (fps > 0) target_fps_time = 1.0 / (double)fps;
  else         target_fps_time = 0.0;
}
// -------------------------------------
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  (void)window;
  (void)scancode;
  (void)mods;

  if (key < 0 || key >= 512) return;

  if (action == GLFW_PRESS)
  {
    keys[key] = true;
    keys_just[key] = true;
    keys_released[key] = false;
  }
  else if (action == GLFW_RELEASE)
  {
    keys[key] = false;
    keys_released[key] = true;
  }
}
// -------------------------------------
static void mouse_button_callback(int button, int action)
{
  if (button < 0 || button >= 8) return;

  if (action == GLFW_PRESS)
  {
    mouse_buttons[button]  = true;
    mouse_just[button]     = true;
    mouse_released[button] = false;
  }
  else if (action == GLFW_RELEASE)
  {
    mouse_buttons[button]  = false;
    mouse_released[button] = true;
  }
}
// -------------------------------------
bool kross_input_down(KInput input)
{
  if (input < 0)                    return false;
  if (input <= KROSS_INPUT_MOUSE_8) return mouse_buttons[input];
  if (input < 512)                  return keys[input];

  return false;
}
// -------------------------------------
bool kross_input_once(KInput input)
{
  if (input < 0)                    return false;
  if (input <= KROSS_INPUT_MOUSE_8) return mouse_just[input];
  if (input < 512)                  return keys_just[input];
  return false;
}
// -------------------------------------
bool kross_input_up(KInput input)
{
  if (input < 0)                    return false;
  if (input <= KROSS_INPUT_MOUSE_8) return mouse_released[input];
  if (input < 512)                  return keys_released[input];

  return false;
}
// -------------------------------------
Vek2 kross_input_mouse_pos(void)
{
  if (!window) return (Vek2){0.0f, 0.0f};
  
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  return (Vek2){(float)xpos, (float)ypos};
}
// -------------------------------------
void kross_init_gpu_bridge(Kanvas* k)
{
  glGenTextures(1, &canvas_tex_id);
  glBindTexture(GL_TEXTURE_2D, canvas_tex_id);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, k->w, k->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, k->pixels);

  glEnable(GL_TEXTURE_2D);
}
// -------------------------------------
static void glfw_mouse_bridge(GLFWwindow* win, int button, int action, int mods)
{
  (void)win;
  (void)mods;
  mouse_button_callback(button, action);
}
// -------------------------------------
void kross_window_init(Kanvas *k, const char* title)
{
  if (!glfwInit()) return;

#ifdef __APPLE__
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_TRUE);
#endif

  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  logical_w = (float)k->w;
  logical_h = (float)k->h;

  window = glfwCreateWindow(k->w, k->h, title, NULL, NULL);

  if (!window) { glfwTerminate(); return; }

  glfwSetWindowSize(window, k->w, k->h);
  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetMouseButtonCallback(window, glfw_mouse_bridge);
  glfwSwapInterval(0);

  kross_init_gpu_bridge(k);
  last_frame_time = glfwGetTime();
}
// -------------------------------------
void kross_kanvas_start(Kanvas* kv)
{
  if (!window) return;

  (void)kv;

  glfwPollEvents();

  double current_time = glfwGetTime();
  delta_time = (float)(current_time - last_frame_time);
  last_frame_time = current_time;

  int fb_w, fb_h;
  glfwGetFramebufferSize(window, &fb_w, &fb_h);
  glViewport(0, 0, fb_w, fb_h);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
// -------------------------------------
void kross_kanvas_stop(Kanvas* kv)
{
  if (!window) return;

  memset(keys_just, 0, sizeof(keys_just));
  memset(keys_released, 0, sizeof(keys_released));
  memset(mouse_just, 0, sizeof(mouse_just));
  memset(mouse_released, 0, sizeof(mouse_released));

  glBindTexture(GL_TEXTURE_2D, canvas_tex_id);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, kv->w, kv->h, GL_RGBA, GL_UNSIGNED_BYTE, kv->pixels);

  glColor3f(1.0f, 1.0f, 1.0f);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f( 1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f( 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, -1.0f);
  glEnd();

  glfwSwapBuffers(window);

  if (target_fps_time > 0.0)
  {
    double wait_until = last_frame_time + target_fps_time;
    while (glfwGetTime() < wait_until)
    {
      double time_left = wait_until - glfwGetTime();
      if (time_left > 0.0)
      {
        glfwWaitEventsTimeout(time_left); 
      }
    }
  }
}
// -------------------------------------
bool kross_window_should_close(void)
{
  if (!window) return true;
  return glfwWindowShouldClose(window);
}
// -------------------------------------
void kross_window_free(void)
{
  if (window)
  {
    glfwDestroyWindow(window);
    window = NULL;
  }
  glfwTerminate();
}
// -------------------------------------
Kolor kross_kolor_scale(Kolor kolor, float scale)
{
  if (scale <= 1) return kolor;
  uint8_t scaled_r = (kolor.r*scale <= 255) ? kolor.r*scale : 255;
  uint8_t scaled_g = (kolor.g*scale <= 255) ? kolor.g*scale : 255;
  uint8_t scaled_b = (kolor.b*scale <= 255) ? kolor.b*scale : 255;
  return(Kolor){scaled_r, scaled_g, scaled_b, kolor.a};
}
// -------------------------------------
Kolor kross_kolor_blend(Kolor kl0, Kolor kl1)
{
  if (kl0.a == 255) return kl0;
  if (kl0.a == 0)   return kl1;

  uint8_t r = (uint8_t)((kl0.r*kl0.a + kl1.r*(255-kl0.a)) >> 8);
  uint8_t g = (uint8_t)((kl0.g*kl0.a + kl1.g*(255-kl0.a)) >> 8);
  uint8_t b = (uint8_t)((kl0.b*kl0.a + kl1.b*(255-kl0.a)) >> 8);
  uint8_t a = (uint8_t)(kl0.a +       (kl1.a*(255-kl0.a)  >> 8));
  
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kross_kolor_lerp(Kolor start, Kolor end, float t)
{
  uint8_t r = (uint8_t)kross_math_lerp((float)start.r, (float)end.r, t);
  uint8_t g = (uint8_t)kross_math_lerp((float)start.g, (float)end.g, t);
  uint8_t b = (uint8_t)kross_math_lerp((float)start.b, (float)end.b, t);
  uint8_t a = (uint8_t)kross_math_lerp((float)start.a, (float)end.a, t);
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kross_kolor_cerp(Kolor kl0, Kolor kl1, Kolor kl2, Kolor kl3, float t)
{
  //--------------
  float r = kross_math_cerp((float)kl0.r, (float)kl1.r, (float)kl2.r, (float)kl3.r, t);
  float g = kross_math_cerp((float)kl0.g, (float)kl1.g, (float)kl2.g, (float)kl3.g, t);
  float b = kross_math_cerp((float)kl0.b, (float)kl1.b, (float)kl2.b, (float)kl3.b, t);
  float a = kross_math_cerp((float)kl0.a, (float)kl1.a, (float)kl2.a, (float)kl3.a, t);
  //--------------
  r = kross_math_clampf(r, 0.0f, 255.0f);
  g = kross_math_clampf(g, 0.0f, 255.0f);
  b = kross_math_clampf(b, 0.0f, 255.0f);
  a = kross_math_clampf(a, 0.0f, 255.0f);
  //--------------
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kross_kolor_invert(Kolor kolor) 
{
  uint8_t xor_r = kolor.r ^= 255;
  uint8_t xor_g = kolor.g ^= 255;
  uint8_t xor_b = kolor.b ^= 255;
  return (Kolor){xor_r, xor_g, xor_b, kolor.a};
}
// -------------------------------------
Kolor kross_kolor_grayscale(Kolor kolor)
{
  float gray_r = (float)kolor.r*0.299f;
  float gray_g = (float)kolor.g*0.587f;
  float gray_b = (float)kolor.b*0.114f;
  float gray = gray_r+gray_g+gray_b;
  return (Kolor){(uint8_t)gray, (uint8_t)gray, (uint8_t)gray, kolor.a};
}
// -------------------------------------
bool kross_kolor_compare_rgb(Kolor kl0, Kolor kl1)
{
  return (kl0.r == kl1.r && kl0.g == kl1.g && kl0.b == kl1.b);
}
// -------------------------------------
bool kross_kolor_compare_rgba(Kolor kl0, Kolor kl1)
{
  return (kl0.r == kl1.r && kl0.g == kl1.g && kl0.b == kl1.b && kl0.a == kl1.a);
}
// -------------------------------------
Kolor kross_kolor_from_hex(uint32_t hex)
{
  uint8_t r = (hex >> 24)&0xFF;
  uint8_t g = (hex >> 16)&0xFF;
  uint8_t b = (hex >> 8)&0xFF;
  uint8_t a = hex;

  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kross_kolor_from_hsv(float h, float s, float v)
{
  // Credit: Alvy Ray Smith
  // --------------
  h = kross_math_clampf(h, 0.0f, 1.0f);
  s = kross_math_clampf(s, 0.0f, 1.0f);
  v = kross_math_clampf(v, 0.0f, 1.0f);
  
  h *= 360.0f;
  
  float M = 255.0f * v;
  float m = M * (1.0f-s);
  float z = (M-m) * (1.0f-fabs(fmodf(h/60.0f, 2.0f) - 1.0f));
  // --------------
  if (h < 60)       return (Kolor){(uint8_t)M, (uint8_t)(z + m), (uint8_t)m, 255};
  else if (h < 120) return (Kolor){(uint8_t)(z + m), (uint8_t)M, (uint8_t)m, 255};
  else if (h < 180) return (Kolor){(uint8_t)m, (uint8_t)M, (uint8_t)(z + m), 255};
  else if (h < 240) return (Kolor){(uint8_t)m, (uint8_t)(z + m), (uint8_t)M, 255};
  else if (h < 300) return (Kolor){(uint8_t)(z + m), (uint8_t)m, (uint8_t)M, 255};
  else              return (Kolor){(uint8_t)M, (uint8_t)m, (uint8_t)(z + m), 255};
}
// -------------------------------------
Kolor kross_kolor_from_cmyk(float c, float m, float y, float k)
{
  // Credit: James Clerk Maxwell / Albert Henry
  // --------------
  c = kross_math_clampf(c, 0.0f, 1.0f);
  m = kross_math_clampf(m, 0.0f, 1.0f);
  y = kross_math_clampf(y, 0.0f, 1.0f);
  k = kross_math_clampf(k, 0.0f, 1.0f);
  // --------------
  uint8_t r = (uint8_t)(255.0f * (1.0f - c) * (1.0f - k));
  uint8_t g = (uint8_t)(255.0f * (1.0f - m) * (1.0f - k));
  uint8_t b = (uint8_t)(255.0f * (1.0f - y) * (1.0f - k));
  // --------------
  return (Kolor){r, g, b, 255};
}
// -------------------------------------
// Quick yap sesh.
// The file encoders/decoders are not commented yet.
// Im waiting to implement QOI and then comment everything.
// -------------------------------------
void kross_file_ppm_write(Kanvas* kv, const char* path)
{
  // Credit: "Jeff Poskanzer" for creating the file format.
  //--------------
  FILE* f = fopen(path, "wb");
  if (!f) return;
  //--------------
  fprintf(f, "P6\n%u %u\n255\n", kv->w, kv->h);
  //--------------
  for (size_t i = 0; i < kv->w*kv->h; ++i)
  {
    fputc(kv->pixels[i].r, f);
    fputc(kv->pixels[i].g, f);
    fputc(kv->pixels[i].b, f);
  }
  //--------------
  fclose(f);
  //--------------
  printf("\n------ FILE INFO ------\n");
  printf("Operation:  Write\n");
  printf("Path     :  %s\n", path);
  printf("Type     :  PPM-P6\n");
  printf("Size     :  %ux%u\n", kv->w, kv->h);
  printf("---- FILE INFO END ----\n");
  //--------------
}
// -------------------------------------
Kanvas* kross_file_ppm_read(const char* path)
{
  //--------------
  FILE* f = fopen(path, "rb");
  if (!f) return NULL;
  //--------------
  char format[3] = {0};
  if (fscanf(f, "%2s", format) != 1) { fclose(f); return NULL; }
  //--------------
  int kv_width = 0, kv_height = 0, kl_maxval = 0;
  if (fscanf(f, "%d %d %d", &kv_width, &kv_height, &kl_maxval) != 3)
  { fclose(f); return NULL; }
  //--------------
  Kanvas* kv = kv_init(kv_width, kv_height);
  int r = 0, g = 0, b = 0;
  fgetc(f);
  //--------------
  if (strcmp("P6", format) == 0)
  {
    for (int i = 0; i < kv_width*kv_height; ++i)
    {
      //--------------
      r = fgetc(f);
      g = fgetc(f);
      b = fgetc(f);
      //--------------
      if (r == EOF || g == EOF || b == EOF) break;
      kv->pixels[i] = (Kolor){(uint8_t)r, (uint8_t)g, (uint8_t)b, (uint8_t)kl_maxval};
      //--------------
    }
  }
  //--------------
  fclose(f);
  //--------------
  printf("------ FILE INFO ------\n");
  printf("Operation:  Read\n");
  printf("Path     :  %s\n", path);
  printf("Type     :  PPM-%s\n", format);
  printf("Size     :  %dx%d\n", kv_width, kv_height);
  printf("---- FILE INFO END ----\n");
  return kv;
  //--------------
}
// -------------------------------------
void kross_file_tga_write(Kanvas* kv, const char* path)
{
  // Credit: "Truevision Inc" for creating the file format.
  //--------------
  FILE* f = fopen(path, "wb");
  if (!f) return;

  fputc(0, f);
  fputc(0, f);
  fputc(10, f);
  fputc(0, f);
  fputc(0, f);
  fputc(0, f);
  fputc(0, f);
  fputc(0, f);
  fputc(0, f);
  fputc(0, f);
  fputc(0, f);
  fputc(kv->w & 0xFF, f);
  fputc((kv->w >> 8) & 0xFF, f);
  fputc(kv->h & 0xFF, f);
  fputc((kv->h >> 8) & 0xFF, f);
  fputc(24, f);
  fputc(0x20, f);

  int pixel_count = kv->w*kv->h;
  int i = 0;
  
  while (i < pixel_count )
  {
    int run = 1;

    while (i+run < pixel_count && run < 128 && kross_kolor_compare_rgb(kv->pixels[i], kv->pixels[i+run])) ++run;

    if (run >= 2)
    {
      fputc(0x80 | (run-1), f);
      fputc(kv->pixels[i].b, f);
      fputc(kv->pixels[i].g, f);
      fputc(kv->pixels[i].r, f);
      i += run;
    }
    else
    {
      int start = i;
      int count = 1;

      while (start+count < pixel_count && count < 128)
      {
        if (start+count+1 < pixel_count)
        {
          Kolor a = kv->pixels[start+count];
          Kolor b = kv->pixels[start+count+1];

          if (kross_kolor_compare_rgb(a, b)) break;
        }
        ++count;
      }

      fputc(count-1, f);
      for (int j = 0; j < count; ++j)
      {
        fputc(kv->pixels[start+j].b, f);
        fputc(kv->pixels[start+j].g, f);
        fputc(kv->pixels[start+j].r, f);
      }

      i += count;
    }
  }

  fclose(f);
}
// -------------------------------------
Kanvas* kross_file_tga_read(const char* path)
{
  FILE* f = fopen(path, "rb");
  if (!f) return NULL;

  uint8_t idlength      = fgetc(f);
  uint8_t colormap      = fgetc(f);
  uint8_t datatype_code = fgetc(f);

  fseek(f, 5, SEEK_CUR);
  fseek(f, 4, SEEK_CUR);

  uint16_t width      = fgetc(f) | (fgetc(f) << 8);
  uint16_t height     = fgetc(f) | (fgetc(f) << 8);
  uint8_t  bpp        = fgetc(f);
  uint8_t  descriptor = fgetc(f);

  Kanvas* kv = kv_init((size_t)width, (size_t)height);
  size_t pixel_count = kv->w*kv->h;

  if (datatype_code == 2)
  {
    if (bpp == 32)
    {
      for (size_t i = 0; i < pixel_count; ++i)
      {
        int b = fgetc(f);
        int g = fgetc(f);
        int r = fgetc(f);
        int a = fgetc(f);
        if (b == EOF && g == EOF && r == EOF && a == EOF) break;
        kv->pixels[i] = (Kolor){(uint8_t)r, (uint8_t)g, (uint8_t)b, (uint8_t)a};
      }
    }
    else if (bpp == 24)
    {
      for (size_t i = 0; i < pixel_count; ++i)
      {
        int b = fgetc(f);
        int g = fgetc(f);
        int r = fgetc(f);
        if (b == EOF || g == EOF || r == EOF) break;
        kv->pixels[i] = (Kolor){(uint8_t)r, (uint8_t)g, (uint8_t)b, (uint8_t)255};
      }
    }
    else if (bpp == 16)
    {
      for (size_t i = 0; i < pixel_count; ++i)
      {
        int lo = fgetc(f);
        int hi = fgetc(f);
        if (lo == EOF || hi == EOF) break;
        uint16_t px = (uint16_t)lo | ((uint16_t)hi << 8);
        uint8_t b = ( px & 0x1F)           << 3;
        uint8_t g = ((px >> 5  ) & 0x1F)   << 3;
        uint8_t r = ((px >> 10 ) & 0x1F)   << 3;
        kv->pixels[i] = (Kolor){r, g, b, 255};
      }
    }
  }
  else if (datatype_code == 10)
  {
    size_t i = 0;

    while (i < pixel_count)
    {
      uint8_t header = fgetc(f);
      int count = (header&0x7F) + 1;

      if (header & 0x80)
      {
        uint8_t b = fgetc(f);
        uint8_t g = fgetc(f);
        uint8_t r = fgetc(f);
        uint8_t a = (bpp == 32) ? fgetc(f) : 255;
        for (int j = 0; j < count; ++j) kv->pixels[i++] = (Kolor){r, g, b, a};
      }
      else
      {
        for (int j = 0; j < count; ++j)
        {
          uint8_t b = fgetc(f);
          uint8_t g = fgetc(f);
          uint8_t r = fgetc(f);
          uint8_t a = (bpp == 32) ? fgetc(f) : 255;
          kv->pixels[i++] = (Kolor){r, g, b, a};
        }
      }
    }
  }

  fclose(f);
  return kv;
}
// -------------------------------------
Vek2 kross_math_vek2_zero(void)
{
  return (Vek2){0.0f, 0.0f};
}
// -------------------------------------
Vek2 kross_math_vek2_one(void)
{
  return (Vek2){1.0f, 1.0f};
}
// -------------------------------------
Vek2 kross_math_vek2_add(Vek2 v0, Vek2 v1)
{
  return (Vek2){v0.x+v1.x, v0.y+v1.y};
}
// -------------------------------------
Vek2 kross_math_vek2_addval(Vek2 v0, float value)
{
  return (Vek2){v0.x+value, v0.y+value};
}
// -------------------------------------
Vek2 kross_math_vek2_sub(Vek2 v0, Vek2 v1)
{
  return (Vek2){v0.x-v1.x, v0.y-v1.y};
}
// -------------------------------------
Vek2 kross_math_vek2_subval(Vek2 v0, float value)
{
  return (Vek2){v0.x-value, v0.y-value};
}
// -------------------------------------
Vek2 kross_math_vek2_scale(Vek2 v0, float scalar)
{
  return (Vek2){v0.x*scalar, v0.y*scalar};
}
// -------------------------------------
Vek2 kross_math_vek2_rotate(Vek2 v0, Vek2 center, float angle)
{
  float cos_a   = cosf(angle);
  float sin_a   = sinf(angle);
  float trans_x = v0.x-center.x;
  float trans_y = v0.y-center.y;
  float rot_x   = trans_x*cos_a-trans_y*sin_a;
  float rot_y   = trans_y*cos_a-trans_x*sin_a;
  return (Vek2){rot_x+center.x, rot_y+center.y};
}
// -------------------------------------
float kross_math_vek2_len(Vek2 v0)
{
  return sqrtf(pow(v0.x, 2)+pow(v0.y, 2));
}
// -------------------------------------
Vek2 kross_math_vek2_min(Vek2 v0, Vek2 v1)
{
  float min_x = KROSS_MIN(v0.x, v1.x);
  float min_y = KROSS_MIN(v0.y, v1.y);
  return (Vek2){min_x, min_y};
}
// -------------------------------------
Vek2 kross_math_vek2_max(Vek2 v0, Vek2 v1)
{
  float max_x = KROSS_MAX(v0.x, v1.x);
  float max_y = KROSS_MAX(v0.y, v1.y);
  return (Vek2){max_x, max_y};
}
// -------------------------------------
Vek2 kross_math_vek2_nrm(Vek2 v0)
{
  float vek_len = kross_math_vek2_len(v0);
  float nrm_x = v0.x/vek_len;
  float nrm_y = v0.y/vek_len;
  return (Vek2){nrm_x, nrm_y};
}
// -------------------------------------
Vek2 kross_math_vek2_lerp(Vek2 v0, Vek2 v1, float t)
{
  float lerp_x = kross_math_lerp(v0.x, v1.x, t);
  float lerp_y = kross_math_lerp(v0.y, v1.y, t);
  return (Vek2){lerp_x, lerp_y};
}
// -------------------------------------
Vek2 kross_math_vek2_kamera(Kamera* kr, Vek2 world)
{
  int screenx = (world.x-kr->target.x)*kr->zoom+kr->target_dst.x;
  int screeny = (world.y-kr->target.y)*kr->zoom+kr->target_dst.y;
  return (Vek2){screenx, screeny};
}
// -------------------------------------
Vek3 kross_math_vek3_zero(void)
{
  return (Vek3){0.0f, 0.0f, 0.0f};
}
// -------------------------------------
Vek3 kross_math_vek3_one(void)
{
  return (Vek3){1.0f, 1.0f, 1.0f};
}
// -------------------------------------
Vek3 kross_math_vek3_add(Vek3 v0, Vek3 v1)
{
  return (Vek3){v0.x+v1.x, v0.y+v1.y, v0.z+v1.z};
}
// -------------------------------------
Vek3 kross_math_addval(Vek3 v0, float value)
{
  return (Vek3){v0.x+value, v0.y+value, v0.z+value};
}
// -------------------------------------
Vek3 kross_math_vek3_sub(Vek3 v0, Vek3 v1)
{
  return (Vek3){v0.x-v1.x, v0.y-v1.y, v0.z-v1.z};
}
// -------------------------------------
Vek3 kross_math_vek3_subval(Vek3 v0, float value)
{
  return (Vek3){v0.x-value, v0.y-value, v0.z-value};
}
// -------------------------------------
Vek3 kross_math_vek3_scale(Vek3 v0, float scalar)
{
  return (Vek3){v0.x*scalar, v0.y*scalar, v0.z*scalar};
}
// -------------------------------------
float kross_math_vek3_dot(Vek3 v0, Vek3 v1)
{
  return v0.x*v1.x+v0.y*v1.y+v0.z*v1.z;
}
// -------------------------------------
float kross_math_vek3_len(Vek3 v0)
{
  return sqrtf(pow(v0.x, 2)+pow(v0.y, 2)+pow(v0.z, 2));
}
// -------------------------------------
Vek3 kross_math_vek3_min(Vek3 v0, Vek3 v1)
{
  float min_x = KROSS_MIN(v0.x, v1.x);
  float min_y = KROSS_MIN(v0.y, v1.y);
  float min_z = KROSS_MIN(v0.z, v1.z);
  return (Vek3){min_x, min_y, min_z};
}
// -------------------------------------
Vek3 kross_math_vek3_max(Vek3 v0, Vek3 v1)
{
  float max_x = KROSS_MAX(v0.x, v1.x);
  float max_y = KROSS_MAX(v0.y, v1.y);
  float max_z = KROSS_MAX(v0.z, v1.z);
  return (Vek3){max_x, max_y, max_z};
}
// -------------------------------------
Vek3 kross_math_vek3_nrm(Vek3 v0)
{
  float vek_len = kross_math_vek3_len(v0);
  float nrm_x = v0.x/vek_len;
  float nrm_y = v0.y/vek_len;
  float nrm_z = v0.z/vek_len;
  return (Vek3){nrm_x, nrm_y, nrm_z};
}
// -------------------------------------
Vek3 kross_math_vek3_cross(Vek3 v0, Vek3 v1)
{
  return (Vek3){v0.y*v1.z-v0.z*v1.y, v0.z*v1.x-v0.x*v1.z, v0.x*v1.y-v0.y*v1.x};
}
// -------------------------------------
Vek3 kross_math_vek3_lerp(Vek3 v0, Vek3 v1, float t)
{
  float lerp_x = kross_math_lerp(v0.x, v1.x, t);
  float lerp_y = kross_math_lerp(v0.y, v1.y, t);
  float lerp_z = kross_math_lerp(v0.z, v1.z, t);
  return (Vek3){lerp_x, lerp_y, lerp_z};
}
// -------------------------------------
Vek2 kross_math_vek2_screen2norm(Vek2 kv, Vek2 screen)
{
  float normx = (screen.x+1)/2 * kv.x;
  float normy = (1-(screen.y+1)/2) * kv.x;
  return (Vek2){normx, normy};
}
// -------------------------------------
Vek2 kross_math_vek2_normal2screen(Vek2 normal, Vek2 kv)
{
  float screenx = normal.x*2 / kv.x;
  float screeny = (1+normal.y)*2 / kv.y;
  return (Vek2){screenx, screeny};
}
// -------------------------------------
Vek2 kross_math_vek2_cartesian2screen(Vek2 cartesian, Vek2 kv, float scale)
{
  float screenx = cartesian.x*scale+kv.x/2;
  float screeny = kv.y/2-cartesian.y*scale;
  return (Vek2){screenx, screeny};
}
// -------------------------------------
Vek2 kross_math_vek2_screen2cartesian(Vek2 screen, Vek2 kv, float scale)
{
  float cartesianx = (screen.x-kv.x/2)/scale;
  float cartesiany = (-screen.y+kv.y/2)/scale;
  return (Vek2){cartesianx, cartesiany};
}
// -------------------------------------
Vek2 kross_math_vek2_screen2uv(Vek2 screen, Vek2 kv)
{
  float uv_x = screen.x/(float)kv.x;
  float uv_y = screen.y/(float)kv.y;
  return (Vek2){uv_x, uv_y};
}
// -------------------------------------
Vek2 kross_math_vek2_uv2screen(Vek2 uv, Vek2 kv)
{
  float screen_x = uv.x*(kv.x-1);
  float screen_y = uv.y*(kv.y-1);
  return (Vek2){screen_x, screen_y};
}
// -------------------------------------
Vek2 kross_math_vek3_project(Vek3 v0)
{
  return (Vek2){v0.x/v0.z, v0.y/v0.z};
}
// -------------------------------------
float kross_math_vek2_dot(Vek2 v0, Vek2 v1)
{
  return v0.x*v1.x+v0.y*v1.y;
}
// -------------------------------------
float  kross_math_vek2_cross(Vek2 v0, Vek2 v1)
{
  return (v0.x*v1.y)-(v0.y*v1.x);
}
// -------------------------------------
Vek3 kross_math_vek3_translate_x(Vek3 v0, float dx)
{
  return (Vek3){v0.x+dx, v0.y, v0.z};
}
// -------------------------------------
Vek3 kross_math_vek3_translate_y(Vek3 v0, float dy)
{
  return (Vek3){v0.x, v0.y+dy, v0.z};
}
// -------------------------------------
Vek3 kross_math_vek3_translate_z(Vek3 v0, float dz)
{
  return (Vek3){v0.x, v0.y, v0.z+dz};
}
// -------------------------------------
Vek3 kross_math_vek3_rotate_y(Vek3 v0, float angle)
{
  float cosa = cosf(angle);
  float sina = sinf(angle);
  return (Vek3){ v0.x*cosa - v0.z*sina, v0.y, v0.x*sina + v0.z*cosa };
}
// -------------------------------------
Vek3 kross_math_vek3_rotate_x(Vek3 v0, float angle)
{
  float cos_a = cosf(angle);
  float sin_a = sinf(angle);
  return (Vek3){v0.x, v0.y*cos_a - v0.z*sin_a, v0.y*sin_a + v0.z*cos_a};
}
// -------------------------------------
Vek2 kross_math_bezier_quad(Vek2 p1, Vek2 control_p, Vek2 p2, float t)
{
  Vek2 a = kross_math_vek2_lerp(p1, control_p, t);
  Vek2 b = kross_math_vek2_lerp(control_p, p2, t);
  Vek2 lerped = kross_math_vek2_lerp(a, b, t);
  return lerped;
}
// -------------------------------------
Vek2 kross_math_bezier_cube(Vek2 p1, Vek2 control_p1, Vek2 control_p2, Vek2 p2, float t)
{
  Vek2 a       = kross_math_vek2_lerp(p1, control_p1, t);
  Vek2 b       = kross_math_vek2_lerp(control_p1, control_p2, t);
  Vek2 c       = kross_math_vek2_lerp(control_p2, p2, t);
  Vek2 lerp_a = kross_math_vek2_lerp(a, b, t);
  Vek2 lerp_b = kross_math_vek2_lerp(b, c, t);
  Vek2 lerped = kross_math_vek2_lerp(lerp_a, lerp_b, t);
  return lerped;
}
// -------------------------------------
float kross_math_lerp(float start, float end, float t)
{
  return start+(end-start)*t;
}
// -------------------------------------
float kross_math_cerp(float x0, float x1, float x2, float x3, float t)
{
  float a = (3.0f*x1-3.0f*x2+x3-x0)/2.0f;
  float b = (2.0f*x0-5.0f*x1+4.0f*x2-x3)/2.0f;
  float c = (x2-x0)/2.0f;
  float d = x1;
  return ((a*t+b)*t+c)*t+d;
}
// -------------------------------------
static float kross_math_noise_hash_2d(int x, int y)
{
  // Very well known integer hash (slightly modified Squirrel3).
  uint32_t hash = (uint32_t)x;
  hash ^= (uint32_t)y*0x27d4eb2d;
  hash = (hash^61)^(hash >> 16);
  hash += hash << 3;
  hash ^= hash >> 4;
  hash *= 0x27d4eb2d;
  hash ^= hash >> 15;

  // Scaling the 32-bit unsigned int to a float between 0.0f and 1.0f.
  return (float)hash/(float)0xFFFFFFFF;
}
// -------------------------------------
static Vek2 kross_math_noise_hash_gradient_2d(int x, int y)
{
  float rand_val = kross_math_noise_hash_2d(x, y);
  float theta    = rand_val*2*KROSS_PI;
  float gradient_x = cosf(theta);
  float gradient_y = sinf(theta);
  return (Vek2){gradient_x, gradient_y};
}
// -------------------------------------
static float kross_math_noise_hash_3d(int x, int y, int z)
{
  uint32_t hash = (uint32_t)x;
  hash ^= (uint32_t)y*0x27d4eb2d;
  hash ^= (uint32_t)z*0x33b4d2ca;
  hash  = (hash^61)^(hash >> 16);
  hash += hash << 3;
  hash ^= hash >> 4;
  hash *= 0x27d4eb2d;
  hash ^= hash >> 15;

  // Scale the 32-bit unsigned int to a float between 0.0f and 1.0f.
  return (float)hash/(float)0xFFFFFFFF;
}
// -------------------------------------
static Vek3 kross_math_noise_hash_gradient_3d(int x, int y, int z)
{
  float rand_val0    = kross_math_noise_hash_3d(x, y, z);
  float rand_val1    = kross_math_noise_hash_3d(x+12345, y+67890, z+54321);
  float theta        = acosf(rand_val0*2.0f-1.0f);
  float phi          = rand_val1*2.0f*KROSS_PI;
  float gradient_x   = cosf(phi)*sinf(theta);
  float gradient_y   = sinf(phi)*sinf(theta);
  float gradient_z   = cosf(theta);
  return (Vek3){gradient_x, gradient_y, gradient_z};
}
// -------------------------------------
static float kross_math_noise_2d_value(float x, float y)
{
  // Credit: Computer Graphics community.
  //--------------
  // We are getting the neighbors of the x/y pixels.
  // Say x: 255.5, x0 is 255, x1 is 256.
  // y: 345.75, y0 is 345, y1 is 346.
  // We can then use those values to generate 4 random points.
  // These 4 random points, represent a rectangle.
  int x0 = floorf(x);
  int y0 = floorf(y);
  int x1 = x0+1;
  int y1 = y0+1;
  //--------------
  // Now this is where it gets good.
  // Why do we need u/v, what even is u/v?
  // UV coordinates always range from 0-1.
  // See where this is going? LERP TIME.
  // We get x which is 255.5 and subtract from it x0 which is 255.
  // What are we left with? 0.5.
  // That 0.5 means we are horizontally halfway (50%) inside this specific pixel.
  // Same thing for y, we get 345.75-345 = 0.75.
  // This means we are 3/4 (75%) of the way to the end vertically.
  // Shortly, u/v show how far (0%-100%) weve walked into this pixel.
  float u = x-x0;
  float v = y-y0;
  // Now we can literally treat u/v like t inside a lerp function.
  // This means can modify it just like t.
  // We modify it because plain UV looks too harsh.
  // So we smoothen it out with easing functions.
  // Use whichever one you feel like, experiment with it.
  // You should even remove fade_u/v and use plain u/v.
  // This will show you a lot more clearly why we smoothen it out.
  // It doesnt look drastically better, but it looks better.
  float fade_u = kross_math_ease_in_out_quint(u);
  float fade_v = kross_math_ease_in_out_quint(v);
  //--------------
  // Remember we said those 4 points represent a rectangle?
  //     (x0: 255, y0: 345)      (x1: 256, y0: 345)
  //    *_______________________________*
  //    |                               |
  //    |                               |
  //    |                               |
  //    |                               |
  //    |                               |
  //    *_______________________________*
  //    (x0: 255, y1: 346)      (x1: 256, y1: 346)
  float top_left       = kross_math_noise_hash_2d(x0, y0);
  float top_right      = kross_math_noise_hash_2d(x1, y0);
  float bottom_left    = kross_math_noise_hash_2d(x0, y1);
  float bottom_right   = kross_math_noise_hash_2d(x1, y1);
  //--------------
  // What we are doing here is called bilinear interpolation.
  // If youve done bilinear interpolation for image scaling before,
  // this will click instantly, because we are doing the same thing,
  // just with random coordinates.
  // First we lerp from left-right horizontally.
  // Then we lerp again from left-right horizontally but on the bottom.
  // Lastly we lerp from top-bottom vertically.
  float row_top      = kross_math_lerp(top_left, top_right, fade_u);
  float row_bottom   = kross_math_lerp(bottom_left, bottom_right, fade_u);
  return kross_math_lerp(row_top, row_bottom, fade_v);
  // Thats it, thats Value Noise.
  // Sounds hard and complicated, but its just because explanations of it online suck.
  //--------------
}
// -------------------------------------
static float kross_math_noise_2d_value_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  // Credit: Benoit Mandelbrot & John W. Van Ness for the mathematical concept.
  // Credit: Ken Perlin & Inigo Quilez for bringing it to computer graphics.
  //--------------
  // Really quick, if you go online now and search for fbm,
  // Your eyes will be met with very, very pretentious names,
  // layer_count is called "octvaes", frequency_multiplier is "lacunarity", amplitude is "gain".
  // Fractional Brownian Motion (fbm) is used to layer multiple copies of noise.
  // Keeping track of the total, which will store the final combined noise value.
  //--------------
  float total = 0.0f;
  // Amplitude shows how strong/tall the current layer of noise is.
  float amplitude = 1.0f;
  // Frequency shows how tightly packed/detailed the current layer of noise is.
  float frequency = 1.0f;
  // We track the maximum possible height so we can shrink the 
  // final number back down to a clean 0.0 to 1.0 range later.
  float max_value = 0.0f;
  //--------------
  // Now we loop through and stack each layer of noise on top of the last one.
  for (int i = 0; i < layer_count; ++i)
  {
    //--------------
    // Multiply our coordinates by the frequency to scale the detail.
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    //--------------
    // Get the noise value for this layer.
    // Multiply it by its strength (amplitude).
    // Then add it to our running total.
    total += kross_math_noise_2d_value(sample_x, sample_y)*amplitude;
    // Add the current strength to our maximum possible value tracker.
    max_value += amplitude;
    // Make the next layer have tighter, smaller details.
    frequency *= frequency_multiplier;
    // Make the next layer much weaker so it doesnt overpower the main shape.
    amplitude *= amplitude_multiplier;
    //--------------
  }
  // Divide the total by the maximum possible value.
  // This safely keeps our final answer between 0.0-1.0.
  return total/max_value;
  //--------------
}
// -------------------------------------
static float kross_math_noise_2d_perlin(float x, float y)
{
  // Credit: Ken Perlin.
  //--------------
  // Now that we know how Value Noise grids and fractional offsets (u/v) work,
  // Perlin Noise takes this a step further.
  // Instead of interpolating random values at the corners,
  // Perlin Noise assigns random direction vectors also known as gradients,
  // We use the exact same u/v logic from before but now we also calculate dot products.
  int x0 = floorf(x);
  int y0 = floorf(y);
  int x1 = x0+1;
  int y1 = y0+1;
  float u = x-x0;
  float v = y-y0;
  float fade_u = kross_math_ease_in_out_quint(u);
  float fade_v = kross_math_ease_in_out_quint(v);
  //--------------
  // Alright here we go now calculating vectors.
  // Dont be scared 00, 01, 10, and 11 are not magic math numbers.
  // The numbers represent points.
  // g00 is the gradient vector from x0 to y0.
  // g01 is the gradient vector from x0 to y1.
  // g10 is the gradient vector from x1 to y0.
  // g11 is the gradient vector from x1 to y1.
  // See? Simple.
  // We do the same exact thing as with Value Noise,
  // But replace hash_2d with hash_gradient_2d.
  // Again it is simply a rectangle with direction vectors instead of plain x/y coords.
  Vek2 g00 = kross_math_noise_hash_gradient_2d(x0, y0);
  Vek2 g10 = kross_math_noise_hash_gradient_2d(x1, y0);
  Vek2 g01 = kross_math_noise_hash_gradient_2d(x0, y1);
  Vek2 g11 = kross_math_noise_hash_gradient_2d(x1, y1);
  //   (g00)                            (g10)
  //    *_______________________________*
  //    |                               |
  //    |                               |
  //    |                               |
  //    |                               |
  //    |                               |
  //    *_______________________________*
  //  (g01)                            (g11)
  //--------------
  // Same here but were finding the distance vectors.
  // A distance vector is an arrow pointing from a corner to our point (u, v).
  // In math to get an arrow pointing from A to B, we do: B-A.
  // For example, if our point is located dead center (0.5, 0.5),
  // The top right vector (d10) becomes (0.5-1.0, 0.5-0.0) = (-0.5, 0.5).
  // We remove 1 only from the x because x is the only one that changed, y remained the same.
  Vek2 d00 = {u-0.0f, v-0.0f}; // Top-left to point.
  Vek2 d10 = {u-1.0f, v-0.0f}; // Top-right to point.
  Vek2 d01 = {u-0.0f, v-1.0f}; // bottom-left to point.
  Vek2 d11 = {u-1.0f, v-1.0f}; // bottom-right to point.
  //--------------
  // Time for the dot products.
  // Think of (n00, n10, n01, n11) like the influence scores of each corner.
  // They tell us how much each corners random gradient aligns
  // With the direction pointing toward our current pixel.
  // Positive means a peak, negative means a valley.
  // Quick disclaimer: here Im acting way smarter than I actually am.
  // I had to watch like 4 different Perlin Noise videos and I still dont understand,
  // Also again, similarities with Value Noise,
  // These are just like the x0 y0 x1 y1 corners of the rectangles but with fancier names.
  float n00 = kross_math_vek2_dot(g00, d00);
  float n10 = kross_math_vek2_dot(g10, d10);
  float n01 = kross_math_vek2_dot(g01, d01);
  float n11 = kross_math_vek2_dot(g11, d11);
  //--------------
  // Again, more bilinear interpolation, horizontally left-right.
  // Then vertically top-bottom.
  float row_top     = kross_math_lerp(n00, n10, fade_u);
  float row_bottom   = kross_math_lerp(n01, n11, fade_u);
  float finalised    = kross_math_lerp(row_top, row_bottom, fade_v);
  //--------------
  // Now here is something new, normalising the output.
  // Value Noise always interpolates from 0-1 so its always in range.
  // Perlin Noise uses dot products, which can output negative numbers.
  // In a 2D grid the max distance to the center of a cell is 0.707 (or atleast the internet says so).
  // This means the raw "finalised" value lands between -0.707 to +0.707
  // To get a clean 0-1 range, we are normalising it.
  float normalised   = (finalised+0.707f)/1.414f;
  normalised = kross_math_clampf(normalised, 0.0f, 1.0f);
  return normalised;
  //--------------
}
// -------------------------------------
static float kross_math_noise_2d_perlin_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  //--------------
  // We already explained FBM.
  // Nothing changes here except that instead of using the Value Noise function,
  // We use the Perlin Noise function.
  // One slight difference you may notice tho is that amplitude here is 1,
  // While in the Value Noise version it was 0.5, why?
  // Because this makes the first octave as a "master" layer that defines the main shapes,
  // While the other layers act as smaller/tighter detail adders.
  //--------------
  float total = 0.0f;
  float amplitude = 1.0f;
  float frequency = 1.0f;
  float max_value = 0.0f;
  //--------------
  for (int i = 0; i < layer_count; ++i)
  {
    //--------------
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    //--------------
    total += kross_math_noise_2d_perlin(sample_x, sample_y)*amplitude;
    max_value += amplitude;
    frequency *= frequency_multiplier;
    amplitude *= amplitude_multiplier;
    //--------------
  }
  return total/max_value;
}
// -------------------------------------
static float kross_math_noise_3d_value(float x, float y, float z)
{  
  //--------------
  // 3D Value Noise is a copy of 2D Value Noise.
  // The only difference is that we now also calculate z.
  // Same thing for u/v we introduce a new variable w,
  // which acts just like u/v do but for the z coordinate.
  // So u for x, v for y, w for z.
  //--------------
  int x0 = floorf(x);
  int y0 = floorf(y);
  int z0 = floorf(z);
  int x1 = x0+1;
  int y1 = y0+1;
  int z1 = z0+1;
  float u = x-x0;
  float v = y-y0;
  float w = z-z0;
  float fade_u = kross_math_ease_in_out_quint(u);
  float fade_v = kross_math_ease_in_out_quint(v);
  float fade_w = kross_math_ease_in_out_quint(w);
  //--------------
  // A really simple way to add 3D Value Noise,
  // Is to steal the coords from 2D Value Noise,
  // And group them into two pairs, one with z0 (Front Face), 
  // one with z1 (Back Face).
  //
  // Think of it like this cube right here:
  //             (BTL)________________(BTR)
  //               /|               /|
  //              / |              / |
  //             /  |             /  |
  //            /   |            /   |
  //       (FTL)/___|___________/(FTR)
  //           |    |           |    |
  //           |   /(BBL)       |    /(BBR)
  //           |  /             |   /
  //           | /              |  /
  //           |/               | /
  //       (FBL)/_______________|/(FBR)
  //
  // F = Front (z0), B = Back   (z1)
  // T = Top   (y0), B = Bottom (y1)
  // L = Left  (x0), R = Right  (x1)
  //--------------
  float front_top_left      = kross_math_noise_hash_3d(x0, y0, z0);
  float front_top_right     = kross_math_noise_hash_3d(x1, y0, z0);
  float front_bottom_left   = kross_math_noise_hash_3d(x0, y1, z0);
  float front_bottom_right  = kross_math_noise_hash_3d(x1, y1, z0);
  //--------------
  float back_top_left       = kross_math_noise_hash_3d(x0, y0, z1);
  float back_top_right      = kross_math_noise_hash_3d(x1, y0, z1);
  float back_bottom_left    = kross_math_noise_hash_3d(x0, y1, z1);
  float back_bottom_right   = kross_math_noise_hash_3d(x1, y1, z1);
  //--------------
  // Now instead of bilinear interpolation, we use trilinear interpolation.
  // Which is just bilinear interpolation, but with an extra step.
  // We first lerp horizontally top-left to top-right,
  // And bottom-left to bottom-right,
  // Then we lerp vertically from front_top to front_bottom.
  // And we do the same exact thing for the back aswell.
  // Then at the very end, we just blend the two faces together along the z-axis.
  // So we lerp depth of front to the depth of the back.
  //--------------
  float front_top     = kross_math_lerp(front_top_left, front_top_right, fade_u);
  float front_bottom  = kross_math_lerp(front_bottom_left, front_bottom_right, fade_u);
  float front_face    = kross_math_lerp(front_top, front_bottom, fade_v);
  //--------------
  float back_top      = kross_math_lerp(back_top_left, back_top_right, fade_u);
  float back_bottom   = kross_math_lerp(back_bottom_left, back_bottom_right, fade_u);
  float back_face     = kross_math_lerp(back_top, back_bottom, fade_v);
  //--------------
  return kross_math_lerp(front_face, back_face, fade_w);
  //--------------
}
// -------------------------------------
static float kross_math_noise_3d_value_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  //--------------
  // And here we do the same thing, its just like 2D FBM but with a z value.
  // The only thing that changes is that we now also sample the z value.
  // Everything else stays exactly the same.
  float total = 0.0f;
  float amplitude = 1.0f;
  float frequency = 1.0f;
  float max_value = 0.0f;
  //--------------
  for (int i = 0; i < layer_count; ++i)
  {
    //--------------
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    float sample_z = z*frequency;
    //--------------
    total += kross_math_noise_3d_value(sample_x, sample_y, sample_z)*amplitude;
    max_value += amplitude;
    frequency *= frequency_multiplier;
    amplitude *= amplitude_multiplier;
    //--------------
  }

  return total/max_value;
}
// -------------------------------------
static float kross_math_noise_3d_perlin(float x, float y, float z)
{
  //--------------
  // This is also just like 2D Perlin Noise, but with a z value.
  int x0 = floorf(x);
  int y0 = floorf(y);
  int z0 = floorf(z);
  int x1 = x0+1;
  int y1 = y0+1;
  int z1 = z0+1;
  float u = x-x0;
  float v = y-y0;
  float w = z-z0;
  float fade_u = kross_math_ease_in_out_quint(u);
  float fade_v = kross_math_ease_in_out_quint(v);
  float fade_w = kross_math_ease_in_out_quint(w);
  //--------------
  // Alright, remember what we said about 2D Perlin Noise?
  // How it uses direction vectors (Gradients),
  // Distance vectors, dot products, normalisation, etc?
  // Well here we do exactly that, with a few extra steps.
  // When in 2D we thought of the pixels generated as 4 corners of a rectangle.
  // Now they are the 8 corners of a cube.
  // And again just like we said for 3D Value Noise, we use the exact same variables,
  // and batch them in two groups, the z0 group, and the z1 group.
  Vek3 g000   = kross_math_noise_hash_gradient_3d(x0, y0, z0);
  Vek3 g100   = kross_math_noise_hash_gradient_3d(x1, y0, z0);
  Vek3 g010   = kross_math_noise_hash_gradient_3d(x0, y1, z0);
  Vek3 g110   = kross_math_noise_hash_gradient_3d(x1, y1, z0);
  //--------------
  Vek3 g001   = kross_math_noise_hash_gradient_3d(x0, y0, z1);
  Vek3 g101   = kross_math_noise_hash_gradient_3d(x1, y0, z1);
  Vek3 g011   = kross_math_noise_hash_gradient_3d(x0, y1, z1);
  Vek3 g111   = kross_math_noise_hash_gradient_3d(x1, y1, z1);
  //--------------
  // Think of it like this cube right here:
  //          (g001)________________(g101)
  //               /|              /|
  //              / |             / |
  //             /  |            /  |
  //            /   |           /   |
  //     (g000)/____|__________/(g100)
  //           |    |__________|____|
  //           |   /(g011)     |    /(g111)
  //           |  /            |   /
  //           | /             |  /
  //           |/              | /
  //           /_______________|/
  //        (g010)             (g110)
  //
  //--------------
  // Again, we get the distance vectors, we only subtract from the ones that change.
  // So d100 gets u-1 because its x1 y0 z0, so x changes while y/z stay the same.
  Vek3 d000 = {u-0.0f, v-0.0f, w-0.0f};
  Vek3 d100 = {u-1.0f, v-0.0f, w-0.0f};
  Vek3 d010 = {u-0.0f, v-1.0f, w-0.0f};
  Vek3 d110 = {u-1.0f, v-1.0f, w-0.0f};
  Vek3 d001 = {u-0.0f, v-0.0f, w-1.0f};
  Vek3 d101 = {u-1.0f, v-0.0f, w-1.0f};
  Vek3 d011 = {u-0.0f, v-1.0f, w-1.0f};
  Vek3 d111 = {u-1.0f, v-1.0f, w-1.0f};
  //--------------
  // Then we get the dot products of each pair just like we did for 2D Perlin Noise.
  float n000 = kross_math_vek3_dot(g000, d000);
  float n100 = kross_math_vek3_dot(g100, d100);
  float n010 = kross_math_vek3_dot(g010, d010);
  float n110 = kross_math_vek3_dot(g110, d110);
  float n001 = kross_math_vek3_dot(g001, d001);
  float n101 = kross_math_vek3_dot(g101, d101);
  float n011 = kross_math_vek3_dot(g011, d011);
  float n111 = kross_math_vek3_dot(g111, d111);
  //--------------
  // Now we trilinearly interpolate.
  float front_top     = kross_math_lerp(n000, n100, fade_u);
  float front_bottom  = kross_math_lerp(n010, n110, fade_u);
  float front_face    = kross_math_lerp(front_top, front_bottom, fade_v);
  float back_top      = kross_math_lerp(n001, n101, fade_u);
  float back_bottom   = kross_math_lerp(n011, n111, fade_u);
  float back_face     = kross_math_lerp(back_top, back_bottom, fade_v);
  // Then we blend the front and back faces along the z-axis.
  float finalised     = kross_math_lerp(front_face, back_face, fade_w);
  // Now for 2D the max distance was -0.707 to +0.707,
  // For 3D it is -0.866 to +0.866.
  // We normalise it and were good to go.
  float normalised    = (finalised+0.866f)/1.732f;
  normalised = kross_math_clampf(normalised, 0.0f, 1.0f);
  return normalised;
  //--------------
}
// -------------------------------------
static float kross_math_noise_3d_perlin_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  // This will store the final combined noise value.
  float total = 0.0f;
  // How strong/tall the current layer of noise is.
  float amplitude = 1.0f;
  // How tightly packed/detailed the current layer of noise is.
  float frequency = 1.0f;
  // We track the maximum possible height so we can shrink the 
  // final number back down to a clean 0.0 to 1.0 range later.
  float max_value = 0.0f;
  // Loop through and stack each layer of noise on top of the last one.
  for (int i = 0; i < layer_count; ++i)
  {
    // Multiply our coordinates by the frequency to scale the detail.
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    float sample_z = z*frequency;
    // Get the noise value for this layer, multiply it by its strength (amplitude), and add it to our running total.
    total += kross_math_noise_3d_perlin(sample_x, sample_y, sample_z)*amplitude;
    // Add the current strength to our maximum possible value tracker.
    max_value += amplitude;
    // Make the next layer have tighter, smaller details.
    frequency *= frequency_multiplier;
    // Make the next layer much weaker so it doesnt overpower the main shape.
    amplitude *= amplitude_multiplier;
  }

  // Divide the total by the maximum possible value.
  // This safely keeps our final answer between 0.0-1.0.
  return total/max_value;
}
// -------------------------------------
float kross_math_noise_2d(float x, float y, KNoiseType type)
{
  if (type == KROSS_NOISE_VALUE)       return kross_math_noise_2d_value(x, y);
  else if (type == KROSS_NOISE_PERLIN) return kross_math_noise_2d_perlin(x, y);
  return 0.0f;
}
// -------------------------------------
float kross_math_noise_2d_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type)
{
  if (type == KROSS_NOISE_VALUE)       return kross_math_noise_2d_value_fbm(x, y, layer_count, frequency_multiplier, amplitude_multiplier);
  else if (type == KROSS_NOISE_PERLIN) return kross_math_noise_2d_perlin_fbm(x, y, layer_count, frequency_multiplier, amplitude_multiplier);
  return 0.0f;
}
// -------------------------------------
float kross_math_noise_3d(float x, float y, float z, KNoiseType type)
{
  if (type == KROSS_NOISE_VALUE)       return kross_math_noise_3d_value(x, y, z);
  else if (type == KROSS_NOISE_PERLIN) return kross_math_noise_3d_perlin(x, y, z);
  return 0.0f;
}
// -------------------------------------
float kross_math_noise_3d_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type)
{
  if (type == KROSS_NOISE_VALUE)       return kross_math_noise_3d_value_fbm(x, y, z, layer_count, frequency_multiplier, amplitude_multiplier);
  else if (type == KROSS_NOISE_PERLIN) return kross_math_noise_3d_perlin_fbm(x, y, z, layer_count, frequency_multiplier, amplitude_multiplier);
  return 0.0f;
}
// -------------------------------------
float kross_math_cv_rad2deg(float angle_in_radians)
{
  return angle_in_radians*(180.0f/KROSS_PI);
}
// -------------------------------------
float kross_math_cv_deg2rad(float angle_in_degrees)
{
  return angle_in_degrees*(KROSS_PI/180.0f);
}
// -------------------------------------
int kross_math_clamp(int value, int min, int max)
{
  if (value < min)        value = min;
  else if (value > max)   value = max;
  return value;
}
// -------------------------------------
float kross_math_clampf(float value, float min, float max)
{
  if (value < min)        value = min;
  else if (value > max)   value = max;
  return value;
}
// -------------------------------------
double kross_math_clampd(double value, double min, double max)
{
  if (value < min)        value = min;
  else if (value > max)   value = max;
  return value;
}
// -------------------------------------
bool kross_math_hit_rect_rect(int rect0_x, int rect0_y, size_t rect0_w, size_t rect0_h, int rect1_x, int rect1_y, size_t rect1_w, size_t rect1_h)
{
  int r0_right_edge   = rect0_x+rect0_w;
  int r0_bottom_edge  = rect0_y+rect0_h;
  int r1_right_edge   = rect1_x+rect1_w;
  int r1_bottom_edge  = rect1_y+rect1_h;

  if (r0_right_edge >= r1_right_edge &&
      rect0_x <= r1_right_edge       &&
      r0_bottom_edge >= rect0_y      &&
      rect0_y <= r1_bottom_edge) return true;

  return false;
}
// -------------------------------------
bool kross_math_hit_rect_rectv(Vek2 rect0, Vek2 rect0_size, Vek2 rect1, Vek2 rect1_size)
{
  return kross_math_hit_rect_rect(rect0.x, rect0.y, rect0_size.x, rect0_size.y,
                                  rect1.x, rect1.y, rect1_size.x, rect1_size.y);
}
// -------------------------------------
bool kross_math_hit_rect_rectr(Rekt rect0, Rekt rect1)
{
  return kross_math_hit_rect_rect(rect0.x, rect0.y, rect0.w, rect0.h,
                                  rect1.x, rect1.y, rect1.w, rect1.h);
}
// -------------------------------------
bool kross_math_hit_rect_circle(int rect_x, int rect_y, size_t rect_w, size_t rect_h, int cx, int cy, size_t r)
{
  float test_x = cx;
  float test_y = cy;

  if (cx < rect_x)                   test_x = rect_x;
  else if (cx > (int)(rect_x+rect_w))  test_x = rect_x+rect_w;
  if (cy < rect_y)                   test_y = rect_y;
  else if (cy > (int)(rect_y+rect_h))  test_y = rect_y+rect_h;

  float distX = cx-test_x;
  float distY = cy-test_y;
  float distance = sqrt((distX*distX)+(distY*distY));

  if (distance <= r) return true;

  return false;
}
// -------------------------------------
bool kross_math_hit_rect_circlev(Vek2 rect, Vek2 rect_size, Vek2 center, size_t r)
{
  return kross_math_hit_rect_circle(rect.x, rect.y, rect_size.x, rect_size.y,
                                    center.x, center.y, r);
}
// -------------------------------------
bool kross_math_hit_rect_circler(Rekt rect, Vek2 center, size_t r)
{
  return kross_math_hit_rect_circle(rect.x, rect.y, rect.w, rect.h,
                                    center.x, center.y, r);
}
// -------------------------------------
#endif // KROSS_IMPLEMENTATION_GUARD
#endif // KROSS_IMPLEMENTATION
// -------------------------------------
