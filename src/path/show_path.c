/*
** show_path.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Apr 18 18:59:45 2017 Thomas BLENEAU
** Last update Fri Apr 21 12:57:18 2017 Thomas BLENEAU
*/

#include <stdio.h>
#include "basics.h"
#include "path.h"
#include "my.h"

void		show_stack(t_link **stack)
{
  t_link	*tmp;

  my_printf("stack :\n");
  if (!(tmp = *stack))
    return ;
  while (tmp != NULL)
    {
      my_printf("%s", tmp->room->name);
      if (tmp->next != NULL)
	my_printf("-");
      tmp = tmp->next;
    }
  my_printf("\n");
}

void		show_save(t_save *save)
{
  t_link	*tmp_link;

  my_printf("save :\n");
  while (save != NULL)
    {
      tmp_link = save->link;
      while (tmp_link != NULL)
	{
	  my_printf("%s", tmp_link->room->name);
	  if (tmp_link->next != NULL)
	    my_printf("-");
	  tmp_link = tmp_link->next;
	}
      my_printf("\n");
      save = save->next;
    }
}
