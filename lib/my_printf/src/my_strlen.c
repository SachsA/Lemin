/*
** my_strlen.c for my_strlen in /home/sachs_a/delivery/fonctions_utiles
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Mon Jan  9 15:12:43 2017 Alexandre Sachs
** Last update Sat Jan 14 15:00:07 2017 Alexandre Sachs
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
