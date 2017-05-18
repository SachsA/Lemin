/*
** my_putstr.c for my_putstr in /home/sachs_a/delivery/system_unix/PSU_2016_my_printf/bonus
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Nov 13 10:56:18 2016 Alexandre Sachs
** Last update Sat Jan 14 15:03:49 2017 Alexandre Sachs
*/

#include "my.h"

int	my_putstr2(char *str, int *compteur)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      *compteur = *compteur + 1;
      i = i + 1;
    }
  return (*compteur);
}

int	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
