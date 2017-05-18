/*
** my_tablen.c for mysh in /home/sachs_a/delivery/system_unix/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar 15 10:59:55 2017 Alexandre Sachs
** Last update Fri Mar 24 00:22:12 2017 Alexandre Sachs
*/

#include <unistd.h>

int	my_tablen(char **tab)
{
  int   i;

  i = -1;
  while (tab[++i] != NULL);
  return (i);
}
