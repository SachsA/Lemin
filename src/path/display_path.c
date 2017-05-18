/*
** display_path.c for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Apr 21 10:14:12 2017 Thomas BLENEAU
** Last update Mon Apr 24 22:04:39 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include <unistd.h>
#include "basics.h"
#include "path.h"
#include "my.h"

int		push_ant(t_room **room, t_link **link,
			 int *max_ant, int *i)
{
  if ((*link)->next->room->nb_ant > 0 && (*link)->room->nb_ant == 0)
    {
      if ((*link)->next->room->place == 0)
	(*link)->room->id_ant = (*max_ant - (*room)->nb_ant) + 1;
      else
	(*link)->room->id_ant = (*link)->next->room->id_ant;
      (*link)->room->nb_ant = 1;
      (*link)->next->room->nb_ant -= 1;
      if (*i != 0)
	my_printf(" ");
      my_printf("P%d-%s", (*link)->room->id_ant, (*link)->room->name);
      (*i)++;
    }
  return (0);
}

int		game_over(t_room **room)
{
  t_room	*tmp;

  if (!(tmp = *room))
    return (-1);
  while (tmp->next != NULL)
    {
      if (tmp->nb_ant != 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

int		display_path_loop(t_save **save, t_room **room)
{
  int		i;
  int		max_ant;
  t_save	*tmp_save;
  t_link	*link;

  max_ant = (*room)->nb_ant;
  while ((*room)->nb_ant > 0 || !game_over(room))
    {
      i = 0;
      if (!(tmp_save = *save))
	return (1);
      while (tmp_save != NULL)
	{
	  link = tmp_save->link;
	  link->room->nb_ant = 0;
	  while (link->next != NULL)
	    {
	      push_ant(room, &link, &max_ant, &i);
	      link = link->next;
	    }
	  tmp_save = tmp_save->next;
	}
      my_printf("\n");
    }
  return (0);
}

int		display_path(t_save **save, t_room **room)
{
  int		lenght;

  if ((lenght = save_len(save)) < 0)
    return (1);
  my_printf("#moves\n");
  display_path_loop(save, room);
  return (0);
}
