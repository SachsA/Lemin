/*
** init_tab.c for Lemin_graph in /home/invicta/CPE_2016_Lemin/bonus/src/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Wed Apr 19 19:40:45 2017 Kellian CIPIERRE
** Last update Mar Apr 25 09:04:43 2017
*/

#include "graph.h"

int		tab_size(t_room **room, sfVector2i *tab)
{
  t_room	*tmp;

  tmp = *room;
  tab->y = 1;
  tab->x = 1;
  while (tmp != NULL)
    {
      if (tmp->pos.y > tab->y)
	tab->y = tmp->pos.y;
      if (tmp->pos.x > tab->x)
	tab->x = tmp->pos.x;
      tmp = tmp->next;
    }
  return (0);
}
