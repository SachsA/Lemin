/*
** parsing.c for parsing in /home/sachs_a/delivery/c_prog_elem/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Apr 10 17:41:51 2017 Alexandre Sachs
** Last update Mon Apr 24 21:34:04 2017 Thomas BLENEAU
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "basics.h"
#include "parsing.h"
#include "get_next_line.h"

void		my_free_pars(char *str, char *save, t_room **room)
{
  if (str != NULL)
    {
      free(str);
      str = NULL;
    }
  if (save != NULL)
    {
      free(save);
      save = NULL;
    }
  free_list(room, 1);
}

char		*parsing(t_room **room)
{
  int		i;
  char		*str;
  char		*save;

  save = NULL;
  while ((str = get_next_line(0)) != NULL)
    {
      str = my_clean(str);
      if (*str == '\0')
	{
	  free(str);
	  continue ;
	}
      if ((i = nodes_carac(str, save, room)) == 84)
	return (my_free_pars(str, save, room), NULL);
      else if (i == 1)
	return (free(save), str);
      if (save != NULL)
	free(save);
      save = my_strdup(str);
      free(str);
    }
  return (my_free_pars(str, save, room), NULL);
}
