/*
** visu-hex.c for visu-hex in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Apr 19 19:13:24 2017 Alexandre Sachs
** Last update Jan Apr 30 17:34:59 2017
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "graph.h"
#include "limits.h"
#include "parsing.h"
#include "get_next_line.h"

int			print_rooms(t_my_framebuffer *pix, t_room **room,
				    sfVector2i *tab)
{
  t_room		*tmp;
  sfVector2f		pos;

  tmp = *room;
  while (tmp != NULL)
    {
      pos.y = tmp->pos.y * ((pix->height - 200) / tab->y) + 100;
      pos.x = tmp->pos.x * ((pix->width - 200) / tab->x) + 100;
      if (tmp->place == 2)
	draw_room(pix, &pos, tab, sfBlue);
      else if (tmp->nb_ant > 0)
	draw_room(pix, &pos, tab, sfRed);
      else
	draw_room(pix, &pos, tab, sfGreen);
      tmp = tmp->next;
    }
  return (0);
}

int			print_links(t_my_framebuffer *pix, t_room **room,
				    sfVector2i *tab)
{
  t_room		*tmp;

  tmp = *room;
  while (tmp != NULL)
    {
      draw_link(pix, tmp, tab);
      tmp = tmp->next;
    }
  return (0);
}

int			print_ant(t_my_framebuffer *pix, t_ants *ants)
{
  int			i;
  int			j;
  t_ants		*tmp;

  tmp = ants;
  while (tmp != NULL)
    {
      i = -3;
      while (++i < 3)
	{
	  j = -3;
	  while (++j < 3)
	    my_put_pixel(pix, tmp->pos.x + j, tmp->pos.y + i, sfWhite);
	}
      tmp->pos.y += tmp->way.y;
      tmp->pos.x += tmp->way.x;
      tmp = tmp->next;
    }
  return (0);
}

int			print_update(t_my_framebuffer *framebuffer,
				     t_room **room, t_ants *ants,
				     t_window *my_window)
{
  sfVector2i		tab;

  tab_size(room, &tab);
  print_links(framebuffer, room, &tab);
  if (ants != NULL)
    print_ant(framebuffer, ants);
  print_rooms(framebuffer, room, &tab);
  my_window_update(framebuffer, my_window);
  if (!my_event(my_window, framebuffer))
    return (1);
  return (0);
}

int			my_init_window(t_window *my_window, t_room **room)
{
  int			i;
  char			*str;
  t_ants		*ants;
  t_my_framebuffer	*framebuffer;

  set_window(&framebuffer, &my_window);
  while (sfRenderWindow_isOpen(my_window->window))
    {
      while ((str = get_next_line(0)) != NULL)
	{
	  i = -1;
	  ants = NULL;
	  get_ants(framebuffer, room, &ants, str);
	  while (++i < SPEED)
	    if (print_update(framebuffer, room, ants, my_window) == 1)
	      return (0);
	  free_ants_list(ants);
	}
      ants = NULL;
      if (print_update(framebuffer, room, ants, my_window) == 1)
	return (0);
    }
  return (0);
}
