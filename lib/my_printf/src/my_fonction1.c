/*
** my_fonction1.c for my_fonction1 in /home/sachs_a/delivery/system_unix/PSU_2016_my_printf/bonus/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Nov 13 11:30:53 2016 Alexandre Sachs
** Last update Sat Jan 14 15:22:05 2017 Alexandre Sachs
*/

#include "my.h"

int	display_char(va_list list, int *compteur)
{
  my_putchar((char) va_arg(list, int));
  *compteur = *compteur + 1;
  return (*compteur);
}

int	display_str(va_list list, int *compteur)
{
  char	*store;

  store = va_arg(list, char *);
  if (store == NULL)
    my_putstr2("(null)", compteur);
  else
    my_putstr2(store, compteur);
  return (*compteur);
}

int	display_nbr(va_list list, int *compteur)
{
  my_put_nbr2(va_arg(list, int), compteur);
  return (*compteur);
}

int	display_nbr_bis(va_list list, int *compteur)
{
  my_put_nbr2(va_arg(list, int), compteur);
  return (*compteur);
}

int	display_unsigned_int(va_list list, int *compteur)
{
  my_fonction_base(va_arg(list, unsigned int), "0123456789", compteur);
  return (*compteur);
}
