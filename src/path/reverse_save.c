/*
** reverse_save.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Apr 21 15:11:29 2017 Thomas BLENEAU
** Last update Thu Apr 27 16:47:49 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include "basics.h"
#include "path.h"
#include "my.h"

int		swap_save(t_save **link, t_save *save)
{
  t_save	*tmp;

  if (*link == save)
    {
      tmp = save->next;
      save->next = save->next->next;
      tmp->next = save;
      *link = tmp;
      return (0);
    }
  tmp = *link;
  while (tmp->next != save)
    tmp = tmp->next;
  tmp->next = tmp->next->next;
  save->next = save->next->next;
  tmp->next->next = save;
  return (0);
}

int		reverse_link(t_link **link)
{
  t_link	*tmp;
  t_link	*prev;
  t_link	*next;

  if (!(tmp = *link))
    return (1);
  prev = NULL;
  while (tmp->next != NULL)
    {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
  tmp->next = prev;
  *link = tmp;
  return (0);
}

int		reverse_save(t_save **save)
{
  t_save	*tmp;

  if (!(tmp = *save))
    return (1);
  while (tmp != NULL)
    {
      if (reverse_link(&tmp->link))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
