/*
** my_str1.c for my_str1 in /home/sachs_a/delivery/fonction_utiles/PRATIQUE
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Mar 24 01:05:16 2017 Alexandre Sachs
** Last update Mon Mar 27 15:20:32 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <stdlib.h>

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

int	my_str_isnum(char *str)
{
  int   i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
        return (0);
    }
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] < s2[i] || s1[i] > s2[i])
        return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

char	*my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *src)
{
  char  *dup;

  if ((dup = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  my_strcpy(dup, src);
  return (dup);
}
