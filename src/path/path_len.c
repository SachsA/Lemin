/*
** path_len.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Apr 14 12:02:58 2017 Thomas BLENEAU
** Last update Mon Apr 24 21:30:46 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int		save_len(t_save **save)
{
  int		i;
  t_save	*tmp;

  i = 0;
  if (!(tmp = *save))
    return (-1);
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  return (i);
}

int		link_len(t_link *link)
{
  t_link	*tmp;
  int		i;

  i = 0;
  if (!(tmp = link))
    return (-1);
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i = i + 1;
    }
  return (i);
}

int	path_cmp_len(t_save *save_1, t_save *save_2)
{
  int	lenght_1;
  int	lenght_2;

  lenght_1 = link_len(save_1->link);
  lenght_2 = link_len(save_2->link);
  if (lenght_1 > lenght_2)
    return (1);
  return (0);
}
