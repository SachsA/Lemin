/*
** tri_list.c for tri_list in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Apr 12 18:20:22 2017 Alexandre Sachs
** Last update Mar Apr 18 16:02:08 2017
*/

#include <unistd.h>
#include "my.h"

int		upgrade_node(t_room *tmp, t_room **room)
{
  t_room	*tmp2;

  tmp2 = tmp->next;
  tmp->next = tmp2->next;
  tmp2->next = *room;
  *room = tmp2;
  return (0);
}

int		downgrade_node(t_room *tmp)
{
  t_room	*tmp2;

  tmp2 = tmp->next;
  tmp->next = tmp2->next;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = tmp2;
  tmp2->next = NULL;
  return (0);
}

int		check_start_end(t_room **room)
{
  int		i;
  int		j;
  t_room	*tmp;

  i = 0;
  j = 0;
  tmp = *room;
  while (tmp != NULL)
    {
      if (tmp->place == 0)
	i++;
      if (tmp->place == 2)
	j++;
      tmp = tmp->next;
    }
  if (i != 1 || j != 1)
    return (84);
  return (0);
}

int		tri_list(t_room **room)
{
  t_room	*tmp;

  tmp = *room;
  while (tmp->next != NULL && tmp->next->place != 0)
    tmp = tmp->next;
  if (tmp->next != NULL)
    upgrade_node(tmp, room);
  tmp = *room;
  while (tmp->next != NULL && tmp->next->place != 2)
    tmp = tmp->next;
  if (tmp->next != NULL)
    downgrade_node(tmp);
  if (check_start_end(room) == 84)
    return (84);
  return (0);
}
