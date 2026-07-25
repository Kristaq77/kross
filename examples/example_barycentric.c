// -------------------------------------
#define KROSS_IMPLEMENTATION
#include "kross.h"
// -------------------------------------
bool math_triangle_edge_is_top_left(Vek2 start, Vek2 end)
{
  Vek2 edge         = km_vek2_sub(start, end);
  bool is_top_edge  = edge.y == 0 && edge.x > 0;
  bool is_left_edge = edge.y < 0;
  return is_top_edge || is_left_edge;
}
// -------------------------------------
int math_triangle_edge_func(Vek2 p1, Vek2 p2, Vek2 px)
{
  Vek2 p12  = km_vek2_sub(p1, p2);
  Vek2 p1px = km_vek2_sub(px, p1);
  return p12.x*p1px.y - p12.y*p1px.x;
}
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Barycentric Triangle");
  kw_target_fps(60);
  //--------------
  Vek2 v0 = {kv->w*0.5f, kv->h*0.35f};
  Vek2 v1 = {kv->w*0.25f, kv->h*0.85f};
  Vek2 v2 = {kv->w-kv->w*0.25f, kv->h*0.85f};
  Vek2 p0 = {kv->w*0.5f, kv->h*0.65f};
  //--------------
  Kolor kolor_p0 = KLEAN_YELLOW;
  Kolor kolor_interpolated = KLEAN_RED;
  //--------------
  Vek2 min = km_vek2_min(v0, km_vek2_min(v1, v2));
  Vek2 max = km_vek2_max(v0, km_vek2_max(v1, v2));
  //--------------
  float area = math_triangle_edge_func(v0, v1, v2);
  float w0 = 0.0f;
  float w1 = 0.0f;
  float w2 = 0.0f;
  bool is_inside = true;
  //--------------
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);
    //--------------
    if (ki_down(KI_F))
    {
      kv_triangle(kv, min, v1, v0, KLEAN_ORANGE);
      kv_triangle(kv, (Vek2){max.x, min.y}, v0, v2, KLEAN_PURPLE);
    }
    if (ki_down(KI_TAB))    kv_rect_strokev(kv, min, km_vek2_sub(max, min), 1, KLEAN_YELLOW);
    if (ki_down(KI_LSHIFT)) p0 = ki_mouse_pos();
    //--------------
    w0 = math_triangle_edge_func(v1, v2, p0)/area;
    w1 = math_triangle_edge_func(v2, v0, p0)/area;
    w2 = math_triangle_edge_func(v0, v1, p0)/area;
    //--------------
    is_inside = (w0 >= 0 && w1 >= 0 && w2 >= 0);
    //--------------
    kolor_interpolated.r = w0*KLEAN_RED.r+w1*KLEAN_GREEN.r+w2*KLEAN_BLUE.r;
    kolor_interpolated.g = w0*KLEAN_RED.g+w1*KLEAN_GREEN.g+w2*KLEAN_BLUE.g;
    kolor_interpolated.b = w0*KLEAN_RED.b+w1*KLEAN_GREEN.b+w2*KLEAN_BLUE.b;
    //--------------
    if (is_inside)
    {
      kv_triangle(kv, v0, v1, p0, KLEAN_RED);
      kv_triangle(kv, v1, v2, p0, KLEAN_GREEN);
      kv_triangle(kv, v0, p0, v2, KLEAN_BLUE);
      kolor_p0 = KLEAN_YELLOW;
    }
    else
    {
      kv_triangle(kv, v0, v1, v2, KLEAN_GRAY);
      kolor_p0 = KLEAN_RED;
      kolor_interpolated = KLEAN_GRAY;
    }
    //--------------
    kv_linev(kv, p0, v0, 1, kolor_p0);
    kv_linev(kv, p0, v1, 1, kolor_p0);
    kv_linev(kv, p0, v2, 1, kolor_p0);
    //--------------
    kv_circlev(kv, p0, 5, kolor_p0);
    //--------------
    kv_text(kv, v0.x-16, v0.y-35, "V0", 2, KLEAN_RED);
    kv_text(kv, v1.x-40, v1.y+15, "V1", 2, KLEAN_GREEN);
    kv_text(kv, v2.x+15, v2.y+15, "V2", 2, KLEAN_BLUE);
    kv_text(kv, p0.x+15, p0.y+15, "P0", 2, kolor_p0);
    //--------------
    kv_text_multi(kv, 20, 20, "Barycentric Data", 3, 4, (Kolor[]){KLEAN_RED, KLEAN_BLUE, KLEAN_GREEN, KLEAN_YELLOW});
    kv_textf(kv, 20, 65, 2,  KLEAN_RED,   "W0: %.3f", w0);
    kv_textf(kv, 20, 95, 2,  KLEAN_GREEN, "W1: %.3f", w1);
    kv_textf(kv, 20, 125, 2, KLEAN_BLUE,  "W2: %.3f", w2);
    //--------------
    if (is_inside) kv_text(kv, 20, 165, "Status: INSIDE", 2,  KLEAN_GREEN);
    else           kv_text(kv, 20, 165, "Status: OUTSIDE", 2, KLEAN_RED);
    //--------------
    kv_text(kv, 20, 205, "Output Color:", 2, KLEAN_BLUE);
    kv_circlev(kv, (Vek2){250, 213}, 12, kolor_interpolated);
    kv_textf(kv, 20, 235, 2, kolor_interpolated, "R: %d  G: %d  B: %d", (int)kolor_interpolated.r, (int)kolor_interpolated.g, (int)kolor_interpolated.b);
    //--------------
    kv_text(kv, kv->w-350, 20, "Controls", 3,             KLEAN_YELLOW);
    kv_text(kv, kv->w-350, 65, "LSHIFT : Move Point", 2,  KLEAN_RED);
    kv_text(kv, kv->w-350, 95, "TAB    : BBox", 2,        KLEAN_GREEN);
    kv_text(kv, kv->w-350, 125, "F      : Debug", 2,      KLEAN_BLUE);
    //--------------
    kv_stop(kv); 
  }
  //--------------
  kw_free();
  kv_free(kv);
  return 0;
}
