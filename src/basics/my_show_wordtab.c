/*
** my_show_wordtab.c for show_wordtab in /home/sachs_a/delivery/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Thu Apr  6 23:40:05 2017 Alexandre Sachs
** Last update Thu Apr  6 23:40:05 2017 Alexandre Sachs
*/

#include "basics.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != '\0')
    my_printf("%s\n", tab[i]);
  return (0);
}
