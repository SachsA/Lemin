/*
** init.c for init in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Tue Apr 11 11:24:59 2017 Alexandre Sachs
** Last update Tue Apr 11 11:24:59 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

int		init_room(t_room **room)
{
  t_room        *tmp;

  if ((tmp = malloc(sizeof(t_room))) == NULL)
    return (-1);
  tmp->place = 1;
  tmp->id_ant = 0;
  tmp->nb_ant = 0;
  tmp->link = NULL;
  tmp->next = *room;
  *room = tmp;
  return (0);
}
