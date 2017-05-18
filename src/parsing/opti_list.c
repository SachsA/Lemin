/*
** opti_list.c for Lemin in /home/invicta/CPE_2016_Lemin/src/parsing/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Thu Apr 27 11:11:19 2017 Kellian CIPIERRE
** Last update May Apr 27 13:30:22 2017
*/

#include <stdlib.h>
#include "basics.h"
#include "my.h"
#include "parsing.h"

int		clean_links(t_room *last, t_room **node)
{
  free_link((*node)->link);
  if (((*node)->link = malloc(sizeof(t_link))) == NULL)
    return (84);
  (*node)->link->next = NULL;
  (*node)->link->room = last;
  return (0);
}

int		opti_list(t_room **room)
{
  t_room	*node;
  t_room	*last;
  t_link	*link;

  node = (*room)->next;
  last = *room;
  while (last->next != NULL)
    last = last->next;
  while (node->next != NULL)
    {
      link = node->link;
      while (link != NULL)
	{
	  if (my_strcmp(link->room->name, last->name) == 0)
	    {
	      clean_links(last, &node);
	      break;
	    }
	  link = link->next;
	}
      node = node->next;
    }
  return (0);
}
