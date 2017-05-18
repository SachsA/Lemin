/*
** nodes_carac.c for nodes_carac in /home/sachs_a/delivery/c_prog_elem/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Tue Apr 11 16:03:37 2017 Alexandre Sachs
** Last update Tue Apr 11 16:03:37 2017 Alexandre Sachs
*/

#include <unistd.h>
#include "basics.h"
#include "parsing.h"

int	fill_room_carac(char **tab, t_room **room)
{
  (*room)->name = my_strdup(tab[0]);
  if (my_str_isnum(tab[1]) == 0 || my_str_isnum(tab[2]) == 0)
    return (84);
  (*room)->pos.x = my_getnbr(tab[1]);
  (*room)->pos.y = my_getnbr(tab[2]);
  return (0);
}

int	nodes_carac(char *str, char *save, t_room **room)
{
  char	**tab;

  if (str[0] == '#' && str[1] == '#')
    return (0);
  if ((tab = my_str_to_wordtab_double(str, ' ', '\t')) == NULL)
    return (84);
  if (my_tablen(tab) == 3)
    {
      if (init_room(room) == -1)
	return (84);
      if (fill_room_carac(tab, room) == 84)
        return (my_free_tab(tab), 84);
    }
  else
    return (my_free_tab(tab), 1);
  if (save != NULL && save[0] == '#' && save[1] == '#')
    {
      if (my_strncmp(save + 2, "start", 6) == 0)
	(*room)->place = 0;
      else if (my_strncmp(save + 2, "end", 4) == 0)
	(*room)->place = 2;
    }
  my_free_tab(tab);
  return (0);
}
