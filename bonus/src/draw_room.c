/*
** draw_square.c for Lemin_graph in /home/invicta/CPE_2016_Lemin/bonus/src/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Wed Apr 19 22:16:43 2017 Kellian CIPIERRE
** Last update Apr Apr 26 19:32:51 2017
*/

#include <stdio.h>
#include "graph.h"

int		draw_room(t_my_framebuffer *framebuffer, sfVector2f *pos,
			  sfVector2i *tab, sfColor color)
{
  int		i;
  int		j;
  sfVector2i	tmp;
  int		var;

  tmp.y = framebuffer->height / tab->y / 5;
  tmp.x = framebuffer->width / tab->x / 5;
  if (tmp.x < tmp.y)
    var = tmp.x;
  else
    var = tmp.y;
  i = pos->y - var;
  while (i < pos->y + var)
    {
      j = pos->x - var;
      while (j < pos->x + var)
	{
	  my_put_pixel(framebuffer, j, i, color);
	  j++;
	}
      i++;
    }
  return (0);
}

int		draw_link(t_my_framebuffer *framebuffer, t_room *room,
		  sfVector2i *tab)
{
  t_link	*tmpl;
  sfVector2f	scale;
  sfVector2i	from;
  sfVector2i	to;

  scale.y = (framebuffer->height - 200) / tab->y;
  scale.x = (framebuffer->width - 200) / tab->x;
  from.y = room->pos.y * scale.y + 100;
  from.x = room->pos.x * scale.x + 100;
  tmpl = room->link;
  while (tmpl != NULL)
    {
      to.y = tmpl->room->pos.y * scale.y + 100;
      to.x = tmpl->room->pos.x * scale.x + 100;
      my_draw_line(framebuffer, from, to, sfRed);
      tmpl = tmpl->next;
    }
  return (0);
}
