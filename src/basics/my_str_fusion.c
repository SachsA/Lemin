/*
** my_cat.c for my_str_fusion in /home/sachs_a/delivery/c_prog_elem/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Mon Apr 10 17:52:46 2017 Alexandre Sachs
** Last update Mon Apr 10 17:52:46 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "basics.h"

char	*my_str_fusion(char *src, char *dest)
{
  int	i;
  char	*str;

  i = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(src) +
				    my_strlen(dest) + 1))) == NULL)
    return (NULL);
  while (*src != '\0')
    {
      str[i] = *src;
      i++;
      src++;
    }
  while (*dest != '\0')
    {
      str[i] = *dest;
      i++;
      dest++;
    }
  str[i] = '\0';
  return (str);
}
