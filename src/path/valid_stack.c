/*
** valid_stack.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Apr 13 16:50:19 2017 Thomas BLENEAU
** Last update Jan Apr 30 16:51:18 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include "limits.h"
#include "parsing.h"
#include "basics.h"
#include "path.h"
#include "my.h"

int		put_stack_list(t_link **stack, t_room *room)
{
  t_link	*tmp;
  t_link	*elem;

  tmp = *stack;
  if ((elem = malloc(sizeof(t_link))) == NULL)
    return (1);
  elem->room = room;
  elem->next = NULL;
  if (tmp == NULL)
    *stack = elem;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}

int		copy_stack_list(t_link **src, t_link **dest)
{
  t_link	*tmp;

  if (!(tmp = *src))
    return (1);
  while (tmp != NULL)
    {
      put_stack_list(dest, tmp->room);
      tmp = tmp->next;
    }
  return (0);
}

int		put_save_list(t_save **save, t_link *link)
{
  t_save	*tmp;
  t_save	*elem;

  tmp = *save;
  if ((elem = malloc(sizeof(t_save))) == NULL)
    return (1);
  elem->link = NULL;
  copy_stack_list(&link, &elem->link);
  elem->prev = NULL;
  elem->next = NULL;
  if (tmp == NULL)
    *save = elem;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (0);
}

int		valid_stack(t_room **room, t_room *origin,
			    t_link *stack, t_save **save)
{
  t_room	*tmp_room;
  t_link	*tmp_link;

  tmp_link = origin->link;
  while (tmp_link != NULL && (save_len(save) < LIMIT))
    {
      tmp_room = tmp_link->room;
      put_stack_list(&stack, tmp_room);
      if (tmp_room->place != 2 && (!(check_path(&stack, tmp_room))))
	valid_stack(room, tmp_room, stack, save);
      if (tmp_room->place == 2)
	{
	  if (put_save_list(save, stack))
	    return (1);
	}
      free_end_stack(stack);
      tmp_link = tmp_link->next;
    }
  return (0);
}
