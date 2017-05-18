/*
** my_str2.c for my_str2 in /home/sachs_a/delivery/fonction_utiles/PRATIQUE
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Mar 24 01:05:32 2017 Alexandre Sachs
** Last update Mon Mar 27 10:37:19 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <stdlib.h>
#include "basics.h"

char	*my_strcat(char *dest, char *src)
{
  int   len;
  int   i;

  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}

char	*my_strncat(char *dest, char *src, int nb)
{
  int   a;
  int   lengh;

  a = 0;
  lengh = my_strlen(dest);
  while (src[a] != '\0' && a < nb)
    {
      dest[lengh + a] = src[a];
      a = a + 1;
    }
  dest[lengh + a] = '\0';
  return (dest);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
    {
      if (s1[i] < s2[i])
        return (s1[i] - s2[i]);
      if (s1[i] > s2[i])
        return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int   i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
