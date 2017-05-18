/*
** valid_save.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Apr 24 21:42:45 2017 Thomas BLENEAU
** Last update Thu Apr 27 18:17:22 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "basics.h"
#include "path.h"
#include "my.h"

int		remove_maillon(t_save **save, t_save **tmp_1,
			       t_save **tmp_2, int *i)
{
  t_save	*tmp_save;

  if (link_len((*tmp_1)->link) > link_len((*tmp_2)->link))
    {
      tmp_save = (*tmp_1)->next;
      push_out_save(save, *tmp_1);
      *tmp_1 = tmp_save;
      *i = 1;
      return (1);
    }
  tmp_save = (*tmp_2)->next;
  push_out_save(save, (*tmp_2));
  *tmp_2 = tmp_save;
  return (0);
}

int		order_display(t_save **save, t_room **room)
{
  if (check_order_path(save))
    return (1);
  if (display_path(save, room))
    return (1);
  return (free_list(room, 1), 0);
}

int		valid_save(t_save **save, t_room **room)
{
  int		i;
  t_save	*tmp_2;
  t_save	*tmp_1;

  if (!(tmp_1 = *save))
    return (1);
  while (tmp_1 && tmp_1->next != NULL)
    {
      i = 0;
      tmp_2 = tmp_1->next;
      while (tmp_2 != NULL)
	{
	  if (check_room_path(tmp_1->link, tmp_2->link))
	    {
	      if (remove_maillon(save, &tmp_1, &tmp_2, &i))
		break ;
	    }
	  else
	    tmp_2 = tmp_2->next;
	}
      if (i == 0)
	tmp_1 = tmp_1->next;
    }
  return (order_display(save, room));
}
