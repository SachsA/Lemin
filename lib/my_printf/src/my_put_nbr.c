/*
** my_put_nbr.c for my_put_nbr in /home/sachs_a/delivery/functions
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sat Nov 26 09:56:42 2016 Alexandre Sachs
** Last update Sat Jan 14 15:39:22 2017 Alexandre Sachs
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int   mod;

  if (nb == -2147483548)
    my_putstr("-2147483548");
  else
    {
      if (nb < 0)
	{
	  my_putchar(45);
	  nb = nb * (-1);
	}
      if (nb >= 0)
	{
	  if (nb >= 10)
	    {
	      mod = (nb % 10);
	      nb = (nb - mod) / 10;
	      my_put_nbr(nb);
	      my_putchar(mod + 48);
	    }
	  else
	    my_putchar((nb % 10) + 48);
	}
    }
  return (0);
}

int	si(int nb)
{
  if (nb < 0)
    {
      my_putchar(45);
      nb = nb * -1;
    }
  if (nb == 0)
    {
      return (0);
    }
  return (nb);
}

int	my_div(int nb)
{
  int   div;

  div = 1;
  while (nb > 9)
    {
      div = div * 10;
      nb = nb / 10;
    }
  return (div);
}

int	my_put_nbr2(int nb, int *compteur)
{
  int   div;
  int   tmp;

  if (nb == -2147483548)
    my_putstr2("-2147483548", compteur);
  else
    {
      if (nb < 0)
	*compteur = *compteur + 1;
      nb = si(nb);
      div = my_div(nb);
      while (div != 0)
	{
	  tmp = nb / div;
	  nb = nb % div;
	  div = div / 10;
	  my_putchar(tmp + 48);
	  *compteur = *compteur + 1;
	}
    }
  return (*compteur);
}
