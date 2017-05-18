/*
** my_strcpy.c for my_strcpy in /home/romain_g/delivery/CPool_Day06
** 
** Made by romain gadrat
** Login   <romain_g@epitech.net>
** 
** Started on  Mon Oct 10 10:01:03 2016 romain gadrat
** Last update Sat Jan 14 15:23:27 2017 Alexandre Sachs
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
