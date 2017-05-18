/*
** main.c for main in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Apr  5 15:19:32 2017 Alexandre Sachs
** Last update May Apr 27 13:34:18 2017
*/

#include <stdlib.h>
#include <unistd.h>
#include "parsing.h"
#include "basics.h"
#include "path.h"
#include "my.h"

int		init_map(t_room **room)
{
  int		nb;
  char		*str;

  if ((nb = get_nb_ants()) == -1)
    return (0);
  if ((str = parsing(room)) == NULL)
    return (free(*room), 0);
  if (*room == NULL)
    return (free(str), 0);
  if (tri_list(room) == 84)
    return (free(str), 0);
  (*room)->nb_ant = nb;
  if (fill_links(str, room) == 84)
    return (free(str), 0);
  opti_list(room);
  free(str);
  return (1);
}

int		lem_in(t_room **room, t_link **stack)
{
  t_save	*save;

  save = NULL;
  put_stack_list(stack, *room);
  if (valid_stack(room, *room, *stack, &save))
    return (0);
  if (valid_save(&save, room))
    return (0);
  return (1);
}

int		main()
{
  t_room	*room;
  t_link	*stack;

  room = NULL;
  stack = NULL;
  if (!init_map(&room))
    return (84);
  if (!lem_in(&room, &stack))
    return (free(stack), 84);
  return (free(stack), 0);
}
