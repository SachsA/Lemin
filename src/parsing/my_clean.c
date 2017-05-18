/*
** my_clean.c for my_clean in /home/sachs_a/delivery/c_prog_elem/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Apr 10 18:43:21 2017 Alexandre Sachs
** Last update Mar Apr 18 11:49:50 2017
*/

#include <stdlib.h>
#include "basics.h"

int	comment(char *src, int i)
{
  if ((i == 0 && src[i] == '#' && src[i + 1] != '#') ||
      (i == 1 && src[i] == '#' && src[i - 1] != '#') ||
      (i > 1 && src[i] == '#'))
    return (1);
  return (0);
}

char	*my_clean(char *src)
{
  char	*final;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (src == NULL)
    return (NULL);
  if ((final = malloc((my_strlen(src) + 1))) == NULL)
    return (NULL);
  while ((src[i] && src[i] == ' ') || (src[i] && src[i] == '\t'))
    i++;
  while (src[i] != '\0' && comment(src, i) == 0)
    {
      while ((src[i] == ' ' && src[i + 1] == ' ') ||
	     (src[i] == '\t' && src[i + 1] == '\t'))
	i++;
      final[j++] = src[i++];
    }
  final[j] = 0;
  free(src);
  if (my_strlen(final) != 0 && final[my_strlen(final) - 1] == ' ')
    final[my_strlen(final) - 1] = 0;
  return (final);
}
