#define KROSS_IMPLEMENTATION
#include "kross.h"
#include <math.h>
// -------------------------------------
#define MAX_VERTICES 512
#define MAX_EDGES 1024
// -------------------------------------
typedef struct {
  int v0;
  int v1;
} Edge;
// -------------------------------------
Vek3 g_points[MAX_VERTICES];
Edge g_edges[MAX_EDGES];
int g_v_count = 0;
int g_e_count = 0;
// -------------------------------------
// WARNING: THIS FILE WAS MADE WITH AI.
// -------------------------------------
void build_cuboid(float cx, float cy, float cz, float w, float h, float d, float slant_z)
{
  int base_v = g_v_count;
  float hw = w * 0.5f;
  float hh = h * 0.5f;
  float hd = d * 0.5f;

  Vek3 local[8] = {
    {+hw, +hh, +hd}, {-hw, +hh, +hd}, {-hw, -hh, +hd}, {+hw, -hh, +hd},
    {+hw, +hh, -hd}, {-hw, +hh, -hd}, {-hw, -hh, -hd}, {+hw, -hh, -hd}
  };

  if (slant_z != 0.0f)
  {
    float c = cosf(slant_z);
    float s = sinf(slant_z);
    for (int i = 0; i < 8; ++i)
    {
      float rx = local[i].x * c - local[i].y * s;
      float ry = local[i].x * s + local[i].y * c;
      local[i].x = rx;
      local[i].y = ry;
    }
  }

  for (int i = 0; i < 8; ++i)
  {
    g_points[base_v + i] = (Vek3){local[i].x + cx, local[i].y + cy, local[i].z + cz};
  }
  g_v_count += 8;

  int e[12][2] = {
    {0,1}, {1,2}, {2,3}, {3,0},
    {4,5}, {5,6}, {6,7}, {7,4},
    {0,4}, {1,5}, {2,6}, {3,7}
  };
  for (int i = 0; i < 12; ++i)
  {
    g_edges[g_e_count].v0 = base_v + e[i][0];
    g_edges[g_e_count].v1 = base_v + e[i][1];
    g_e_count++;
  }
}
// -------------------------------------
void build_octahedron(float cx, float cy, float cz, float size)
{
  int base_v = g_v_count;
  Vek3 local[6] = {
    {0, size, 0}, {0, -size, 0},
    {size, 0, 0}, {-size, 0, 0},
    {0, 0, size}, {0, 0, -size}
  };
  
  for (int i = 0; i < 6; ++i)
  {
    g_points[base_v + i] = (Vek3){local[i].x + cx, local[i].y + cy, local[i].z + cz};
  }
  g_v_count += 6;

  int e[12][2] = {
    {0,2}, {0,3}, {0,4}, {0,5},
    {1,2}, {1,3}, {1,4}, {1,5},
    {2,4}, {4,3}, {3,5}, {5,2}
  };
  for (int i = 0; i < 12; ++i)
  {
    g_edges[g_e_count].v0 = base_v + e[i][0];
    g_edges[g_e_count].v1 = base_v + e[i][1];
    g_e_count++;
  }
}
// -------------------------------------
void init_geometry(void)
{
  g_v_count = 0;
  g_e_count = 0;

  float y_off = -0.10f; 

  build_cuboid(0.0f, 0.15f + y_off, 0.0f, 0.15f, 1.6f, 0.15f, 0.0f);
  build_cuboid(0.0f, 0.65f + y_off, 0.0f, 0.4f, 0.1f, 0.15f, 0.0f);
  build_cuboid(0.0f, 0.3f + y_off, 0.0f, 0.9f, 0.15f, 0.15f, 0.0f);
  build_cuboid(0.0f, -0.25f + y_off, 0.0f, 0.4f, 0.1f, 0.15f, -0.4f);
  build_cuboid(0.0f, -0.7f + y_off, 0.0f, 0.35f, 0.1f, 0.35f, 0.0f);
  build_cuboid(0.0f, -0.8f + y_off, 0.0f, 0.55f, 0.1f, 0.55f, 0.0f);
  build_cuboid(0.0f, -0.9f + y_off, 0.0f, 0.75f, 0.1f, 0.75f, 0.0f);
  build_octahedron(0.0f, 1.0f + y_off, 0.0f, 0.12f);
  build_octahedron(-0.65f, 0.3f + y_off, 0.0f, 0.12f);
  build_octahedron(0.65f, 0.3f + y_off, 0.0f, 0.12f);
}
// -------------------------------------
void kv_draw_geometry(Kanvas* k, float angle, float scale, float rot_speed, size_t thicc, Kolor kolor)
{
  Vek2 viewport = {(float)k->w, (float)k->h};
  
  float dz = 2.0f; 
  float rot_x = angle * rot_speed * 0.7f;
  float rot_y = angle * rot_speed;
  float pan_x = 0.875f; 

  for (size_t i = 0; i < g_e_count; ++i)
  {
    Vek3 a = g_points[g_edges[i].v0];
    Vek3 b = g_points[g_edges[i].v1];

    a.x *= scale; a.y *= scale; a.z *= scale;
    b.x *= scale; b.y *= scale; b.z *= scale;

    Vek3 ra = km_vek3_rotate_y(km_vek3_rotate_y(a, rot_y), rot_x);
    Vek3 rb = km_vek3_rotate_y(km_vek3_rotate_y(b, rot_y), rot_x);
    Vek2 p1 = km_vek3_project(km_vek3_translate_z(ra, dz));
    Vek2 p2 = km_vek3_project(km_vek3_translate_z(rb, dz));

    p1.x += pan_x;
    p2.x += pan_x;

    Vek2 v1 = km_vek2_screen2norm((Vek2){viewport.x*0.5f, viewport.y*0.5f}, p1);
    Vek2 v2 = km_vek2_screen2norm((Vek2){viewport.x*0.5f, viewport.y*0.5f}, p2);

    kv_linev(k, v1, v2, thicc, kolor);
  }
}
// -------------------------------------
int main(void)
{
  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Kross 3D Orthodox Cross");
  kw_target_fps(60);

  init_geometry();

  float angle = 0;
  
  while (!kw_should_close())
  {
    kv_start(kv);
    kv_fill(kv, KLEAN_BLACK);

    angle += 0.015f; 
    kv_draw_geometry(kv, angle, 1.3f, 1.0f, 2, KLEAN_YELLOW);

    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
