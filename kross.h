// -------------------------------------
// MIT License
// Copyright (c) 2026 Kristaq
//
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
// -------------------------------------
// The point of Kross is not to replace your game engine.
// The point is for you to read the source code, and learn graphics programming basics.
// The code is slow, but I have a solid excuse, *educational*.
// I genuinely hope you learn something from here :).
// -------------------------------------
// AI USE
// -------------------------------------
// The rasterizer part of my library is all written by me.
// The GPU part of my library uses OpenGL to take what the CPU drew and put it on the screen,
// That part was coded by AI, if you scroll to that section, (line: 2175), you will see why.
// -------------------------------------
// TODO: Add more noise, preferrably Simplex but others will do.
// TODO: Add QOI file support and comment all file functions.
// TODO: Add dotted lines.
// TODO: Slight optimizations for each function.
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
#define KLEAN_WHITE     (Kolor){255, 255, 255, 255}
#define KLEAN_BLACK     (Kolor){25,  25,  25,  255}
#define KLEAN_GRAY      (Kolor){130, 130, 130, 255}
#define KLEAN_RED       (Kolor){210, 80,  80,  255}
#define KLEAN_BLUE      (Kolor){70,  130, 180, 255}
#define KLEAN_GREEN     (Kolor){85,  150, 100, 255}
#define KLEAN_PURPLE    (Kolor){125, 115, 155, 255}
#define KLEAN_ORANGE    (Kolor){230, 145, 80,  255}
#define KLEAN_YELLOW    (Kolor){240, 215, 120, 255}
#define KLEAN_PINK      (Kolor){178, 121, 167, 255}
#define KLEAN_CYAN      (Kolor){96,  153, 192, 255}
#define KLEAN_BROWN     (Kolor){140, 120, 100, 255}
// -------------------------------------
#define KCYBER_WHITE     (Kolor){230, 255, 255, 255}
#define KCYBER_BLACK     (Kolor){5,   5,   15,  255}
#define KCYBER_GRAY      (Kolor){45,  50,  70,  255}
#define KCYBER_RED       (Kolor){255, 20,  20,  255}
#define KCYBER_BLUE      (Kolor){0,   150, 255, 255}
#define KCYBER_GREEN     (Kolor){57,  255, 20,  255}
#define KCYBER_PURPLE    (Kolor){180, 0,   255, 255}
#define KCYBER_ORANGE    (Kolor){255, 150, 0,   255}
#define KCYBER_YELLOW    (Kolor){255, 255, 0,   255}
#define KCYBER_PINK      (Kolor){255, 20,  147, 255}
#define KCYBER_CYAN      (Kolor){0,   255, 255, 255}
#define KCYBER_BROWN     (Kolor){160, 80,  40,  255}
// -------------------------------------
#define KGRUNGE_WHITE    (Kolor){190, 190, 180, 255}
#define KGRUNGE_BLACK    (Kolor){15,  15,  15,  255}
#define KGRUNGE_GRAY     (Kolor){80,  80,  80,  255}
#define KGRUNGE_RED      (Kolor){120, 10,  10,  255}
#define KGRUNGE_BLUE     (Kolor){40,  55,  90,  255}
#define KGRUNGE_GREEN    (Kolor){35,  60,  35,  255}
#define KGRUNGE_PURPLE   (Kolor){70,  35,  85,  255}
#define KGRUNGE_ORANGE   (Kolor){140, 70,  20,  255}
#define KGRUNGE_YELLOW   (Kolor){150, 130, 40,  255}
#define KGRUNGE_PINK     (Kolor){140, 60,  90,  255}
#define KGRUNGE_CYAN     (Kolor){50,  100, 110, 255}
#define KGRUNGE_BROWN    (Kolor){80,  50,  30,  255}
// -------------------------------------
#define KPASTEL_WHITE    (Kolor){255, 252, 250, 255}
#define KPASTEL_BLACK    (Kolor){70,  70,  85,  255}
#define KPASTEL_GRAY     (Kolor){200, 205, 215, 255}
#define KPASTEL_RED      (Kolor){255, 170, 170, 255}
#define KPASTEL_BLUE     (Kolor){170, 215, 235, 255}
#define KPASTEL_GREEN    (Kolor){150, 240, 180, 255}
#define KPASTEL_PURPLE   (Kolor){210, 180, 250, 255}
#define KPASTEL_ORANGE   (Kolor){255, 210, 160, 255}
#define KPASTEL_YELLOW   (Kolor){250, 250, 170, 255}
#define KPASTEL_PINK     (Kolor){255, 185, 200, 255}
#define KPASTEL_CYAN     (Kolor){180, 240, 240, 255}
#define KPASTEL_BROWN    (Kolor){200, 180, 160, 255}
// -------------------------------------
#define KSWAP(T, kr_a, kr_b) do { T _kross_tmp_t = kr_a; kr_a = kr_b; kr_b = _kross_tmp_t; } while (0)
#define KMIN(kre_a, kre_b) ((kre_a) < (kre_b)) ? (kre_a) : (kre_b)
#define KMAX(kre_a, kre_b) ((kre_a) > (kre_b)) ? (kre_a) : (kre_b)
#define KPI 3.141592653589793238462643383279502
// -------------------------------------
typedef struct Kolor  { uint8_t r, g, b, a;                                    } Kolor;
typedef struct Kanvas { Kolor* pixels; size_t w, h; float x, y;                } Kanvas;
typedef struct Vek2   { float x, y;                                            } Vek2;
typedef struct Vek3   { float x, y, z;                                         } Vek3;
typedef struct Rekt   { float x, y; size_t w, h;                               } Rekt;
// --------------
typedef enum KNoiseType  { KNOISE_VALUE, KNOISE_PERLIN                     } KNoiseType;
typedef enum KInterpType { KINTERP_NNI,  KINTERP_BILINEAR, KINTERP_BICUBIC } KInterpType;
typedef enum KInput {
  // --------------
  // Yes, I sat here and typed out every single one of these keycodes.
  // Do you know how boring it is to assign numbers to the alphabet?
  // It is the programming equivalent of doing lines in detention.
  // "I will not make a custom engine... I will not make a custom engine..."
  // --------------
  KI_A            = 65,
  KI_B            = 66,
  KI_C            = 67,
  KI_D            = 68,
  KI_E            = 69,
  KI_F            = 70,
  KI_G            = 71,
  KI_H            = 72,
  KI_I            = 73,
  KI_J            = 74,
  KI_K            = 75,
  KI_L            = 76,
  KI_M            = 77,
  KI_N            = 78,
  KI_O            = 79,
  KI_P            = 80,
  KI_Q            = 81,
  KI_R            = 82,
  KI_S            = 83,
  KI_T            = 84,
  KI_U            = 85,
  KI_V            = 86,
  KI_W            = 87,
  KI_X            = 88,
  KI_Y            = 89,
  KI_Z            = 90,
  KI_0            = 48,
  KI_1            = 49,
  KI_2            = 50,
  KI_3            = 51,
  KI_4            = 52,
  KI_5            = 53,
  KI_6            = 54,
  KI_7            = 55,
  KI_8            = 56,
  KI_9            = 57,
  KI_SPACE        = 32,
  KI_ENTER        = 257,
  KI_ESCAPE       = 256,
  KI_BACKSPACE    = 259,
  KI_TAB          = 258,
  KI_CAPS_LOCK    = 280,
  KI_DELETE       = 261,
  KI_INSERT       = 260,
  KI_PAGE_UP      = 266,
  KI_PAGE_DOWN    = 267,
  KI_HOME         = 268,
  KI_END          = 269,
  KI_RIGHT        = 262,
  KI_LEFT         = 263,
  KI_DOWN         = 264,
  KI_UP           = 265,
  KI_LSHIFT       = 340,
  KI_LCTRL        = 341,
  KI_LALT         = 342,
  KI_LSUPER       = 343,
  KI_RSHIFT       = 344,
  KI_RCTRL        = 345,
  KI_RALT         = 346,
  KI_RSUPER       = 347,
  KI_F1           = 290,
  KI_F2           = 291,
  KI_F3           = 292,
  KI_F4           = 293,
  KI_F5           = 294,
  KI_F6           = 295,
  KI_F7           = 296,
  KI_F8           = 297,
  KI_F9           = 298,
  KI_F10          = 299,
  KI_F11          = 300,
  KI_F12          = 301,
  KI_GRAVE        = 96,
  KI_MINUS        = 45,
  KI_EQUAL        = 61,
  KI_LBRACKET     = 91,
  KI_RBRACKET     = 93,
  KI_BACKSLASH    = 92,
  KI_SEMICOLON    = 59,
  KI_APOSTROPHE   = 39,
  KI_COMMA        = 44,
  KI_PERIOD       = 46,
  KI_SLASH        = 47,
  KI_MOUSE_1      = 0,
  KI_MOUSE_2      = 1,
  KI_MOUSE_3      = 2,
  KI_MOUSE_4      = 3,
  KI_MOUSE_5      = 4,
  KI_MOUSE_6      = 5,
  KI_MOUSE_7      = 6,
  KI_MOUSE_8      = 7,
  KI_MOUSE_LEFT   = 0,
  KI_MOUSE_RIGHT  = 1,
  KI_MOUSE_MIDDLE = 2
} KInput;
// -------------------------------------
void    kw_init(Kanvas* kv, const char* title);
void    kw_free(void);
bool    kw_should_close(void);
void    kw_target_fps(size_t fps);
float   kw_delta_time(void);
// -------------------------------------
bool    ki_down(KInput input);
bool    ki_once(KInput input);
bool    ki_up(KInput input);
Vek2    ki_mouse_pos(void);
// -------------------------------------
Kanvas* kv_init(size_t width, size_t height);
Kanvas* kv_load(const char* path);
void    kv_save(Kanvas* kv, const char* path);
void    kv_start(Kanvas* kv);
void    kv_stop(Kanvas* kv);
void    kv_free(Kanvas* kv);
void    kv_fill(Kanvas* kv, Kolor kolor);
void    kv_fill_horz(Kanvas* kv, Kolor kl_left, Kolor kl_right);
void    kv_fill_vert(Kanvas* kv, Kolor kl_top,  Kolor kl_bot);
Kanvas* kv_copy(Kanvas* kv);
Kanvas* kv_scale(Kanvas* kv, float scale, KInterpType interp);
Kanvas* kv_rotate(Kanvas* kv, float angle_in_degrees, KInterpType interp);
Vek2    kv_nrm(Kanvas* kv);
void    kv_blit(Kanvas* kv_main, Kanvas* kv_sub);
void    kv_blitr(Kanvas* kv_main, Rekt start, Rekt end, Kanvas* kv_sub);
void    kv_blur(Kanvas* kv, size_t radius);
void    kv_vignette(Kanvas* kv, size_t radius);
void    kv_grayscale(Kanvas* kv);
void    kv_invert(Kanvas* kv);
void    kv_pixel(Kanvas* kv, int x, int y, Kolor kolor);
void    kv_line(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, Kolor kolor);
void    kv_linev(Kanvas* kv, Vek2 pos0, Vek2 pos1, size_t thicc, Kolor kolor);
void    kv_line_arrow(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, size_t head_len, float head_angle, Kolor kolor);
void    kv_line_arrowv(Kanvas* kv, Vek2 v0, Vek2 v1, size_t thicc, size_t head_len, float head_angle, Kolor kolor);
void    kv_line_bezier_quad(Kanvas* kv, Vek2 p0, Vek2 cp, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor);
void    kv_line_bezier_cube(Kanvas* kv, Vek2 p0, Vek2 cp0, Vek2 cp1, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor);
void    kv_rect(Kanvas* kv, int x, int y, size_t width, size_t height, Kolor kolor);
void    kv_rectv(Kanvas* kv, Vek2 pos, Vek2 size, Kolor kolor);
void    kv_rectr(Kanvas* kv, Rekt rect, Kolor kolor);
void    kv_rect_stroke(Kanvas* kv, int x, int y, size_t width, size_t height, size_t thicc, Kolor kolor);
void    kv_rect_strokev(Kanvas* kv, Vek2 pos, Vek2 size, size_t thicc, Kolor kolor);
void    kv_rect_stroker(Kanvas* kv, Rekt rect, size_t thicc, Kolor kolor);
void    kv_circle(Kanvas* kv, int cx, int cy, size_t r, Kolor kolor);
void    kv_circlev(Kanvas* kv, Vek2 center, size_t r, Kolor kolor);
void    kv_circle_stroke(Kanvas* kv, int cx, int cy, size_t r, size_t thicc, Kolor kolor);
void    kv_circle_strokev(Kanvas* kv, Vek2 center, size_t r, size_t thicc, Kolor kolor);
void    kv_triangle(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kolor);
void    kv_triangle_stroke(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, size_t thicc, Kolor kolor);
void    kv_triangle_tricolor(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kl0, Kolor kl1, Kolor kl2);
void    kv_grid(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, size_t thicc, Kolor kolor);
void    kv_gridv(Kanvas* kv, Vek2 start, Vek2 colrow, size_t gap, size_t thicc, Kolor kolor);
void    kv_board(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, Kolor kl0, Kolor kl1);
void    kv_boardv(Kanvas* kv, Vek2 start, Vek2 colrow, size_t gap, Kolor kl0, Kolor kl1);
// -------------------------------------
void    kv_text_char(Kanvas* kv, int x, int y, char c, int size, Kolor kolor);
void    kv_text(Kanvas* kv, int x, int y, const char* text, size_t size, Kolor kolor);
void    kv_text_multi(Kanvas* kv, int x, int y, const char* text, size_t size, size_t kolors_len, Kolor* kolors);
void    kv_textf(Kanvas* kv, int x, int y, size_t size, Kolor kolor, const char* text, ...);
void    kv_textf_multi(Kanvas* kv, int x, int y, size_t size, size_t kolors_len, Kolor* kolors, const char* text, ...);
int     kv_text_measure(const char* text, size_t size);
// -------------------------------------
Kolor   kl_lerp(Kolor start, Kolor end, float t);
Kolor   kl_cerp(Kolor kl0, Kolor kl1, Kolor kl2, Kolor kl3, float t);
Kolor   kl_blend(Kolor kl0, Kolor kl1);
Kolor   kl_scale(Kolor kolor, float scale);
Kolor   kl_invert(Kolor kolor);
Kolor   kl_grayscale(Kolor kolor);
Kolor   kl_get(Kanvas* kv, int x, int y);
bool    kl_compare_rgb(Kolor kl0, Kolor kl1);
bool    kl_compare_rgba(Kolor kl0, Kolor kl1);
Kolor   kl_from_hsv(float h, float s, float v);
Kolor   kl_from_hex(uint32_t hex);
Kolor   kl_from_cmyk(float c, float m, float y, float k);
// -------------------------------------
// --------------
// "Why PPM and TGA?" I hear you ask. "Why not PNG, you absolute Neanderthal?"
// Because PNG uses DEFLATE compression, and I would rather eat glass than write
// A custom zlib compression algorithm in pure C just to save a screenshot.
// PPM is literally just plain text: "P3, width, height, max_color, raw RGB".
// If you open a PPM in a text editor, you can literally read the pixels.
// Its horribly bloated, but hey, it compiles in 5 lines of code.
void    kf_ppm_write(Kanvas* kv, const char* path);
void    kf_tga_write(Kanvas* kv, const char* path);
void    kf_qoi_write(Kanvas* kv, const char* path);
Kanvas* kf_ppm_read(const char* path);
Kanvas* kf_tga_read(const char* path);
Kanvas* kf_qoi_read(const char* path);
// --------------
// -------------------------------------
Vek2    km_vek2_zero(void);
Vek2    km_vek2_one(void);
Vek2    km_vek2_add(Vek2 v0, Vek2 v1);
Vek2    km_vek2_addval(Vek2 v0, float value);
Vek2    km_vek2_sub(Vek2 v0, Vek2 v1);
Vek2    km_vek2_subval(Vek2 v0, float value);
float   km_vek2_dot(Vek2 v0, Vek2 v1);
float   km_vek2_cross(Vek2 v0, Vek2 v1);
float   km_vek2_len(Vek2 v0);
Vek2    km_vek2_min(Vek2 v0, Vek2 v1);
Vek2    km_vek2_max(Vek2 v0, Vek2 v1);
Vek2    km_vek2_nrm(Vek2 v0);
Vek2    km_vek2_scale(Vek2 v0, float scalar);
Vek2    km_vek2_rotate(Vek2 v0, Vek2 center, float angle);
Vek2    km_vek2_lerp(Vek2 v0, Vek2 v1, float t);
Vek2    km_vek2_screen2norm(Vek2 screen, Vek2 kv);
Vek2    km_vek2_normal2screen(Vek2 normal, Vek2 kv);
Vek2    km_vek2_cartesian2screen(Vek2 cartesian, Vek2 kv, float scale);
Vek2    km_vek2_screen2cartesian(Vek2 screen, Vek2 kv, float scale);
Vek2    km_vek2_screen2uv(Vek2 screen, Vek2 kv);
Vek2    km_vek2_uv2screen(Vek2 uv, Vek2 kv);
Vek2    km_bezier_quad(Vek2 p0, Vek2 cp, Vek2 p1, float t);
Vek2    km_bezier_cube(Vek2 p0, Vek2 cp0, Vek2 cp1, Vek2 p1, float t);
// -------------------------------------
// --------------
// Let me be completely honest with you, this section is never used once in the library.
// Originally I wanted Kross to be a 2D and 3D software rasterizer,
// Then I realized that writing 3D from scratch means dealing with matrix projections, Clip spaces and depth buffers, things my tiny brain was not prepared for.
// So instead of deleting everything, I left the useless 3D vector math here.
// Its a tombstone for my dead dreams. (Who said Shakespeare died?).
Vek3    km_vek3_zero(void);
Vek3    km_vek3_one(void);
Vek3    km_vek3_add(Vek3 v0, Vek3 v1);
Vek3    km_vek3_addval(Vek3 v0, float value);
Vek3    km_vek3_sub(Vek3 v0, Vek3 v1);
Vek3    km_vek3_subval(Vek3 v0, float value);
Vek3    km_vek3_scale(Vek3 v0, float scalar);
Vek3    km_vek3_cross(Vek3 v0, Vek3 v1);
Vek3    km_vek3_lerp(Vek3 v0, Vek3 v1, float t);
float   km_vek3_dot(Vek3 v0, Vek3 v1);
float   km_vek3_len(Vek3 v0);
Vek3    km_vek3_min(Vek3 v0, Vek3 v1);
Vek3    km_vek3_max(Vek3 v0, Vek3 v1);
Vek3    km_vek3_nrm(Vek3 v0);
Vek3    km_vek3_rotate_x(Vek3 v0, float angle);
Vek3    km_vek3_rotate_y(Vek3 v0, float angle);
Vek3    km_vek3_translate_x(Vek3 v0, float dx);
Vek3    km_vek3_translate_y(Vek3 v0, float dy);
Vek3    km_vek3_translate_z(Vek3 v0, float dz);
Vek2    km_vek3_project(Vek3 v0);
float   km_lerp(float start, float end, float t);
float   km_cerp(float x0, float x1, float x2, float x3, float t);
// --------------
// -------------------------------------
float   km_noise_2d(float x, float y, KNoiseType type);
float   km_noise_2d_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type);
float   km_noise_3d(float x, float y, float z, KNoiseType type);
float   km_noise_3d_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type);
// -------------------------------------
// --------------
// We humans like to think in degrees.
// The C math library <math.h>, however, lives in a pretentious world of radians.
// If you pass 90 into cos(), it will not give you 0. It will give you a garbage decimal.
// Use these functions to translate between human brain and C math library.
float   km_cv_deg2rad(float angle_in_degrees);
float   km_cv_rad2deg(float angle_in_radians);
// --------------
int     km_clamp(int value, int min, int max);
float   km_clampf(float value, float min, float max);
double  km_clampd(double value, double min, double max);
bool    km_hit_rect_rect(int rect0x, int rect0y, size_t rect0w, size_t rect0h, int rect1x, int rect1y, size_t rect1w, size_t rect1h);
bool    km_hit_rect_rectv(Vek2 rect0, Vek2 rect0_size, Vek2 rect1, Vek2 rect1_size);
bool    km_hit_rect_rectr(Rekt rekt0, Rekt rekt1);
bool    km_hit_rect_circle(int rectx, int recty, size_t rectw, size_t recth, int cx, int cy, size_t r);
bool    km_hit_rect_circlev(Vek2 rect, Vek2 rect_size, Vek2 center, size_t r);
bool    km_hit_rect_circler(Rekt rekt, Vek2 center, size_t r);
// -------------------------------------
float   km_ease_in_quad(float t);
float   km_ease_out_quad(float t);
float   km_ease_in_out_quad(float t);
float   km_ease_in_quint(float t);
float   km_ease_out_quint(float t);
float   km_ease_in_out_quint(float t);
float   km_ease_in_elastic(float t);
float   km_ease_out_elastic(float t);
float   km_ease_in_out_elastic(float t);
float   km_ease_in_cubic(float t);
float   km_ease_out_cubic(float t);
float   km_ease_in_out_cubic(float t);
float   km_ease_in_sine(float t);
float   km_ease_out_sine(float t);
float   km_ease_in_out_sine(float t);
float   km_ease_in_expo(float t);
float   km_ease_out_expo(float t);
float   km_ease_in_out_expo(float t);
float   km_ease_in_bounce(float t);
float   km_ease_out_bounce(float t);
float   km_ease_in_out_bounce(float t);
// -------------------------------------
#ifdef __cplusplus
}
#endif
#endif // KROSS_H
#ifdef  KROSS_IMPLEMENTATION
#ifndef KROSS_IMPLEMENTATION_GUARD
#define KROSS_IMPLEMENTATION_GUARD
// -------------------------------------
Kanvas* kv_init(size_t width, size_t height)
{
  Kanvas* kv = malloc(sizeof(Kanvas));
  if (!kv) return NULL;
  kv->w = width;
  kv->h = height;
  kv->x = 0;
  kv->y = 0;
  kv->pixels = malloc(width*height*sizeof(Kolor));
  if (!kv->pixels) { free(kv); return NULL; }
  return kv;
}
// -------------------------------------
Kanvas* kv_load(const char* path)
{
  const char* dot = strrchr(path, '.');
  const char* extension = (dot && *(dot+1)) ? dot+1 : "";

  if (strcmp(extension, "ppm") == 0) return kf_ppm_read(path);
  if (strcmp(extension, "tga") == 0) return kf_tga_read(path);

  return NULL;
}
// -------------------------------------
void kv_save(Kanvas* kv, const char* path)
{
  const char* dot = strrchr(path, '.');
  const char* extension = (dot && *(dot+1)) ? dot+1 : "";

  if (strcmp(extension, "ppm") == 0) kf_ppm_write(kv, path);
  if (strcmp(extension, "tga") == 0) kf_tga_write(kv, path);
}
// -------------------------------------
void kv_free(Kanvas* kv)
{
  if (kv->pixels) free(kv->pixels);
  if (kv)         free(kv);
}
// -------------------------------------
void kv_pixel(Kanvas* kv, int x, int y, Kolor kolor)
{
  //--------------
  x = km_clamp(x, 0, kv->w-1);
  y = km_clamp(y, 0, kv->h-1);
  //--------------
  // This function does exactly what we explain above,
  // Under the hood, its just return kv->pixels[y*kv->w+x];
  Kolor kl = kl_get(kv, x, y);
  kv->pixels[y*kv->w+x] = kl_blend(kolor, kl);
  //--------------
}
// -------------------------------------
void kv_invert(Kanvas* kv)
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
void kv_fill(Kanvas* kv, Kolor kolor)
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
void kv_fill_horz(Kanvas* kv, Kolor kl_left, Kolor kl_right)
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
      kv_pixel(kv, left_x, y, kl_left);
    }

    for (int right_x = kv->w/2; right_x < (int)kv->w; ++right_x)
    {
      kv_pixel(kv, right_x, y, kl_right);
    }
  }
}
// -------------------------------------
void kv_fill_vert(Kanvas* kv, Kolor kl_bot, Kolor kl_top)
{ 
  //--------------
  // CHALLENGE
  //--------------
  // This code sucks performance wise (like most of my code).
  // Because it iterates column-first (x on the outer loop), it jumps across
  // Memory rows on every single pixel write, causing massive cache misses.
  // I want you to rewrite this function so that it traverses the canvas row-by-row,
  // (horizontally), taking full advantage of CPU cache lines.
  //--------------
  for (int x = 0; x < (int)kv->w; ++x)
  {
    for (int top_y = 0; top_y < (int)kv->h/2; ++top_y)
    {
      kv_pixel(kv, x, top_y, kl_top);
    }

    for (int bottom_y = kv->h/2; bottom_y < (int)kv->h; ++bottom_y)
    {
      kv_pixel(kv, x, bottom_y, kl_bot);
    }
  }
}
// -------------------------------------
Kanvas* kv_copy(Kanvas* kv)
{
  if (!kv || !kv->pixels) return NULL;
  Kanvas* tmp = kv_init(kv->w, kv->h);

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
static Kanvas* kv_scale_nni(Kanvas* kv, float scale)
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
  Kanvas* scaled = kv_init(kv->w*scale, kv->h*scale);
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
    // the decimals (truncation). If y*scale_inv is 14.9, src_y just becomes 14.
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
static Kanvas* kv_scale_bilinear(Kanvas* kv, float scale)
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
  Kanvas* scaled = kv_init(kv->w*scale, kv->h*scale);
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
      int x0 = src_x;
      int y0 = src_y;
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
      float fade_u = km_ease_in_out_quint(u);
      float fade_v = km_ease_in_out_quint(v);
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
      Kolor row_top       = kl_lerp(top_left, top_right, fade_u);
      Kolor row_bottom    = kl_lerp(bottom_left, bottom_right, fade_u);
      // Then from top to bottom.
      Kolor final_kolor   = kl_lerp(row_top, row_bottom, fade_v);
      // Then writing the kolor to the buffer.
      kv_pixel(scaled, x, y, final_kolor);
      //--------------
    }
  }

  return scaled;
}
// -------------------------------------
static Kanvas* kv_scale_bicubic(Kanvas* kv, float scale)
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
  Kanvas* scaled = kv_init(kv->w*scale, kv->h*scale);
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
      int base_x = src_x;
      int base_y = src_y;
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
      Kolor row_top = kl_cerp(row_top0, row_top1, row_top2, row_top3, u);
      Kolor row_2nd = kl_cerp(row_2nd0, row_2nd1, row_2nd2, row_2nd3, u);
      Kolor row_3rd = kl_cerp(row_3rd0, row_3rd1, row_3rd2, row_3rd3, u);
      Kolor row_bot = kl_cerp(row_bot0, row_bot1, row_bot2, row_bot3, u);
      //--------------
      // Then we cerp vertically in linear order: top-bottom (top-2nd-3rd-bottom).
      Kolor row_final = kl_cerp(row_top, row_2nd, row_3rd, row_bot, v);
      // Then we write it to the buffer.
      kv_pixel(scaled, x, y, row_final);
      //--------------
    }
  }

  return scaled;
}
// -------------------------------------
Kanvas* kv_scale(Kanvas* kv, float scale, KInterpType interp)
{
  if (interp == KINTERP_NNI)      return kv_scale_nni(kv, scale);
  if (interp == KINTERP_BILINEAR) return kv_scale_bilinear(kv, scale);
  if (interp == KINTERP_BICUBIC)  return kv_scale_bicubic(kv, scale);
  return NULL;
}
// -------------------------------------
static Kanvas* kv_rotate_nni(Kanvas* kv, float angle_in_degrees)
{
  if (!kv || !kv->pixels || kv->w == 0 || kv->h == 0) return NULL;

  Kanvas* tmp = kv_init(kv->w, kv->h);
  if (!tmp || !tmp->pixels) return NULL;

  float angle_in_radians = km_cv_deg2rad(angle_in_degrees);

  float cos_angle = cosf(-angle_in_radians);
  float sin_angle = sinf(-angle_in_radians);

  for (int dy = 0; dy < (int)kv->h; ++dy)
  {
    for (int dx = 0; dx < (int)kv->w; ++dx)
    {
      float src_x = dx*cos_angle - dy*sin_angle;
      float src_y = dx*sin_angle + dy*cos_angle;

      src_x = km_clampf(src_x, 0, kv->w-1);
      src_y = km_clampf(src_y, 0, kv->h-1);

      int src_x_i = (int)roundf(src_x);
      int src_y_i = (int)roundf(src_y);

      src_x_i = km_clamp(src_x_i, 0, (int)kv->w-1);
      src_y_i = km_clamp(src_y_i, 0, (int)kv->h-1);

      Kolor kolor = kv->pixels[src_y_i*kv->w + src_x_i];

      kv_pixel(tmp, dx, dy, kolor);
      //--------------
    }
  }

  return tmp;
}
// -------------------------------------
static Kanvas* kv_rotate_bilinear(Kanvas* kv, float angle_in_degrees)
{
  if (!kv || !kv->pixels || kv->w == 0 || kv->h == 0) return NULL;
  Kanvas* tmp = kv_init(kv->w, kv->h);
  if (!tmp || !tmp->pixels) return NULL;

  float angle_in_radians = km_cv_deg2rad(angle_in_degrees);
  float cos_angle = cosf(-angle_in_radians);
  float sin_angle = sinf(-angle_in_radians);

  for (int dy = 0; dy < (int)kv->h; ++dy)
  {
    for (int dx = 0; dx < (int)kv->w; ++dx)
    {
      float src_x = dx*cos_angle - dy*sin_angle;
      float src_y = dx*sin_angle + dy*cos_angle;
      src_x = km_clampf(src_x, 0, kv->w-1);
      src_y = km_clampf(src_y, 0, kv->h-1);

      int x0 = src_x;
      int y0 = src_y;
      int x1 = (x0+1 < (int)kv->w) ? x0+1 : x0;
      int y1 = (y0+1 < (int)kv->h) ? y0+1 : y0;

      float u = src_x-x0;
      float v = src_y-y0;

      Kolor top_left  = kv->pixels[y0*kv->w + x0];
      Kolor top_right = kv->pixels[y0*kv->w + x1];
      Kolor bot_left  = kv->pixels[y1*kv->w + x0];
      Kolor bot_right = kv->pixels[y1*kv->w + x1];

      Kolor row_top = kl_lerp(top_left, top_right, u);
      Kolor row_bot = kl_lerp(bot_left, bot_right, u);
      Kolor final   = kl_lerp(row_top, row_bot, v);
      kv_pixel(tmp, dx, dy, final);
    }
  }

  return tmp;
}
// -------------------------------------
static Kanvas* kv_rotate_bicubic(Kanvas* kv, float angle_in_degrees)
{
  if (!kv || !kv->pixels || kv->w == 0 || kv->h == 0) return NULL;
  Kanvas* tmp = kv_init(kv->w, kv->h);
  if (!tmp || !tmp->pixels) return NULL;

  float angle_in_radians = km_cv_deg2rad(angle_in_degrees);
  float cos_angle = cosf(-angle_in_radians);
  float sin_angle = sinf(-angle_in_radians);

  for (int dy = 0; dy < (int)kv->h; ++dy)
  {
    for (int dx = 0; dx < (int)kv->w; ++dx)
    {
      float src_x = dx*cos_angle - dy*sin_angle;
      float src_y = dx*sin_angle + dy*cos_angle;
      src_x = km_clampf(src_x, 0, kv->w-1);
      src_y = km_clampf(src_y, 0, kv->h-1);

      int base_x = src_x;
      int base_y = src_y;
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
      Kolor row_top = kl_cerp(row_top0, row_top1, row_top2, row_top3, u);
      Kolor row_2nd = kl_cerp(row_2nd0, row_2nd1, row_2nd2, row_2nd3, u);
      Kolor row_3rd = kl_cerp(row_3rd0, row_3rd1, row_3rd2, row_3rd3, u);
      Kolor row_bot = kl_cerp(row_bot0, row_bot1, row_bot2, row_bot3, u);
      //--------------
      Kolor row_final = kl_cerp(row_top, row_2nd, row_3rd, row_bot, v);
      kv_pixel(tmp, dx, dy, row_final);
    }
  }

  return tmp;
}
// -------------------------------------
Kanvas* kv_rotate(Kanvas* kv, float angle_in_degrees, KInterpType interp)
{
  if (interp == KINTERP_NNI)      return kv_rotate_nni(kv, angle_in_degrees);
  if (interp == KINTERP_BILINEAR) return kv_rotate_bilinear(kv, angle_in_degrees);
  if (interp == KINTERP_BICUBIC)  return kv_rotate_bicubic(kv, angle_in_degrees);
  return NULL;
}
// -------------------------------------
Vek2 kv_nrm(Kanvas* kv)
{
  float nrm_x = (float)kv->x/(float)kv->w;
  float nrm_y = (float)kv->y/(float)kv->h;
  return (Vek2){nrm_x, nrm_y};
}
// -------------------------------------
void kv_blit(Kanvas* kv_main, Kanvas* kv_sub)
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
void kv_blitr(Kanvas* kv_main, Rekt start, Rekt end, Kanvas* kv_sub)
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
      kv_main->pixels[dst_i] = kl_blend(kv_sub->pixels[src_i], kv_main->pixels[dst_i]);
      //--------------
    }
  }
}
// -------------------------------------
void kv_blur(Kanvas* kv, size_t radius)
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
  Kanvas* tmp = kv_copy(kv);
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
          target_x = km_clamp(target_x, 0, (int)kv->w-1);
          target_y = km_clamp(target_y, 0, (int)kv->h-1);
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
void kv_vignette(Kanvas* kv, size_t radius)
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
        factor = km_clampf(factor, 0, 1);
        float intensity = 1.0f-factor;
        Kolor kolor     = kl_get(kv, x, y);
        Kolor scaled    = kl_scale(kolor, intensity);
        kv_pixel(kv, x, y, scaled);
      }
      //--------------
    }
  }
}
// -------------------------------------
void kv_grayscale(Kanvas* kv)
{
  for (size_t i = 0; i < kv->w*kv->h; ++i)
  {
    kv->pixels[i] = kl_grayscale(kv->pixels[i]);
  }
}
// -------------------------------------
Kolor kl_get(Kanvas* kv, int x, int y)
{
  //--------------
  if (!kv) return (Kolor){0, 0, 0, 255};
  x = km_clamp(x, 0, kv->w-1);
  y = km_clamp(y, 0, kv->h-1);
  return kv->pixels[y*kv->w+x];
  //--------------
}
// -------------------------------------
void kv_rect(Kanvas* kv, int x, int y, size_t width, size_t height, Kolor kolor)
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
  kv_triangle(kv, top_left,  bot_left, top_right, kolor);
  kv_triangle(kv, top_right, bot_left, bot_right, kolor);
  //--------------
}
// -------------------------------------
void kv_rectv(Kanvas* kv, Vek2 pos, Vek2 size, Kolor kolor)
{
  //--------------
  // Peak library "development",
  // Take previous function, change parameter, fake new function.
  // Also for size {x: width, y: height}.
  //--------------
  kv_rect(kv, (int)pos.x, (int)pos.y, (size_t)size.x, (size_t)size.y, kolor);
  //--------------
}
// -------------------------------------
void kv_rectr(Kanvas* kv, Rekt rect, Kolor kolor)
{
  kv_rect(kv, rect.x, rect.y, rect.w, rect.h, kolor);
}
// -------------------------------------
void kv_rect_stroke(Kanvas* kv, int x, int y, size_t width, size_t height, size_t thicc, Kolor kolor)
{
  //--------------
  // For this one we draw 4 "thicc" sized rectangles that connect to each other.
  //--------------
  kv_rect(kv, x, y, width, thicc, kolor);
  kv_rect(kv, x, y+height-thicc, width, thicc, kolor);
  kv_rect(kv, x, y+thicc, thicc, height-2*thicc, kolor);
  kv_rect(kv, x+width-thicc, y+thicc, thicc, height-2*thicc, kolor);
  //--------------
}
// -------------------------------------
void kv_rect_strokev(Kanvas* kv, Vek2 pos, Vek2 size, size_t thicc, Kolor kolor)
{
  // For size {x: width, y: height}
  kv_rect_stroke(kv, (int)pos.x, (int)pos.y, (size_t)size.x, (size_t)size.y, thicc, kolor);
}
// -------------------------------------
void kv_rect_stroker(Kanvas* kv, Rekt rect, size_t thicc, Kolor kolor)
{
  kv_rect_stroke(kv, rect.x, rect.y, rect.w, rect.h, thicc, kolor);
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
float km_ease_in_quad(float t)
{
  return t*t;
}
// -------------------------------------
float km_ease_out_quad(float t)
{
  return t*(2.0f-t);
}
// -------------------------------------
float km_ease_in_out_quad(float t)
{
  return t < 0.5f ? 2*t*t : 1.0f - powf(-2*t + 2, 2)/2;
}
// -------------------------------------
float km_ease_in_elastic(float t)
{
  const float c4 = (2*KPI)/3;

  return t == 0 ? 0 : t == 1 ? 1 : -powf(2, 10*t - 10) * sinf((t * 10.0f - 10.75f) * c4);
}
// -------------------------------------
float km_ease_out_elastic(float t)
{
  return (float)(sinf(-13.0f*(t-1.0f)*(KPI/2.0f))*powf(2.0f, -10.0f*t)+1.0f);
}
// -------------------------------------
float km_ease_in_out_elastic(float t)
{
  return (float)(sinf(-13.0f*(t-1.0f)*(KPI/2.0f))*powf(2.0f, -10.0f*t)+1.0f);
}
// -------------------------------------
float km_ease_in_quint(float t)
{
  return t*t*t*t*t;
}
// -------------------------------------
float km_ease_out_quint(float t)
{
  return 1.0f-powf(1.0f-t, 5.0f);
}
// -------------------------------------
float km_ease_in_out_quint(float t)
{
  return t*t*t*(t*(t*6.0f-15.0f)+10.0f);
}
// -------------------------------------
float km_ease_in_cubic(float t)
{
  return t*t*t;
}
// -------------------------------------
float km_ease_out_cubic(float t)
{
  return 1.0f-powf(1.0f-t, 3.0f);
}
// -------------------------------------
float km_ease_in_out_cubic(float t)
{
  return t < 0.5f ? 4.0f*t*t*t : 1.0f-powf(-2.0f*t+2.0f, 3.0f)/2.0f;
}
// -------------------------------------
float km_ease_in_sine(float t)
{  
  return 1.0f-cosf((t*KPI)/2.0f);
}
// -------------------------------------
float km_ease_out_sine(float t)
{
  return sinf((t*KPI)/2.0f);
}
// -------------------------------------
float km_ease_in_out_sine(float t)
{
  return -(cosf(KPI*t) - 1.0f)/2.0f;
}
// -------------------------------------
float km_ease_in_expo(float t)
{
  return t == 0.0f ? 0.0f : powf(2.0f, 10.0f*t - 10.0f);
}
// -------------------------------------
float km_ease_out_expo(float t)
{
  return t == 1.0f ? 1.0f : 1.0f-powf(2.0f, -10.0f*t);
}
// -------------------------------------
float km_ease_in_out_expo(float t)
{
  return t == 0.0f ? 0.0f : t == 1.0f ? 1.0f : t < 0.5f ? powf(2.0f, 20.0f*t - 10.0f)/2.0f
  : (2.0f-powf(2.0f, -20.0f*t + 10.0f))/2.0f;
}
// -------------------------------------
float km_ease_in_bounce(float t)
{
  return 1.0f-km_ease_out_bounce(1.0f-t);
}
// -------------------------------------
float km_ease_out_bounce(float t)
{
  const float n1 = 7.5625f;
  const float d1 = 2.75f;

  if (t < 1.0f/d1) return n1*t*t;
  else if (t < 2.0f/d1) return n1*(t-1.5f/d1)*(t-1.5f/d1) + 0.75f;
  else if (t < 2.5f/d1) return n1*(t-2.25f/d1)*(t-2.25f/d1) + 0.9375f;
  else return n1 * (t - 2.625f/d1) * (t - 2.625f/d1) + 0.984375f;
}
// -------------------------------------
float km_ease_in_out_bounce(float t)
{
  return t < 0.5f ? (1.0f-km_ease_out_bounce(1.0f - 2.0f*t))/2.0f : (1.0f+km_ease_out_bounce(2.0f*t - 1.0f))/2.0f;
}
// -------------------------------------
void kv_circle(Kanvas* kv, int cx, int cy, size_t r, Kolor kolor)
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
          if (x1*x1 + y1*y1 <= (int)(r*r)) kv_pixel(kv, x, y, kolor);
          //--------------
        }
      }
    }
  }
}
// -------------------------------------
void kv_circlev(Kanvas* kv, Vek2 center, size_t radius, Kolor kolor)
{
  kv_circle(kv, (int)center.x, (int)center.y, radius, kolor);
}
// -------------------------------------
void kv_circle_stroke(Kanvas* kv, int cx, int cy, size_t r, size_t thicc, Kolor kolor)
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
            kv_pixel(kv, x, y, kolor);
          }
        }
        //--------------
      }
    }
  }
}
// -------------------------------------
void kv_circle_strokev(Kanvas* kv, Vek2 center, size_t r, size_t thicc, Kolor kolor)
{
  kv_circle_stroke(kv, (int)center.x, (int)center.y, r, thicc, kolor);
}
// -------------------------------------
static bool km_triangle_edge_is_top_left(Vek2 start, Vek2 end)
{
  Vek2 edge = km_vek2_sub(start, end);
  bool is_top_edge = edge.y == 0 && edge.x > 0;
  bool is_left_edge = edge.y < 0;
  return is_top_edge || is_left_edge;
}
// -------------------------------------
static int km_triangle_edge_func(Vek2 p1, Vek2 p2, Vek2 px)
{
  Vek2 p12 = km_vek2_sub(p1, p2);
  Vek2 p1px = km_vek2_sub(px, p1);
  return p12.x*p1px.y - p12.y*p1px.x;
}
// -------------------------------------
void kv_triangle(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kolor)
{
  //--------------
  // Welcome to the heart of the rasterizer,
  // To the most painful, yet most beautiful function in graphics programming,
  // For this one, I had the pleasure of following one of Pikumas guides,
  // If youve never heard of Pikuma or seen a video form him, then go.
  // Im not gonna waste your time and clutter your brain on this one,
  // The best way to learn how triangle rasterizing works,
  // is to go and watch that hour long video.
  // The video is titled: "Triangle Rasterization - Pikuma".
  //--------------
  int min_x = KMIN(KMIN(v0.x, v1.x), v2.x);
  int min_y = KMIN(KMIN(v0.y, v1.y), v2.y);
  int max_x = KMAX(KMAX(v0.x, v1.x), v2.x);
  int max_y = KMAX(KMAX(v0.y, v1.y), v2.y);
  //--------------
  int bias0 = km_triangle_edge_is_top_left(v0, v1) ? 0 : -1;
  int bias1 = km_triangle_edge_is_top_left(v1, v2) ? 0 : -1;
  int bias2 = km_triangle_edge_is_top_left(v2, v0) ? 0 : -1;
  //--------------
  for (int y = min_y; y <= max_y; ++y)
  {
    for (int x = min_x; x <= max_x; ++x)
    {
      //--------------
      int w0 = km_triangle_edge_func(v0, v1, (Vek2){x, y}) + bias0;
      int w1 = km_triangle_edge_func(v1, v2, (Vek2){x, y}) + bias1;
      int w2 = km_triangle_edge_func(v2, v0, (Vek2){x, y}) + bias2;
      //--------------
      // If all weights are >= 0 then the pixel is inside the triangle.
      //--------------
      if (w0 >= 0 && w1 >= 0 && w2 >= 0) kv_pixel(kv, x, y, kolor);
      //--------------
    }
  }
}
// -------------------------------------
void kv_triangle_tricolor(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, Kolor kl0, Kolor kl1, Kolor kl2)
{
  //--------------
  int min_x = KMIN(KMIN(v0.x, v1.x), v2.x);
  int min_y = KMIN(KMIN(v0.y, v1.y), v2.y);
  int max_x = KMAX(KMAX(v0.x, v1.x), v2.x);
  int max_y = KMAX(KMAX(v0.y, v1.y), v2.y);
  //--------------
  float area = km_triangle_edge_func(v0, v1, v2);
  if (area <= 0) return;
  //--------------
  float karea = 1.0f/area;
  //--------------
  int bias0 = km_triangle_edge_is_top_left(v0, v1) ? 0 : -1;
  int bias1 = km_triangle_edge_is_top_left(v1, v2) ? 0 : -1;
  int bias2 = km_triangle_edge_is_top_left(v2, v0) ? 0 : -1;
  //--------------
  for (int y = min_y; y <= max_y; ++y)
  {
    for (int x = min_x; x <= max_x; ++x)
    {
      int w0 = km_triangle_edge_func(v0, v1, (Vek2){x, y})+bias0;
      int w1 = km_triangle_edge_func(v1, v2, (Vek2){x, y})+bias1;
      int w2 = km_triangle_edge_func(v2, v0, (Vek2){x, y})+bias2;
      //--------------
      if (w0 >= 0 && w1 >= 0 && w2 >= 0)
      {
        float alpha = w1*karea;
        float beta  = w2*karea;
        float gamma = w0*karea;
        //--------------
        int r = alpha*kl0.r+beta*kl1.r+gamma*kl2.r;
        int g = alpha*kl0.g+beta*kl1.g+gamma*kl2.g;
        int b = alpha*kl0.b+beta*kl1.b+gamma*kl2.b;
        //--------------
        kv_pixel(kv, x, y, (Kolor){r, g, b, 255});
      }
    }
  }
}
// -------------------------------------
void kv_triangle_stroke(Kanvas* kv, Vek2 v0, Vek2 v1, Vek2 v2, size_t thicc, Kolor kolor)
{
  kv_linev(kv, v0, v1, thicc, kolor);
  kv_linev(kv, v1, v2, thicc, kolor);
  kv_linev(kv, v2, v0, thicc, kolor);
}
// -------------------------------------
void kv_line(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, Kolor kolor)
{
  Vek2 start = {x0, y0};
  Vek2 end = {x1, y1};
  Vek2 dir = km_vek2_sub(end, start);
  Vek2 perp = {-dir.y, dir.x};
  Vek2 perp_norm = km_vek2_nrm(perp);
  //--------------
  float half_thickness = thicc/2.0f;
  Vek2 offset = km_vek2_scale(perp_norm, half_thickness);
  //--------------
  Vek2 v0 = km_vek2_add(start, offset);
  Vek2 v1 = km_vek2_sub(start, offset);
  Vek2 v2 = km_vek2_add(end, offset);
  Vek2 v3 = km_vek2_sub(end, offset);
  //--------------
  kv_triangle(kv, v0, v2, v1, kolor);
  kv_triangle(kv, v1, v2, v3, kolor);
}
// -------------------------------------
void kv_linev(Kanvas* kv, Vek2 pos0, Vek2 pos1, size_t thicc, Kolor kolor)
{
  kv_line(kv, pos0.x, pos0.y, pos1.x, pos1.y, thicc, kolor);
}
// -------------------------------------
void kv_line_arrow(Kanvas* kv, int x0, int y0, int x1, int y1, size_t thicc, size_t head_len, float head_angle, Kolor kolor)
{
  //--------------
  // This function is just math I dont understand.
  // I dont even remember where I copied this function.
  // All I did was change the names around and use my own functions.
  //--------------
  kv_line(kv, x0, y0, x1, y1, thicc, kolor);
  float rad_angle = km_cv_deg2rad(head_angle);
  float angle = atan2(y1-y0, x1-x0);
  //--------------
  int x2 = x1-(int)(head_len*cosf(angle-rad_angle));
  int y2 = y1-(int)(head_len*sinf(angle-rad_angle));
  int x3 = x1-(int)(head_len*cosf(angle+rad_angle));
  int y3 = y1-(int)(head_len*sinf(angle+rad_angle));
  //--------------
  kv_line(kv, x1, y1, x2, y2, thicc, kolor);
  kv_line(kv, x1, y1, x3, y3, thicc, kolor);
}
// -------------------------------------
void kv_line_arrowv(Kanvas* kv, Vek2 v0, Vek2 v1, size_t thicc, size_t head_len, float head_angle, Kolor kolor)
{
  kv_line_arrow(kv, v0.x, v0.y, v1.x, v1.y, thicc, head_len, head_angle, kolor);
}
// -------------------------------------
void kv_line_bezier_quad(Kanvas* kv, Vek2 p0, Vek2 cp, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor)
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
  // Is a formula for finding how far along we are in between two points.
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
    Vek2 point_bez = km_bezier_quad(p0, cp, p1, t);
    //--------------
    kv_linev(kv, point_pre, point_bez, thicc, kolor);
    point_pre = point_bez;
    //--------------
  }
  //--------------
  // LEARNING RESOURCES: "Rasterizing Splines in C" - Tsoding.
  //--------------
}
// -------------------------------------
void kv_line_bezier_cube(Kanvas* kv, Vek2 p0, Vek2 cp0, Vek2 cp1, Vek2 p1, size_t resolution, size_t thicc, Kolor kolor)
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
    Vek2 point_bez = km_bezier_cube(p0, cp0, cp1, p1, t);
    //--------------
    kv_linev(kv, point_pre, point_bez, thicc, kolor);
    point_pre = point_bez;
    //--------------
  }
  //--------------
  // LEARNING RESOURCES: "Rasterizing Splines in C" - Tsoding.
  //--------------
}
// -------------------------------------
void kv_grid(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, size_t thicc, Kolor kolor)
{
  size_t width = cols*gap;
  size_t height = rows*gap;

  for (size_t row = 0; row <= rows; ++row)
  {
    int y1 = y+row*gap;
    kv_line(kv, x, y1, x+width, y1, thicc, kolor);
  }

  for (size_t col = 0; col <= cols; ++col)
  {
    int x1 = x+col*gap;
    kv_line(kv, x1, y, x1, y+height, thicc, kolor);
  }
}
// -------------------------------------
void kv_board(Kanvas* kv, int x, int y, size_t cols, size_t rows, size_t gap, Kolor kl0, Kolor kl1)
{
  if (cols == 0 || rows == 0 || gap == 0) return;

  for (size_t row = 0; row < rows; ++row)
  {
    for (size_t col = 0; col < cols; ++col)
    {
      Kolor c = (row+col)%2 == 0 ? kl0 : kl1;
      kv_rect(kv, x + col*gap, y + row*gap, gap, gap, c);
    }
  }
}
// -------------------------------------
void kv_boardv(Kanvas* kv, Vek2 start, Vek2 colrow, size_t gap, Kolor kl0, Kolor kl1)
{
  kv_board(kv, (int)start.x, (int)start.y, (size_t)colrow.x, (size_t)colrow.y, gap, kl0, kl1);
}
// -------------------------------------
// Welcome to the font section.
// Its nothing fancy just a large bitmap with scary numbers.
// Dont worry tho, they are not scary I promise.
// Bitmaps are usually stored 2 ways.
// Either in hexadecimal, which are the alien numbers,
// Or in normal bitmaps, which are maps of 1s and 0s.
// Heres an example of the bitmap for the letter "A":
// --------------
// 0x18 = 0 0 0 1 1 0 0 0
// 0x3C = 0 0 1 1 1 1 0 0
// 0x66 = 0 1 1 0 0 1 1 0
// 0x66 = 0 1 1 0 0 1 1 0
// 0x7E = 0 1 1 1 1 1 1 0
// 0x66 = 0 1 1 0 0 1 1 0
// 0x66 = 0 1 1 0 0 1 1 0
// 0x00 = 0 0 0 0 0 0 0 0
// --------------
// Do you see it? See how it maps to a letter? 
// The way I originally wanted to do this was to use bitmaps of 1s and 0s.
// But what you realise very, very quickly is that those kind of bitmaps,
// For the whole english alphabet + numbers + special chars, is around 1000 loc.
// Meanwhile the same thing but in hexadecimal format is literally 10x smaller.
// kross_font is an 8x8 font and its made to resemble the PxPlus IBM VGA8 font.
// Something important is that the font starts with ASCII 32, which is space.
// You will see why this is important in the actual functions below.
// (Feel free to change this font to whatever you prefer).
// -------------------------------------
#define GLYPH_WIDTH 8
#define GLYPH_HEIGHT 8
uint8_t kross_font_glyphs[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /* 32: Space */
  0x18,0x3C,0x3C,0x18,0x18,0x00,0x18,0x00, /* 33: ! */
  0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00, /* 34: " */
  0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00, /* 35: # */
  0x18,0x3E,0x60,0x3E,0x06,0x7C,0x18,0x00, /* 36: $ */
  0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00, /* 37: % */
  0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00, /* 38: & */
  0x18,0x18,0x30,0x00,0x00,0x00,0x00,0x00, /* 39: ' */
  0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00, /* 40: ( */
  0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00, /* 41: ) */
  0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00, /* 42: * */
  0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00, /* 43: + */
  0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30, /* 44: , */
  0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00, /* 45: - */
  0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00, /* 46: . */
  0x00,0x06,0x0C,0x18,0x30,0x60,0x00,0x00, /* 47: / */
  0x7C,0xC6,0xE6,0xF6,0xDE,0xCE,0x7C,0x00, /* 48: 0 */
  0x18,0x38,0x78,0x18,0x18,0x18,0x7E,0x00, /* 49: 1 */
  0x7C,0xC6,0x06,0x3C,0x60,0xC0,0xFE,0x00, /* 50: 2 */
  0x7C,0xC6,0x06,0x3C,0x06,0xC6,0x7C,0x00, /* 51: 3 */
  0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x0C,0x00, /* 52: 4 */
  0xFE,0xC0,0xFC,0x06,0x06,0xC6,0x7C,0x00, /* 53: 5 */
  0x7C,0xC6,0xC0,0xFC,0xC6,0xC6,0x7C,0x00, /* 54: 6 */
  0xFE,0x06,0x0C,0x18,0x30,0x30,0x30,0x00, /* 55: 7 */
  0x7C,0xC6,0xC6,0x7C,0xC6,0xC6,0x7C,0x00, /* 56: 8 */
  0x7C,0xC6,0xC6,0xFE,0x06,0xC6,0x7C,0x00, /* 57: 9 */
  0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00, /* 58: : */
  0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30, /* 59: ; */
  0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00, /* 60: < */
  0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00, /* 61: = */
  0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00, /* 62: > */
  0x7C,0xC6,0x06,0x0C,0x18,0x00,0x18,0x00, /* 63: ? */
  0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00, /* 64: @ */
  0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0xC6,0x00, /* 65: A */
  0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00, /* 66: B */
  0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00, /* 67: C */
  0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00, /* 68: D */
  0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00, /* 69: E */
  0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00, /* 70: F */
  0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3E,0x00, /* 71: G */
  0xC6,0xC6,0xC6,0xFE,0xC6,0xC6,0xC6,0x00, /* 72: H */
  0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00, /* 73: I */
  0x06,0x06,0x06,0x06,0xC6,0xC6,0x7C,0x00, /* 74: J */
  0xC6,0xCC,0xD8,0xF0,0xD8,0xCC,0xC6,0x00, /* 75: K */
  0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00, /* 76: L */
  0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00, /* 77: M */
  0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00, /* 78: N */
  0x3C,0x66,0x66,0x66,0x66,0x66,0x3C,0x00, /* 79: O */
  0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00, /* 80: P */
  0x38,0x6C,0xC6,0xC6,0xE6,0x6C,0x38,0x06, /* 81: Q */
  0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00, /* 82: R */
  0x3C,0x66,0x60,0x3C,0x06,0x66,0x3C,0x00, /* 83: S */
  0x7E,0x18,0x18,0x18,0x18,0x18,0x18,0x00, /* 84: T */
  0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00, /* 85: U */
  0xC6,0xC6,0xC6,0xC6,0xC6,0x6C,0x38,0x00, /* 86: V */
  0xC6,0xC6,0xC6,0xD6,0xFE,0xEE,0xC6,0x00, /* 87: W */
  0xC6,0xC6,0x6C,0x38,0x6C,0xC6,0xC6,0x00, /* 88: X */
  0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00, /* 89: Y */
  0x7E,0x06,0x0C,0x18,0x30,0x60,0x7E,0x00, /* 90: Z */
  0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00, /* 91: [ */
  0x00,0x60,0x30,0x18,0x0C,0x06,0x00,0x00, /* 92: \ */
  0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00, /* 93: ] */
  0x18,0x3C,0x66,0x00,0x00,0x00,0x00,0x00, /* 94: ^ */
  0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00, /* 95: _ */
  0x30,0x18,0x0C,0x00,0x00,0x00,0x00,0x00, /* 96: ` */
  0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00, /* 97: a */
  0xE0,0x60,0x60,0x7C,0x66,0x66,0xDC,0x00, /* 98: b */
  0x00,0x00,0x78,0xCC,0xC0,0xCC,0x78,0x00, /* 99: c */
  0x1C,0x0C,0x0C,0x3C,0x6C,0x6C,0x3E,0x00, /* 100: d */
  0x00,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00, /* 101: e */
  0x38,0x6C,0x60,0xF0,0x60,0x60,0xF0,0x00, /* 102: f */
  0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8, /* 103: g */
  0xE0,0x60,0x60,0x6C,0x76,0x66,0xE6,0x00, /* 104: h */
  0x18,0x18,0x00,0x38,0x18,0x18,0x3C,0x00, /* 105: i */
  0x0C,0x0C,0x00,0x1C,0x0C,0x0C,0x0C,0x38, /* 106: j */
  0xE0,0x60,0x60,0x66,0x6C,0x78,0xE6,0x00, /* 107: k */
  0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00, /* 108: l */
  0x00,0x00,0xEC,0xFE,0xD6,0xD6,0xD6,0x00, /* 109: m */
  0x00,0x00,0xDC,0x66,0x66,0x66,0x66,0x00, /* 110: n */
  0x00,0x00,0x3C,0x66,0x66,0x66,0x3C,0x00, /* 111: o */
  0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0, /* 112: p */
  0x00,0x00,0x3E,0x6C,0x6C,0x3C,0x0C,0x1E, /* 113: q */
  0x00,0x00,0xDC,0x76,0x60,0x60,0x60,0x00, /* 114: r */
  0x00,0x00,0x78,0xC0,0x78,0x0C,0x78,0x00, /* 115: s */
  0x10,0x30,0x7C,0x30,0x30,0x34,0x18,0x00, /* 116: t */
  0x00,0x00,0x66,0x66,0x66,0x66,0x3E,0x00, /* 117: u */
  0x00,0x00,0x66,0x66,0x66,0x3C,0x18,0x00, /* 118: v */
  0x00,0x00,0xD6,0xD6,0xD6,0xFE,0x6C,0x00, /* 119: w */
  0x00,0x00,0x66,0x3C,0x18,0x3C,0x66,0x00, /* 120: x */
  0x00,0x00,0x66,0x66,0x66,0x3E,0x0C,0x38, /* 121: y */
  0x00,0x00,0x7E,0x0C,0x18,0x30,0x7E,0x00, /* 122: z */
  0x0C,0x18,0x18,0x38,0x18,0x18,0x0C,0x00, /* 123: { */
  0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00, /* 124: | */
  0x30,0x18,0x18,0x1C,0x18,0x18,0x30,0x00, /* 125: } */
  0x00,0x00,0x00,0x36,0x6C,0x00,0x00,0x00  /* 126: ~ */
};
// -------------------------------------
void kv_text_char(Kanvas* kv, int x, int y, char c, int size, Kolor kolor)
{
  if (c < 32) return;
  // --------------
  int glyph_index = c-32;
  const uint8_t* glyph = &kross_font_glyphs[glyph_index*GLYPH_HEIGHT];
  // --------------
  for (int row = 0; row < GLYPH_HEIGHT; ++row)
  {
    uint8_t bits = glyph[row];
    // --------------
    for (int col = 0; col < GLYPH_WIDTH; ++col)
    {
      if ((bits >> (7-col)) & 1)
      {
        for (int step_y = 0; step_y < size; ++step_y)
        {
          for (int step_x = 0; step_x < size; ++step_x)
          {
            int pos_x = x+col*size;
            int pos_y = y+row*size;
            kv_pixel(kv, pos_x+step_x, pos_y+step_y, kolor);
          }
        }
      }
    }
  }
}
// -------------------------------------
void kv_text(Kanvas* kv, int x, int y, const char* text, size_t size, Kolor kolor)
{
  int start_x = x;

  while (*text)
  {
    kv_text_char(kv, start_x, y, *text, size, kolor);
    start_x += GLYPH_WIDTH*size;
    text++;
  }
}
// -------------------------------------
void kv_text_multi(Kanvas* kv, int x, int y, const char* text, size_t size, size_t kolors_len, Kolor* kolors)
{
  Kolor kolor;
  int start_x = x;
  int i = 0;

  while (*text)
  {
    i++;
    kolor = (!kolors) ? KLEAN_BLUE : kolors[i%kolors_len];
    kv_text_char(kv, start_x, y, *text, size, kolor);
    start_x += GLYPH_WIDTH*size;
    text++;
  }
}
// -------------------------------------
void kv_textf(Kanvas* kv, int x, int y, size_t size, Kolor kolor, const char* text, ...)
{
  char buf[256];
  va_list args;
  va_start(args, text);
  vsnprintf(buf, sizeof(buf), text, args);
  va_end(args);

  kv_text(kv, x, y, buf, size, kolor);
}
// -------------------------------------
void kv_textf_multi(Kanvas* kv, int x, int y, size_t size, size_t kolors_len, Kolor* kolors, const char* text, ...)
{
  char buf[256];
  va_list args;
  va_start(args, text);
  vsnprintf(buf, sizeof(buf), text, args);
  va_end(args);

  kv_text_multi(kv, x, y, buf, size, kolors_len, kolors);
}
// -------------------------------------
int kv_text_measure(const char* text, size_t size)
{
  int len = strlen(text);
  if (size == 0) return 0;
  return len*GLYPH_WIDTH*size;
}
// -------------------------------------
// Cleaning these up since we dont want anyone to use them outside.
#undef GLYPH_WIDTH
#undef GLYPH_HEIGHT
// -------------------------------------
// Alright let me rant a little bit about Windows here.
// At first, when the library started, I was using OpenGL 3.2.
// When the time came to release it, I wanted it to be cross-platform,
// So it would work for Linux, MacOS, Windows, etc.
// Linux and Mac are not picky, whatever OpenGL you use, theyre okay with.
// Windows on the other hand, only exposes OpenGL 1.1 out of the box.
// The pea-brains at Microsoft literally decided to freeze OpenGL support completely.
// To use OpenGL 3.2 on Windows, I would need to use a tool like GLAD.
// --------------
// Now, why GLAD? Because, Windows does not let you statically link modern OpenGL functions.
// They arent in the headers, instead, the graphics driver has them hidden away.
// To get them, there are two ways:
// 1. Go insane and manually ask the driver for each functions memory address.
// 2. Use GLAD (guess where the name comes from).
// Now between these two options, I decided to go for the third, using OpenGL 1.1.
// Which is the only version Windows is okay with out of the box.
// I LITERALLY HAD TO FIND OPENGL 1.1 CODE ONLINE TO COPY BECAUSE I KNOW JACK ABOUT OPENGL.
// ALRIGHT? YOU KNOW WHAT THAT FEELS LIKE?
// IT FEELS LIKE PERFORMING DARK NECROMANCY ON A 30 YEAR OLD API CORPSE USING STACK OVERFLOW AS MY SPELL BOOK.
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
float kw_delta_time(void)
{
  return delta_time;
}
// -------------------------------------
void kw_target_fps(size_t fps)
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
bool ki_down(KInput input)
{
  if (input < 0)           return false;
  if (input <= KI_MOUSE_8) return mouse_buttons[input];
  if (input < 512)         return keys[input];

  return false;
}
// -------------------------------------
bool ki_once(KInput input)
{
  if (input < 0)           return false;
  if (input <= KI_MOUSE_8) return mouse_just[input];
  if (input < 512)         return keys_just[input];
  return false;
}
// -------------------------------------
bool ki_up(KInput input)
{
  if (input < 0)           return false;
  if (input <= KI_MOUSE_8) return mouse_released[input];
  if (input < 512)         return keys_released[input];

  return false;
}
// -------------------------------------
Vek2 ki_mouse_pos(void)
{
  if (!window) return (Vek2){0.0f, 0.0f};
  
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  return (Vek2){(float)xpos, (float)ypos};
}
// -------------------------------------
void kross_init_gpu_bridge(Kanvas* kv)
{
  glGenTextures(1, &canvas_tex_id);
  glBindTexture(GL_TEXTURE_2D, canvas_tex_id);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, kv->w, kv->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, kv->pixels);

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
void kw_init(Kanvas* kv, const char* title)
{
  if (!glfwInit()) return;

#ifdef __APPLE__
  glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_TRUE);
