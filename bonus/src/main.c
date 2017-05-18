/*
** main.c for lemin in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin/bonus
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Apr 19 19:14:55 2017 Alexandre Sachs
** Last update Apr Apr 26 19:56:24 2017
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graph.h"
#include "my.h"
#include "parsing.h"

int		main()
{
  int		nb;
  char		*str;
  t_room	*room;
  t_window	my_window;

  room = NULL;
  if ((nb = get_nb_ants()) == -1)
    return (84);
  if ((str = parsing(&room)) == NULL || room == NULL)
    return (84);
  if (tri_list(&room) == 84)
    return (84);
  room->nb_ant = nb;
  if (fill_links(str, &room) == 84)
    return (free(str), 84);
  my_init_window(&my_window, &room);
  free(str);
  free_list(&room, 0);
  return (0);
}
