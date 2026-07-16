// -------------------------------------
#define KROSS_IMPLEMENTATION
#define KROSS_STRIP_PREFIX
#include "kross.h"
// -------------------------------------
// These two functions live inisde Kross but they are static, so Ill just copy them here since I need them.
// -------------------------------------
bool math_triangle_edge_is_top_left(Vek2 start, Vek2 end)
{
  Vek2 edge = kross_math_vek2_sub(start, end);
  bool is_top_edge = edge.y == 0 && edge.x > 0;
  bool is_left_edge = edge.y < 0;
  return is_top_edge || is_left_edge;
}
// -------------------------------------
int math_triangle_edge_func(Vek2 p1, Vek2 p2, Vek2 px)
{
  Vek2 p12 = kross_math_vek2_sub(p1, p2);
  Vek2 p1px = kross_math_vek2_sub(px, p1);
  return p12.x*p1px.y - p12.y*p1px.x;
}
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Barycentric Triangle");
  kw_target_fps(60);

  Vek2 v0 = {kv->w*0.5f, kv->h*0.25f};
  Vek2 v1 = {kv->w*0.25f, kv->h*0.75f};
  Vek2 v2 = {kv->w-kv->w*0.25f, kv->h*0.75f};
  Vek2 p0 = {kv->w*0.5f, kv->h*0.5f};
  Kolor kolor_p0 = KLEAN_YELLOW;
  Kolor kolor_interpolated = KLEAN_RED;

  Vek2 sv0 = {kv->w*0.10f, kv->h*0.65f};
  Vek2 sv1 = {kv->w*0.05f, kv->h*0.75f};
  Vek2 sv2 = {kv->w*0.15f, kv->h*0.75f};

  Vek2 min = km_vek2_min(v0, km_vek2_min(v1, v2));
  Vek2 max = km_vek2_max(v0, km_vek2_max(v1, v2));

  float area = math_triangle_edge_func(v0, v1, v2);
  float w0 = 0.0f;
  float w1 = 0.0f;
  float w2 = 0.0f;
  bool is_inside = true;

  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);

    if (ki_down(KI_F))
    {
      kv_triangle(kv, min, v1, v0, KLEAN_ORANGE);
      kv_triangle(kv, (Vek2){max.x, min.y}, v0, v2, KLEAN_PURPLE);
    }
    if (ki_down(KI_TAB))
    {
      kv_rect_strokev(kv, min, km_vek2_sub(max, min), 1, KLEAN_YELLOW);
    }
    if (ki_down(KI_LSHIFT)) p0 = ki_mouse_pos();

    w0 = math_triangle_edge_func(v1, v2, p0)/area;
    w1 = math_triangle_edge_func(v2, v0, p0)/area;
    w2 = math_triangle_edge_func(v0, v1, p0)/area;
    is_inside = (w0 >= 0 && w1 >= 0 && w2 >= 0);
    kolor_interpolated.r = w0*KLEAN_RED.r+w1*KLEAN_GREEN.r+w2*KLEAN_BLUE.r;
    kolor_interpolated.g = w0*KLEAN_RED.g+w1*KLEAN_GREEN.g+w2*KLEAN_BLUE.g;
    kolor_interpolated.b = w0*KLEAN_RED.b+w1*KLEAN_GREEN.b+w2*KLEAN_BLUE.b;

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

    kv_triangle(kv, sv0, sv1, sv2, kolor_interpolated);
    kv_linev(kv, p0, v0, 1, kolor_p0);
    kv_linev(kv, p0, v1, 1, kolor_p0);
    kv_linev(kv, p0, v2, 1, kolor_p0);
    kv_circlev(kv, p0, 5, kolor_p0);

    kv_stop(kv); 
  }

  kw_free();
  kv_free(kv);
}
