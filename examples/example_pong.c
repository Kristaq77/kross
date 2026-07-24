// -------------------------------------
#define KROSS_IMPLEMENTATION
#include "kross.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// -------------------------------------
int main(void)
{
  typedef struct Pong_Ball {
    float cx;
    float cy;
    size_t r;
    Kolor kolor;
  } Pong_Ball;

  Kanvas* kv = kv_init(1280, 800);
  kw_init(kv, "Pong");
  kw_target_fps(60);
  // --------------
  const size_t paddle_w = 15;
  const size_t paddle_h = 105;
  const size_t paddle_speed = 6;
  // --------------
  size_t p0_count = 0;
  size_t p1_count = 0;
  // --------------
  size_t ball_r = 10;
  float ball_cx = kv->w/2-ball_r;
  float ball_cy = kv->h/2-ball_r;
  float base_ball_speed = 350.0f;
  float ball_vx = base_ball_speed; 
  float ball_vy = base_ball_speed;
  // --------------
  Pong_Ball ball = {ball_cx, ball_cy, ball_r, KLEAN_WHITE};
  // --------------
  Rekt paddle0 = {20, kv->h/2-paddle_h/2, paddle_w, paddle_h};
  Rekt paddle1 = {kv->w-paddle_w-20, kv->h/2-paddle_h/2, paddle_w, paddle_h};
  // --------------
  Kolor p0_kolor = KLEAN_YELLOW;
  Kolor p1_kolor = KLEAN_RED;
  // --------------
  float p0_hit_timer = 0.0f;
  float p1_hit_timer = 0.0f;
  // --------------
  while (!kw_should_close())
  {
    kv_start(kv);
    // --------------
    kv_fill(kv, KLEAN_BLACK);
    // --------------
    for (int i = 0; i < kv->h; i += 40) kv_rect(kv, kv->w/2 - 2, i + 10, 4, 20, KPASTEL_WHITE);
    // --------------
    if (ki_down(KI_W))      paddle0.y -= paddle_speed;
    if (ki_down(KI_S))      paddle0.y += paddle_speed;
    if (ki_down(KI_UP))     paddle1.y -= paddle_speed;
    if (ki_down(KI_DOWN))   paddle1.y += paddle_speed;
    // --------------
    paddle0.y = km_clampf(paddle0.y, 0, kv->h-paddle_h);
    paddle1.y = km_clampf(paddle1.y, 0, kv->h-paddle_h);
    // --------------
    if (p0_hit_timer > 0) p0_hit_timer -= kw_delta();
    if (p1_hit_timer > 0) p1_hit_timer -= kw_delta();
    // --------------
    ball.cx += ball_vx * kw_delta();
    ball.cy += ball_vy * kw_delta();
    // --------------
    if (ball.cy-ball.r <= 0)
    {
      ball.cy = ball.r;
      ball_vy *= -1;
    } 
    else if (ball.cy+ball.r >= kv->h)
    {
      ball.cy = kv->h-ball.r;
      ball_vy *= -1;
    }

    Vek2 ball_pos = {ball.cx, ball.cy};
    // --------------
    if (km_hit_rect_circler(paddle0, ball_pos, ball.r))
    {
      ball_vx = fabsf(ball_vx) + 20.0f; 
      ball.cx = paddle0.x + paddle0.w + ball.r;
      p0_hit_timer = 0.15f;
    }
    if (km_hit_rect_circler(paddle1, ball_pos, ball.r))
    {
      ball_vx = -fabsf(ball_vx)-20.0f;
      ball.cx = paddle1.x - ball.r;
      p1_hit_timer = 0.15f;
    }

    if (ball.cx < 0)
    {
      p1_count++;
      ball.cx = kv->w/2;
      ball.cy = kv->h/2;
      ball_vx = -base_ball_speed;
      ball_vy = (rand()%2 == 0 ? base_ball_speed : -base_ball_speed);
    } 
    else if (ball.cx > kv->w)
    {
      p0_count++;
      ball.cx = kv->w/2;
      ball.cy = kv->h/2;
      ball_vx = base_ball_speed;
      ball_vy = (rand()%2 == 0 ? base_ball_speed : -base_ball_speed);
    }

    float t_kolor = km_clampf(ball.cx/(float)kv->w, 0.0f, 1.0f);
    ball.kolor = kl_lerp(p0_kolor, p1_kolor, t_kolor);
    // --------------
    Kolor draw_p0 = p0_hit_timer > 0 ? kl_lerp(p0_kolor, KLEAN_WHITE, p0_hit_timer * 6.66f) : p0_kolor;
    Kolor draw_p1 = p1_hit_timer > 0 ? kl_lerp(p1_kolor, KLEAN_WHITE, p1_hit_timer * 6.66f) : p1_kolor;
    // --------------
    for (size_t i = 0; i < p0_count; i++) kv_circle(kv, (kv->w/2) - 40 - (i * 25), 30, 6, p0_kolor);
    for (size_t i = 0; i < p1_count; i++) kv_circle(kv, (kv->w/2) + 40 + (i * 25), 30, 6, p1_kolor);
    // --------------
    kv_circle(kv, ball.cx, ball.cy, ball.r, ball.kolor);
    // --------------
    kv_rectr(kv, paddle0, draw_p0);
    kv_rectr(kv, paddle1, draw_p1);
    // --------------
    kv_rect(kv, 0, 0, kv->w, 4, KLEAN_RED);
    kv_rect(kv, 0, 0, 4, kv->h, KLEAN_YELLOW);
    kv_rect(kv, 0, kv->h-4, kv->w, 4, KLEAN_RED);
    kv_rect(kv, kv->w-4, 0, 4, kv->h, KLEAN_YELLOW);
    // --------------
    kv_stop(kv);
  }

  kw_free();
  kv_free(kv);
  return 0;
}
// -------------------------------------
