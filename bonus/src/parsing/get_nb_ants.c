/*
** get_nb_ants.c for get_nb_ants in /home/sachs_a/delivery/c_prog_elem/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Tue Apr 11 15:10:37 2017 Alexandre Sachs
** Last update Tue Apr 11 15:10:37 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "parsing.h"
#include "basics.h"
#include "my.h"

int	get_nb_ants()
{
  int	nb;
  char	*str;

  nb = -1;
  while ((str = get_next_line(0)) != NULL && comment(str, 0) == 1);
  if (str != NULL)
    {
      if (my_str_isnum(str) != 0)
	nb = my_getnbr(str);
      else
	{
	  write(2, "The first line must be the number of ants, "
		"and it must be only digits.\n", 71);
	  return (-1);
	}
    }
  free(str);
  return (nb);
}
