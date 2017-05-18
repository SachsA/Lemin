/*
** my_free.c for my_free in /home/sachs_a/delivery/c_prog_elem/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Tue Apr 11 14:58:02 2017 Alexandre Sachs
** Last update Thu Apr 20 11:47:01 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include "my.h"
#include "path.h"
#include "parsing.h"

void		my_free_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    free(tab[i]);
  if (tab != NULL)
    free(tab);
}

void		free_link(t_link *link)
{
  t_link	*tmp;

  while (link != NULL)
    {
      tmp = link;
      link = link->next;
      free(tmp);
    }
}

void		free_end_stack(t_link *link)
{
  if (link == NULL || link->next == NULL)
    return ;
  while (link->next->next != NULL)
    link = link->next;
  free(link->next);
  link->next = NULL;
}

void		free_save(t_save **stack)
{
  t_save	*tmp;
  t_save	*save;

  if (!(tmp = *stack))
    return ;
  while (tmp != NULL)
    {
      free_link(tmp->link);
      save = tmp;
      tmp = tmp->next;
      free(save);
    }
}

void		free_list(t_room **room, int bool)
{
  t_room	*tmp;
  t_link	*tmp2;

  tmp = *room;
  while (*room != NULL)
    {
      tmp = *room;
      *room = tmp->next;
      while (tmp->link != NULL)
	{
	  tmp2 = tmp->link;
	  tmp->link = tmp2->next;
	  free(tmp2);
	}
      free(tmp->name);
      free(tmp);
    }
  if (bool == 1 && room != NULL)
    room = NULL;
}
