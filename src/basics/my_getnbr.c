/*
** my_getnbr.c for my_getnbr in /home/sachs_a/delivery/fonction_utiles/repo
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Thu Apr  6 23:39:10 2017 Alexandre Sachs
** Last update Thu Apr  6 23:39:10 2017 Alexandre Sachs
*/

#include <stdio.h>

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	neg;

  i = 0;
  nb = 0;
  neg = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	neg = neg + 1;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + str[i] - 48;
      i = i + 1;
    }
  if ((neg % 2) == 0)
    return (nb);
  else
    return (-nb);
}
