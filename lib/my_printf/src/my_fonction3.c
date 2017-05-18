/*
** my_fonction3.c for my_fonction3 in /home/sachs_a/delivery/system_unix/PSU_2016_my_printf/bonus/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Nov 13 11:40:31 2016 Alexandre Sachs
** Last update Mon Feb 27 18:45:58 2017 Alexandre Sachs
*/

#include "my.h"

int	display_pointeur(va_list list, int *compteur)
{
  char	*store;

  store = va_arg(list, char *);
  if (store == NULL)
    my_putstr2("(nil)", compteur);
  else
    {
      my_putstr2("0x", compteur);
      my_fonction_base_long((unsigned long) store,
			    "0123456789abcdef", compteur);
    }
  return (*compteur);
}

int	display_str_octale2(char *src, int j, int *compteur)
{
  if (src[j] < 7)
    my_putstr2("\\00", compteur);
  else if (src[j] > 7 && src[j] < 32)
    my_putstr2("\\0", compteur);
  else if (src[j] >= 127)
    my_putstr2("\\", compteur);
  my_fonction_base(src[j], "01234567", compteur);
  return (*compteur);
}

int	display_str_octale(va_list list, int *compteur)
{
  char	*src;
  int	j;

  j = -1;
  src = va_arg(list, char *);
  if (src == NULL)
    my_putstr2("(null)", compteur);
  else
    while (src[++j] != '\0')
      {
	if (src[j] < 32 || src[j] > 126)
	  display_str_octale2(src, j, compteur);
	else
	  {
	    my_putchar(src[j]);
	    *compteur = *compteur + 1;
	  }
      }
  return (*compteur);
}
