/*
** my_fonction2.c for my_fonction2 in /home/sachs_a/delivery/system_unix/PSU_2016_my_printf/bonus/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Nov 13 11:30:38 2016 Alexandre Sachs
** Last update Sat Jan 14 15:22:12 2017 Alexandre Sachs
*/

#include "my.h"

int	display_hex_maj(va_list list, int *compteur)
{
  my_fonction_base(va_arg(list, unsigned int), "0123456789ABCDEF", compteur);
  return (*compteur);
}

int	display_hex_min(va_list list, int *compteur)
{
  my_fonction_base(va_arg(list, unsigned int), "0123456789abcdef", compteur);
  return (*compteur);
}

int	display_octale(va_list list, int *compteur)
{
  my_fonction_base(va_arg(list, unsigned int), "01234567", compteur);
  return (*compteur);
}

int	display_binaire(va_list list, int *compteur)
{
  my_fonction_base(va_arg(list, unsigned int), "01", compteur);
  return (*compteur);
}
