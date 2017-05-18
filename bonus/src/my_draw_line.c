/*
** my_test.c for test_libgraph in /home/invicta/test_graph/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Wed Nov  9 09:57:15 2016 Kellian CIPIERRE
** Last update Apr Apr 26 19:29:26 2017
*/

#include "graph.h"

void		my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  double	x;
  double	y;
  double	vx;
  double	vy;

  x = from.x;
  y = from.y;
  vx = (double)(to.x - from.x) / (128 * 128);
  vy = (double)(to.y - from.y) / (128 * 128);
  while ((int)x != to.x || (int)y != to.y)
    {
      my_put_pixel(framebuffer, x, y, color);
      x += vx;
      y += vy;
    }
}