#endif

  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  logical_w = (float)kv->w;
  logical_h = (float)kv->h;

  window = glfwCreateWindow(kv->w, kv->h, title, NULL, NULL);

  if (!window) { glfwTerminate(); return; }

  glfwSetWindowSize(window, kv->w, kv->h);
  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetMouseButtonCallback(window, glfw_mouse_bridge);
  glfwSwapInterval(0);

  kross_init_gpu_bridge(kv);
  last_frame_time = glfwGetTime();
}
// -------------------------------------
void kv_start(Kanvas* kv)
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
void kv_stop(Kanvas* kv)
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
bool kw_should_close(void)
{
  if (!window) return true;
  return glfwWindowShouldClose(window);
}
// -------------------------------------
void kw_free(void)
{
  if (window)
  {
    glfwDestroyWindow(window);
    window = NULL;
  }
  glfwTerminate();
}
// -------------------------------------
Kolor kl_scale(Kolor kolor, float scale)
{
  if (scale <= 1) return kolor;
  uint8_t scaled_r = (kolor.r*scale <= 255) ? kolor.r*scale : 255;
  uint8_t scaled_g = (kolor.g*scale <= 255) ? kolor.g*scale : 255;
  uint8_t scaled_b = (kolor.b*scale <= 255) ? kolor.b*scale : 255;
  return(Kolor){scaled_r, scaled_g, scaled_b, kolor.a};
}
// -------------------------------------
Kolor kl_blend(Kolor kl0, Kolor kl1)
{
  // Credit: Alvy Ray Smith & Ed Catmull for coming up with alpha compositing.
  // --------------
  // Tiny optimization here, if the foreground (kl0) is completely opaque,
  // That means its completely hiding its background, so just display it.
  // If the foreground is completely transparent, display the background (kl1).
  // --------------
  if (kl0.a == 255) return kl0;
  if (kl0.a == 0)   return kl1;
  // --------------
  // FEAR NOT the scary bit-shifts. They are very simple, very nice.
  // This example of a bit-shift, is called a right bit-shift,
  // A right bit-shift is equivalent to division, but its in binary.
  // So >> 8 is not dividing by 8, its dividing by 2^8 which is 256.
  // When I first learned this, I thought why noy just use >>/<< everywhere,
  // Its much quicker and it works the same right? Well yes but no.
  // Firstly, you cannot bit-shift a float/double, only integers.
  // Secondly it is preferred to only do this on unsigned integers.
  // Thirdly, do you really want to say 2 << 2 instead of 2*4?
  // --------------
  // The standard formula with floats is:
  // result = (foreground*alpha) + (background*(1-alpha))
  // You might ask, where did you get division from you idiot?
  // Firstly, ouch. Secondly, the division is hiding. I know, element of surprise.
  // In this formula, alpha is measured from 0.0 to 1.0.
  // In this code, the alpha channel is a byte, so we have to convert it from 0-255 to 0-1.
  // --------------
  // Lets manually calculate this as an example:
  // Say kl0.r = 200, kl0.a = 180, so kl0.r*kl0.a = 36000.
  // 36000 in binary is: 1000110010100000.
  // >> 8 means "shift every single digit 8 spots to the right).
  // So we take that whole line, and slide it:
  // --------------
  //      1000110010100000 (Before)
  // >> 8 0000000010001100 (After)
  // --------------
  // Notice how the last 8 digits just walked the plank?
  // This chunk: 10100000 got completely pushed off the edge, its deleted.
  // The front filled in with 8 fresh zeros.
  // So our final answer: 0000000010001100 is 140.
  // Lets check: 36000/256 = 140.625, 0.625 gets chopped off.
  // That lost precision right there is what the trade-off of this method is.
  // Thankfully its so small that the human eye cannot see it.
  // --------------
  uint8_t r = (uint8_t)((kl0.r*kl0.a + kl1.r*(255-kl0.a)) >> 8);
  uint8_t g = (uint8_t)((kl0.g*kl0.a + kl1.g*(255-kl0.a)) >> 8);
  uint8_t b = (uint8_t)((kl0.b*kl0.a + kl1.b*(255-kl0.a)) >> 8);
  // --------------
  // Alpha is slightly different, kl0s opacity counts in full, (its on top).
  // We only add whatever sliver of kl1 peeks through any gaps kl0 didnt cover.
  // --------------
  uint8_t a = (uint8_t)(kl0.a +       (kl1.a*(255-kl0.a)  >> 8));
  // --------------
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kl_lerp(Kolor start, Kolor end, float t)
{
  uint8_t r = (uint8_t)km_lerp((float)start.r, (float)end.r, t);
  uint8_t g = (uint8_t)km_lerp((float)start.g, (float)end.g, t);
  uint8_t b = (uint8_t)km_lerp((float)start.b, (float)end.b, t);
  uint8_t a = (uint8_t)km_lerp((float)start.a, (float)end.a, t);
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kl_cerp(Kolor kl0, Kolor kl1, Kolor kl2, Kolor kl3, float t)
{
  //--------------
  float r = km_cerp((float)kl0.r, (float)kl1.r, (float)kl2.r, (float)kl3.r, t);
  float g = km_cerp((float)kl0.g, (float)kl1.g, (float)kl2.g, (float)kl3.g, t);
  float b = km_cerp((float)kl0.b, (float)kl1.b, (float)kl2.b, (float)kl3.b, t);
  float a = km_cerp((float)kl0.a, (float)kl1.a, (float)kl2.a, (float)kl3.a, t);
  //--------------
  r = km_clampf(r, 0.0f, 255.0f);
  g = km_clampf(g, 0.0f, 255.0f);
  b = km_clampf(b, 0.0f, 255.0f);
  a = km_clampf(a, 0.0f, 255.0f);
  //--------------
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kl_invert(Kolor kolor) 
{
  uint8_t xor_r = kolor.r ^= 255;
  uint8_t xor_g = kolor.g ^= 255;
  uint8_t xor_b = kolor.b ^= 255;
  return (Kolor){xor_r, xor_g, xor_b, kolor.a};
}
// -------------------------------------
Kolor kl_grayscale(Kolor kolor)
{
  float gray_r = (float)kolor.r*0.299f;
  float gray_g = (float)kolor.g*0.587f;
  float gray_b = (float)kolor.b*0.114f;
  float gray = gray_r+gray_g+gray_b;
  return (Kolor){(uint8_t)gray, (uint8_t)gray, (uint8_t)gray, kolor.a};
}
// -------------------------------------
bool kl_compare_rgb(Kolor kl0, Kolor kl1)
{
  return (kl0.r == kl1.r && kl0.g == kl1.g && kl0.b == kl1.b);
}
// -------------------------------------
bool kl_compare_rgba(Kolor kl0, Kolor kl1)
{
  return (kl0.r == kl1.r && kl0.g == kl1.g && kl0.b == kl1.b && kl0.a == kl1.a);
}
// -------------------------------------
Kolor kl_from_hex(uint32_t hex)
{
  // --------------
  // AGAIN, DO NOT BE SCARED. This one is actually a lot of fun.
  // (This is a pretty long explanation, since there is quite a few new things).
  // --------------
  // What were doing is turning a single hexadecimal number into RRGGBBAA.
  // Each pair is one byte. For example:
  // 0xAABBCCDD, laid out as 4 bytes is:
  // --------------
  //    AA    BB    CC    DD
  //    ---   ---   ---   --- 
  //   | R | | G | | B | | A |
  //   |---| |---| |---| |---|
  //     3     2     1      0
  // --------------
  // See how R is on the far left and A is on the far right?
  // It means we have to bring R back down to one byte.
  // Look at those numbers underneath, index 0, 1, 2, 3.
  // Not only are they an index, theyre also a weight.
  // This means we have to shift right by 3 bytes to get R.
  // Again bit shifts, like the name, shift in bits.
  // How many bits are 3 bytes? 3*8 = 24 bits.
  // --------------
  // Alright, were done explaining the bit-shifts, now to explain the bitwise AND operator.
  // If youve done C/C++ before, you probably know & as the addressof operator.
  // It has one more use tho, when & sits in between two numbers it turns into bitwise AND.
  // What it does is it goes over both numbers bit by bit,
  // And it only keeps a 1 where both numbers have 1, anything else becomes 0.
  // Quick example:
  // --------------
  //   1010
  // & 1100
  // result: 1000 (only the spot where both ones align survives).
  // --------------
  // 0xFF is 8 ones in a row: 11111111.
  // ANDing anything with 0xFF is basically a filter, it says "keep
  // whatevers in the last 8 bits, and force everything above that
  // straight to 0", theres no other way to get a 1 out the other
  // side unless 0xFF also had a 1 there, and it only does in the
  // last 8 spots. thats why people call this "masking", 0xFF is
  // literally masking off everything except the byte we want.
  // Heres an example (for finding the blue channel):
  // --------------
  //         10101010 10111011   (0x0000AABB, after >> 16)
  // &       00000000 11111111   (0xFF)
  // result: 00000000 10111011   (0x000000BB)
  // --------------
  // At the very end, we dont have to shift A at all.
  // Because it already is at the right spot.
  // --------------
  uint8_t r = (hex >> 24)&0xFF;
  uint8_t g = (hex >> 16)&0xFF;
  uint8_t b = (hex >> 8)&0xFF;
  uint8_t a = hex;
  // --------------
  return (Kolor){r, g, b, a};
}
// -------------------------------------
Kolor kl_from_hsv(float h, float s, float v)
{
  // Credit: Alvy Ray Smith
  // --------------
  h = km_clampf(h, 0.0f, 1.0f);
  s = km_clampf(s, 0.0f, 1.0f);
  v = km_clampf(v, 0.0f, 1.0f);
  // --------------
  h *= 360.0f;
  // --------------
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
Kolor kl_from_cmyk(float c, float m, float y, float k)
{
  // Credit: James Clerk Maxwell & Albert Henry
  // --------------
  c = km_clampf(c, 0.0f, 1.0f);
  m = km_clampf(m, 0.0f, 1.0f);
  y = km_clampf(y, 0.0f, 1.0f);
  k = km_clampf(k, 0.0f, 1.0f);
  // --------------
  uint8_t r = (uint8_t)(255.0f*(1.0f-c)*(1.0f-k));
  uint8_t g = (uint8_t)(255.0f*(1.0f-m)*(1.0f-k));
  uint8_t b = (uint8_t)(255.0f*(1.0f-y)*(1.0f-k));
  // --------------
  return (Kolor){r, g, b, 255};
}
// -------------------------------------
// The file encoders/decoders are not commented yet.
// Im waiting to implement QOI and then comment everything.
// -------------------------------------
void kf_ppm_write(Kanvas* kv, const char* path)
{
  // Credit: "Jeff Poskanzer" for creating the file format.
  //--------------
  FILE* f = fopen(path, "wb");
  if (!f) return;
  //--------------
  fprintf(f, "P6\n%zu %zu\n255\n", kv->w, kv->h);
  //--------------
  for (size_t i = 0; i < kv->w*kv->h; ++i)
  {
    fputc(kv->pixels[i].r, f);
    fputc(kv->pixels[i].g, f);
    fputc(kv->pixels[i].b, f);
  }
  //--------------
  fclose(f);
}
// -------------------------------------
Kanvas* kf_ppm_read(const char* path)
{
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
}
// -------------------------------------
void kf_tga_write(Kanvas* kv, const char* path)
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

    while (i+run < pixel_count && run < 128 && kl_compare_rgb(kv->pixels[i], kv->pixels[i+run])) ++run;

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

          if (kl_compare_rgb(a, b)) break;
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
Kanvas* kf_tga_read(const char* path)
{
  FILE* f = fopen(path, "rb");
  if (!f) return NULL;
  //--------------
  uint8_t idlength      = fgetc(f);
  uint8_t colormap      = fgetc(f);
  uint8_t datatype_code = fgetc(f);
  //--------------
  fseek(f, 5, SEEK_CUR);
  fseek(f, 4, SEEK_CUR);
  //--------------
  uint16_t width      = fgetc(f) | (fgetc(f) << 8);
  uint16_t height     = fgetc(f) | (fgetc(f) << 8);
  //--------------
  uint8_t  bpp        = fgetc(f);
  uint8_t  descriptor = fgetc(f);
  //--------------
  Kanvas* kv = kv_init((size_t)width, (size_t)height);
  size_t pixel_count = kv->w*kv->h;
  //--------------
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
        //--------------
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
        //--------------
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
        //--------------
        uint8_t b = ( px & 0x1F)           << 3;
        uint8_t g = ((px >> 5  ) & 0x1F)   << 3;
        uint8_t r = ((px >> 10 ) & 0x1F)   << 3;
        //--------------
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
        //--------------
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
          //--------------
          kv->pixels[i++] = (Kolor){r, g, b, a};
        }
      }
    }
  }

  fclose(f);
  return kv;
}
// -------------------------------------
Vek2 km_vek2_zero(void)
{
  return (Vek2){0.0f, 0.0f};
}
// -------------------------------------
Vek2 km_vek2_one(void)
{
  return (Vek2){1.0f, 1.0f};
}
// -------------------------------------
Vek2 km_vek2_add(Vek2 v0, Vek2 v1)
{
  return (Vek2){v0.x+v1.x, v0.y+v1.y};
}
// -------------------------------------
Vek2 km_vek2_addval(Vek2 v0, float value)
{
  return (Vek2){v0.x+value, v0.y+value};
}
// -------------------------------------
Vek2 km_vek2_sub(Vek2 v0, Vek2 v1)
{
  return (Vek2){v0.x-v1.x, v0.y-v1.y};
}
// -------------------------------------
Vek2 km_vek2_subval(Vek2 v0, float value)
{
  return (Vek2){v0.x-value, v0.y-value};
}
// -------------------------------------
Vek2 km_vek2_scale(Vek2 v0, float scalar)
{
  return (Vek2){v0.x*scalar, v0.y*scalar};
}
// -------------------------------------
Vek2 km_vek2_rotate(Vek2 v0, Vek2 center, float angle)
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
float km_vek2_len(Vek2 v0)
{
  return sqrtf(pow(v0.x, 2)+pow(v0.y, 2));
}
// -------------------------------------
Vek2 km_vek2_min(Vek2 v0, Vek2 v1)
{
  float min_x = KMIN(v0.x, v1.x);
  float min_y = KMIN(v0.y, v1.y);
  return (Vek2){min_x, min_y};
}
// -------------------------------------
Vek2 km_vek2_max(Vek2 v0, Vek2 v1)
{
  float max_x = KMAX(v0.x, v1.x);
  float max_y = KMAX(v0.y, v1.y);
  return (Vek2){max_x, max_y};
}
// -------------------------------------
Vek2 km_vek2_nrm(Vek2 v0)
{
  float vek_len = km_vek2_len(v0);
  float nrm_x = v0.x/vek_len;
  float nrm_y = v0.y/vek_len;
  return (Vek2){nrm_x, nrm_y};
}
// -------------------------------------
Vek2 km_vek2_lerp(Vek2 v0, Vek2 v1, float t)
{
  float lerp_x = km_lerp(v0.x, v1.x, t);
  float lerp_y = km_lerp(v0.y, v1.y, t);
  return (Vek2){lerp_x, lerp_y};
}
// -------------------------------------
Vek3 km_vek3_zero(void)
{
  return (Vek3){0.0f, 0.0f, 0.0f};
}
// -------------------------------------
Vek3 km_vek3_one(void)
{
  return (Vek3){1.0f, 1.0f, 1.0f};
}
// -------------------------------------
Vek3 km_vek3_add(Vek3 v0, Vek3 v1)
{
  return (Vek3){v0.x+v1.x, v0.y+v1.y, v0.z+v1.z};
}
// -------------------------------------
Vek3 km_addval(Vek3 v0, float value)
{
  return (Vek3){v0.x+value, v0.y+value, v0.z+value};
}
// -------------------------------------
Vek3 km_vek3_sub(Vek3 v0, Vek3 v1)
{
  return (Vek3){v0.x-v1.x, v0.y-v1.y, v0.z-v1.z};
}
// -------------------------------------
Vek3 km_vek3_subval(Vek3 v0, float value)
{
  return (Vek3){v0.x-value, v0.y-value, v0.z-value};
}
// -------------------------------------
Vek3 km_vek3_scale(Vek3 v0, float scalar)
{
  return (Vek3){v0.x*scalar, v0.y*scalar, v0.z*scalar};
}
// -------------------------------------
float km_vek3_dot(Vek3 v0, Vek3 v1)
{
  return v0.x*v1.x+v0.y*v1.y+v0.z*v1.z;
}
// -------------------------------------
float km_vek3_len(Vek3 v0)
{
  return sqrtf(pow(v0.x, 2)+pow(v0.y, 2)+pow(v0.z, 2));
}
// -------------------------------------
Vek3 km_vek3_min(Vek3 v0, Vek3 v1)
{
  float min_x = KMIN(v0.x, v1.x);
  float min_y = KMIN(v0.y, v1.y);
  float min_z = KMIN(v0.z, v1.z);
  return (Vek3){min_x, min_y, min_z};
}
// -------------------------------------
Vek3 km_vek3_max(Vek3 v0, Vek3 v1)
{
  float max_x = KMAX(v0.x, v1.x);
  float max_y = KMAX(v0.y, v1.y);
  float max_z = KMAX(v0.z, v1.z);
  return (Vek3){max_x, max_y, max_z};
}
// -------------------------------------
Vek3 km_vek3_nrm(Vek3 v0)
{
  float vek_len = km_vek3_len(v0);
  float nrm_x = v0.x/vek_len;
  float nrm_y = v0.y/vek_len;
  float nrm_z = v0.z/vek_len;
  return (Vek3){nrm_x, nrm_y, nrm_z};
}
// -------------------------------------
Vek3 km_vek3_cross(Vek3 v0, Vek3 v1)
{
  return (Vek3){v0.y*v1.z-v0.z*v1.y, v0.z*v1.x-v0.x*v1.z, v0.x*v1.y-v0.y*v1.x};
}
// -------------------------------------
Vek3 km_vek3_lerp(Vek3 v0, Vek3 v1, float t)
{
  float lerp_x = km_lerp(v0.x, v1.x, t);
  float lerp_y = km_lerp(v0.y, v1.y, t);
  float lerp_z = km_lerp(v0.z, v1.z, t);
  return (Vek3){lerp_x, lerp_y, lerp_z};
}
// -------------------------------------
Vek2 km_vek2_screen2norm(Vek2 kv, Vek2 screen)
{
  float normx = (screen.x+1)/2 * kv.x;
  float normy = (1-(screen.y+1)/2) * kv.x;
  return (Vek2){normx, normy};
}
// -------------------------------------
Vek2 km_vek2_normal2screen(Vek2 normal, Vek2 kv)
{
  float screenx = normal.x*2 / kv.x;
  float screeny = (1+normal.y)*2 / kv.y;
  return (Vek2){screenx, screeny};
}
// -------------------------------------
Vek2 km_vek2_cartesian2screen(Vek2 cartesian, Vek2 kv, float scale)
{
  float screenx = cartesian.x*scale+kv.x/2;
  float screeny = kv.y/2-cartesian.y*scale;
  return (Vek2){screenx, screeny};
}
// -------------------------------------
Vek2 km_vek2_screen2cartesian(Vek2 screen, Vek2 kv, float scale)
{
  float cartesianx = (screen.x-kv.x/2)/scale;
  float cartesiany = (-screen.y+kv.y/2)/scale;
  return (Vek2){cartesianx, cartesiany};
}
// -------------------------------------
Vek2 km_vek2_screen2uv(Vek2 screen, Vek2 kv)
{
  float uv_x = screen.x/(float)kv.x;
  float uv_y = screen.y/(float)kv.y;
  return (Vek2){uv_x, uv_y};
}
// -------------------------------------
Vek2 km_vek2_uv2screen(Vek2 uv, Vek2 kv)
{
  float screen_x = uv.x*(kv.x-1);
  float screen_y = uv.y*(kv.y-1);
  return (Vek2){screen_x, screen_y};
}
// -------------------------------------
Vek2 km_vek3_project(Vek3 v0)
{
  return (Vek2){v0.x/v0.z, v0.y/v0.z};
}
// -------------------------------------
float km_vek2_dot(Vek2 v0, Vek2 v1)
{
  return v0.x*v1.x+v0.y*v1.y;
}
// -------------------------------------
float  km_vek2_cross(Vek2 v0, Vek2 v1)
{
  return (v0.x*v1.y)-(v0.y*v1.x);
}
// -------------------------------------
Vek3 km_vek3_translate_x(Vek3 v0, float dx)
{
  return (Vek3){v0.x+dx, v0.y, v0.z};
}
// -------------------------------------
Vek3 km_vek3_translate_y(Vek3 v0, float dy)
{
  return (Vek3){v0.x, v0.y+dy, v0.z};
}
// -------------------------------------
Vek3 km_vek3_translate_z(Vek3 v0, float dz)
{
  return (Vek3){v0.x, v0.y, v0.z+dz};
}
// -------------------------------------
Vek3 km_vek3_rotate_y(Vek3 v0, float angle)
{
  float cosa = cosf(angle);
  float sina = sinf(angle);
  return (Vek3){ v0.x*cosa - v0.z*sina, v0.y, v0.x*sina + v0.z*cosa };
}
// -------------------------------------
Vek3 km_vek3_rotate_x(Vek3 v0, float angle)
{
  float cos_a = cosf(angle);
  float sin_a = sinf(angle);
  return (Vek3){v0.x, v0.y*cos_a - v0.z*sin_a, v0.y*sin_a + v0.z*cos_a};
}
// -------------------------------------
Vek2 km_bezier_quad(Vek2 p1, Vek2 control_p, Vek2 p2, float t)
{
  Vek2 a = km_vek2_lerp(p1, control_p, t);
  Vek2 b = km_vek2_lerp(control_p, p2, t);
  Vek2 lerped = km_vek2_lerp(a, b, t);
  return lerped;
}
// -------------------------------------
Vek2 km_bezier_cube(Vek2 p1, Vek2 control_p1, Vek2 control_p2, Vek2 p2, float t)
{
  Vek2 a       = km_vek2_lerp(p1, control_p1, t);
  Vek2 b       = km_vek2_lerp(control_p1, control_p2, t);
  Vek2 c       = km_vek2_lerp(control_p2, p2, t);
  Vek2 lerp_a = km_vek2_lerp(a, b, t);
  Vek2 lerp_b = km_vek2_lerp(b, c, t);
  Vek2 lerped = km_vek2_lerp(lerp_a, lerp_b, t);
  return lerped;
}
// -------------------------------------
float km_lerp(float start, float end, float t)
{
  return start+(end-start)*t;
}
// -------------------------------------
float km_cerp(float x0, float x1, float x2, float x3, float t)
{
  float a = (3.0f*x1-3.0f*x2+x3-x0)/2.0f;
  float b = (2.0f*x0-5.0f*x1+4.0f*x2-x3)/2.0f;
  float c = (x2-x0)/2.0f;
  float d = x1;
  return ((a*t+b)*t+c)*t+d;
}
// -------------------------------------
static float km_noise_hash_2d(int x, int y)
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
static Vek2 km_noise_hash_gradient_2d(int x, int y)
{
  float rand_val = km_noise_hash_2d(x, y);
  float theta    = rand_val*2*KPI;
  float gradient_x = cosf(theta);
  float gradient_y = sinf(theta);
  return (Vek2){gradient_x, gradient_y};
}
// -------------------------------------
static float km_noise_hash_3d(int x, int y, int z)
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
static Vek3 km_noise_hash_gradient_3d(int x, int y, int z)
{
  float rand_val0    = km_noise_hash_3d(x, y, z);
  float rand_val1    = km_noise_hash_3d(x+12345, y+67890, z+54321);
  float theta        = acosf(rand_val0*2.0f-1.0f);
  float phi          = rand_val1*2.0f*KPI;
  float gradient_x   = cosf(phi)*sinf(theta);
  float gradient_y   = sinf(phi)*sinf(theta);
  float gradient_z   = cosf(theta);
  return (Vek3){gradient_x, gradient_y, gradient_z};
}
// -------------------------------------
static float km_noise_2d_value(float x, float y)
{
  // Credit: Computer Graphics community.
  //--------------
  // We are getting the neighbors of the x/y pixels.
  // Say x: 255.5, x0 is 255, x1 is 256.
  // y: 345.75, y0 is 345, y1 is 346.
  // We can then use those values to generate 4 random points.
  // These 4 random points, represent a rectangle.
  //--------------
  int x0 = x;
  int y0 = y;
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
  //--------------
  float u = x-x0;
  float v = y-y0;
  //--------------
  // Now we can literally treat u/v like t inside a lerp function.
  // This means can modify it just like t.
  // We modify it because plain UV looks too harsh.
  // So we smoothen it out with easing functions.
  // Use whichever one you feel like, experiment with it.
  // You should even remove fade_u/v and use plain u/v.
  // This will show you a lot more clearly why we smoothen it out.
  // It doesnt look drastically better, but it looks better.
  //--------------
  float fade_u = km_ease_in_out_quint(u);
  float fade_v = km_ease_in_out_quint(v);
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
  //--------------
  float top_left       = km_noise_hash_2d(x0, y0);
  float top_right      = km_noise_hash_2d(x1, y0);
  float bottom_left    = km_noise_hash_2d(x0, y1);
  float bottom_right   = km_noise_hash_2d(x1, y1);
  //--------------
  // What we are doing here is called bilinear interpolation.
  // If youve done bilinear interpolation for image scaling before,
  // this will click instantly, because we are doing the same thing,
  // just with random coordinates.
  // First we lerp from left-right horizontally.
  // Then we lerp again from left-right horizontally but on the bottom.
  // Lastly we lerp from top-bottom vertically.
  //--------------
  float row_top      = km_lerp(top_left, top_right, fade_u);
  float row_bottom   = km_lerp(bottom_left, bottom_right, fade_u);
  return km_lerp(row_top, row_bottom, fade_v);
  //--------------
  // Thats it, thats Value Noise.
  // Sounds hard and complicated, but its just because explanations of it online suck.
  //--------------
}
// -------------------------------------
static float km_noise_2d_value_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  // Credit: Benoit Mandelbrot & John W. Van Ness for the mathematical concept.
  // Credit: Ken Perlin & Inigo Quilez for bringing it to computer graphics.
  //--------------
  // Really quick, if you go online now and search for fbm,
  // Your eyes will be met with very, very pretentious names,
  // layer_count is called "octaves",
  // frequency_multiplier is "lacunarity",
  // amplitude is "gain".
  //--------------
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
  for (int i = 0; i < layer_count; ++i)
  {
    //--------------
    // Multiply our coordinates by the frequency to scale the detail.
    //--------------
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    //--------------
    // Get the noise value for this layer.
    // Multiply it by its strength (amplitude).
    // Then add it to our running total.
    //--------------
    total += km_noise_2d_value(sample_x, sample_y)*amplitude;
    // Add the current strength to our maximum possible value tracker.
    max_value += amplitude;
    // Make the next layer have tighter, smaller details.
    frequency *= frequency_multiplier;
    // Make the next layer much weaker so it doesnt overpower the main shape.
    amplitude *= amplitude_multiplier;
    //--------------
  }
  //--------------
  // Divide the total by the maximum possible value.
  // This safely keeps our final answer between 0.0-1.0.
  //--------------
  return total/max_value;
  //--------------
}
// -------------------------------------
static float km_noise_2d_perlin(float x, float y)
{
  // Credit: Ken Perlin.
  //--------------
  // Now that we know how Value Noise grids and fractional offsets (u/v) work,
  // Perlin Noise takes this a step further.
  // Instead of interpolating random values at the corners,
  // Perlin Noise assigns random direction vectors also known as gradients,
  // We use the exact same u/v logic from before but now we also calculate dot products.
  //--------------
  int x0 = x;
  int y0 = y;
  int x1 = x0+1;
  int y1 = y0+1;
  float u = x-x0;
  float v = y-y0;
  float fade_u = km_ease_in_out_quint(u);
  float fade_v = km_ease_in_out_quint(v);
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
  //--------------
  Vek2 g00 = km_noise_hash_gradient_2d(x0, y0);
  Vek2 g10 = km_noise_hash_gradient_2d(x1, y0);
  Vek2 g01 = km_noise_hash_gradient_2d(x0, y1);
  Vek2 g11 = km_noise_hash_gradient_2d(x1, y1);
  //--------------
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
  //--------------
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
  //--------------
  float n00 = km_vek2_dot(g00, d00);
  float n10 = km_vek2_dot(g10, d10);
  float n01 = km_vek2_dot(g01, d01);
  float n11 = km_vek2_dot(g11, d11);
  //--------------
  // Again, more bilinear interpolation, horizontally left-right.
  // Then vertically top-bottom.
  //--------------
  float row_top     = km_lerp(n00, n10, fade_u);
  float row_bottom   = km_lerp(n01, n11, fade_u);
  float finalised    = km_lerp(row_top, row_bottom, fade_v);
  //--------------
  // Now here is something new, normalising the output.
  // Value Noise always interpolates from 0-1 so its always in range.
  // Perlin Noise uses dot products, which can output negative numbers.
  // In a 2D grid the max distance to the center of a cell is 0.707 (or atleast the internet says so).
  // This means the raw "finalised" value lands between -0.707 to +0.707
  // To get a clean 0-1 range, we are normalising it.
  //--------------
  float normalised   = (finalised+0.707f)/1.414f;
  normalised = km_clampf(normalised, 0.0f, 1.0f);
  return normalised;
  //--------------
}
// -------------------------------------
static float km_noise_2d_perlin_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier)
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
    total += km_noise_2d_perlin(sample_x, sample_y)*amplitude;
    max_value += amplitude;
    frequency *= frequency_multiplier;
    amplitude *= amplitude_multiplier;
    //--------------
  }
  return total/max_value;
}
// -------------------------------------
static float km_noise_3d_value(float x, float y, float z)
{  
  //--------------
  // 3D Value Noise is a copy of 2D Value Noise.
  // The only difference is that we now also calculate z.
  // Same thing for u/v we introduce a new variable w,
  // which acts just like u/v do but for the z coordinate.
  // So u for x, v for y, w for z.
  //--------------
  int x0 = x;
  int y0 = y;
  int z0 = z;
  int x1 = x0+1;
  int y1 = y0+1;
  int z1 = z0+1;
  float u = x-x0;
  float v = y-y0;
  float w = z-z0;
  float fade_u = km_ease_in_out_quint(u);
  float fade_v = km_ease_in_out_quint(v);
  float fade_w = km_ease_in_out_quint(w);
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
  float front_top_left      = km_noise_hash_3d(x0, y0, z0);
  float front_top_right     = km_noise_hash_3d(x1, y0, z0);
  float front_bottom_left   = km_noise_hash_3d(x0, y1, z0);
  float front_bottom_right  = km_noise_hash_3d(x1, y1, z0);
  //--------------
  float back_top_left       = km_noise_hash_3d(x0, y0, z1);
  float back_top_right      = km_noise_hash_3d(x1, y0, z1);
  float back_bottom_left    = km_noise_hash_3d(x0, y1, z1);
  float back_bottom_right   = km_noise_hash_3d(x1, y1, z1);
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
  float front_top     = km_lerp(front_top_left, front_top_right, fade_u);
  float front_bottom  = km_lerp(front_bottom_left, front_bottom_right, fade_u);
  float front_face    = km_lerp(front_top, front_bottom, fade_v);
  //--------------
  float back_top      = km_lerp(back_top_left, back_top_right, fade_u);
  float back_bottom   = km_lerp(back_bottom_left, back_bottom_right, fade_u);
  float back_face     = km_lerp(back_top, back_bottom, fade_v);
  //--------------
  return km_lerp(front_face, back_face, fade_w);
  //--------------
}
// -------------------------------------
static float km_noise_3d_value_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  //--------------
  // And here we do the same thing, its just like 2D FBM but with a z value.
  // The only thing that changes is that we now also sample the z value.
  // Everything else stays exactly the same.
  //--------------
  float total = 0.0f;
  float amplitude = 1.0f;
  float frequency = 1.0f;
  float max_value = 0.0f;
  //--------------
  for (int i = 0; i < layer_count; ++i)
  {
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    float sample_z = z*frequency;
    //--------------
    total += km_noise_3d_value(sample_x, sample_y, sample_z)*amplitude;
    max_value += amplitude;
    frequency *= frequency_multiplier;
    amplitude *= amplitude_multiplier;
  }

  return total/max_value;
}
// -------------------------------------
static float km_noise_3d_perlin(float x, float y, float z)
{
  // Credit: Ken Perlin.
  //--------------
  // This is also just like 2D Perlin Noise, but with a z value.
  int x0 = x;
  int y0 = y;
  int z0 = z;
  int x1 = x0+1;
  int y1 = y0+1;
  int z1 = z0+1;
  float u = x-x0;
  float v = y-y0;
  float w = z-z0;
  float fade_u = km_ease_in_out_quint(u);
  float fade_v = km_ease_in_out_quint(v);
  float fade_w = km_ease_in_out_quint(w);
  //--------------
  // Alright, remember what we said about 2D Perlin Noise?
  // How it uses direction vectors (Gradients),
  // Distance vectors, dot products, normalisation, etc?
  // Well here we do exactly that, with a few extra steps.
  // When in 2D we thought of the pixels generated as 4 corners of a rectangle.
  // Now they are the 8 corners of a cube.
  // And again just like we said for 3D Value Noise, we use the exact same variables,
  // and batch them in two groups, the z0 group, and the z1 group.
  //--------------
  Vek3 g000   = km_noise_hash_gradient_3d(x0, y0, z0);
  Vek3 g100   = km_noise_hash_gradient_3d(x1, y0, z0);
  Vek3 g010   = km_noise_hash_gradient_3d(x0, y1, z0);
  Vek3 g110   = km_noise_hash_gradient_3d(x1, y1, z0);
  //--------------
  Vek3 g001   = km_noise_hash_gradient_3d(x0, y0, z1);
  Vek3 g101   = km_noise_hash_gradient_3d(x1, y0, z1);
  Vek3 g011   = km_noise_hash_gradient_3d(x0, y1, z1);
  Vek3 g111   = km_noise_hash_gradient_3d(x1, y1, z1);
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
  //--------------
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
  float n000 = km_vek3_dot(g000, d000);
  float n100 = km_vek3_dot(g100, d100);
  float n010 = km_vek3_dot(g010, d010);
  float n110 = km_vek3_dot(g110, d110);
  float n001 = km_vek3_dot(g001, d001);
  float n101 = km_vek3_dot(g101, d101);
  float n011 = km_vek3_dot(g011, d011);
  float n111 = km_vek3_dot(g111, d111);
  //--------------
  // Now we trilinearly interpolate.
  float front_top     = km_lerp(n000, n100, fade_u);
  float front_bottom  = km_lerp(n010, n110, fade_u);
  float front_face    = km_lerp(front_top, front_bottom, fade_v);
  float back_top      = km_lerp(n001, n101, fade_u);
  float back_bottom   = km_lerp(n011, n111, fade_u);
  float back_face     = km_lerp(back_top, back_bottom, fade_v);
  // Then we blend the front and back faces along the z-axis.
  float finalised     = km_lerp(front_face, back_face, fade_w);
  //--------------
  // Now for 2D the max distance was -0.707 to +0.707,
  // For 3D it is -0.866 to +0.866.
  // We normalise it and were good to go.
  //--------------
  float normalised    = (finalised+0.866f)/1.732f;
  normalised = km_clampf(normalised, 0.0f, 1.0f);
  return normalised;
  //--------------
}
// -------------------------------------
static float km_noise_3d_perlin_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier)
{
  float total = 0.0f;
  float amplitude = 1.0f;
  float frequency = 1.0f;
  float max_value = 0.0f;
  //--------------
  for (int i = 0; i < layer_count; ++i)
  {
    float sample_x = x*frequency;
    float sample_y = y*frequency;
    float sample_z = z*frequency;
    //--------------
    total += km_noise_3d_perlin(sample_x, sample_y, sample_z)*amplitude;
    max_value += amplitude;
    frequency *= frequency_multiplier;
    amplitude *= amplitude_multiplier;
  }
  //--------------
  // Divide the total by the maximum possible value.
  // This safely keeps our final answer between 0.0-1.0.
  //--------------
  return total/max_value;
}
// -------------------------------------
float km_noise_2d(float x, float y, KNoiseType type)
{
  if (type == KNOISE_VALUE)       return km_noise_2d_value(x, y);
  else if (type == KNOISE_PERLIN) return km_noise_2d_perlin(x, y);
  return 0.0f;
}
// -------------------------------------
float km_noise_2d_fbm(float x, float y, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type)
{
  if (type == KNOISE_VALUE)       return km_noise_2d_value_fbm(x, y, layer_count, frequency_multiplier, amplitude_multiplier);
  else if (type == KNOISE_PERLIN) return km_noise_2d_perlin_fbm(x, y, layer_count, frequency_multiplier, amplitude_multiplier);
  return 0.0f;
}
// -------------------------------------
float km_noise_3d(float x, float y, float z, KNoiseType type)
{
  if (type == KNOISE_VALUE)       return km_noise_3d_value(x, y, z);
  else if (type == KNOISE_PERLIN) return km_noise_3d_perlin(x, y, z);
  return 0.0f;
}
// -------------------------------------
float km_noise_3d_fbm(float x, float y, float z, int layer_count, float frequency_multiplier, float amplitude_multiplier, KNoiseType type)
{
  if (type == KNOISE_VALUE)       return km_noise_3d_value_fbm(x, y, z, layer_count, frequency_multiplier, amplitude_multiplier);
  else if (type == KNOISE_PERLIN) return km_noise_3d_perlin_fbm(x, y, z, layer_count, frequency_multiplier, amplitude_multiplier);
  return 0.0f;
}
// -------------------------------------
float km_cv_rad2deg(float angle_in_radians)
{
  return angle_in_radians*(180.0f/KPI);
}
// -------------------------------------
float km_cv_deg2rad(float angle_in_degrees)
{
  return angle_in_degrees*(KPI/180.0f);
}
// -------------------------------------
int km_clamp(int value, int min, int max)
{
  if (value < min)        value = min;
  else if (value > max)   value = max;
  return value;
}
// -------------------------------------
float km_clampf(float value, float min, float max)
{
  if (value < min)        value = min;
  else if (value > max)   value = max;
  return value;
}
// -------------------------------------
double km_clampd(double value, double min, double max)
{
  if (value < min)        value = min;
  else if (value > max)   value = max;
  return value;
}
// -------------------------------------
bool km_hit_rect_rect(int rect0_x, int rect0_y, size_t rect0_w, size_t rect0_h, int rect1_x, int rect1_y, size_t rect1_w, size_t rect1_h)
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
bool km_hit_rect_rectv(Vek2 rect0, Vek2 rect0_size, Vek2 rect1, Vek2 rect1_size)
{
  return km_hit_rect_rect(rect0.x, rect0.y, rect0_size.x, rect0_size.y,
                                  rect1.x, rect1.y, rect1_size.x, rect1_size.y);
}
// -------------------------------------
bool km_hit_rect_rectr(Rekt rect0, Rekt rect1)
{
  return km_hit_rect_rect(rect0.x, rect0.y, rect0.w, rect0.h,
                                  rect1.x, rect1.y, rect1.w, rect1.h);
}
// -------------------------------------
bool km_hit_rect_circle(int rect_x, int rect_y, size_t rect_w, size_t rect_h, int cx, int cy, size_t r)
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
bool km_hit_rect_circlev(Vek2 rect, Vek2 rect_size, Vek2 center, size_t r)
{
  return km_hit_rect_circle(rect.x, rect.y, rect_size.x, rect_size.y,
                                    center.x, center.y, r);
}
// -------------------------------------
bool km_hit_rect_circler(Rekt rect, Vek2 center, size_t r)
{
  return km_hit_rect_circle(rect.x, rect.y, rect.w, rect.h,
                                    center.x, center.y, r);
}
// -------------------------------------
#endif // KROSS_IMPLEMENTATION_GUARD
#endif // KROSS_IMPLEMENTATION
// -------------------------------------
