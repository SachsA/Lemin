/*
** check_path.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Apr 18 18:57:31 2017 Thomas BLENEAU
** Last update Thu Apr 27 17:28:37 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include "basics.h"
#include "path.h"
#include "my.h"

int		check_path(t_link **stack, t_room *room)
{
  t_link	*tmp;

  tmp = *stack;
  while (tmp->next != NULL)
    {
      if (tmp->room == room)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		push_out_save(t_save **save, t_save *tmp)
{
  t_save	*tmp_free;

  if (tmp == *save)
    {
      tmp_free = tmp;
      *save = (*save)->next;
      if (*save != NULL)
	(*save)->prev = NULL;
      free_link(tmp->link);
      free(tmp_free);
      return (0);
    }
  else
    {
      if (tmp->next != NULL)
	tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
    }
  tmp_free = tmp;
  free_link(tmp->link);
  free(tmp_free);
  return (0);
}

int		check_room_path(t_link *link_1, t_link *link_2)
{
  t_link	*tmp_2;
  t_link	*tmp_1;

  if (link_2->next != NULL)
    tmp_2 = link_2->next;
  if (link_1->next != NULL)
    tmp_1 = link_1->next;
  while (tmp_1 != NULL)
    {
      tmp_2 = link_2->next;
      while (tmp_2 != NULL)
	{
	  if ((tmp_2->room->place != 2))
	    if (my_strcmp(tmp_1->room->name, tmp_2->room->name) == 0)
	      return (1);
	  tmp_2 = tmp_2->next;
	}
      tmp_1 = tmp_1->next;
    }
  return (0);
}

int		check_order_path(t_save **save)
{
  t_save	*tmp;
  int		lenght;

  if (!(tmp = *save))
    return (1);
  while (tmp->next != NULL)
    {
      lenght = path_cmp_len(tmp, tmp->next);
      if (lenght == 1)
	{
	  swap_save(save, tmp);
	  tmp = *save;
	}
      else
	tmp = tmp->next;
    }
  if (reverse_save(save))
    return (1);
  return (0);
}
