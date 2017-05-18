/*
** my_str_to_wordtab.c for str_to_wordtab in /home/sachs_a/delivery/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Thu Apr  6 23:42:03 2017 Alexandre Sachs
** Last update Thu Apr  6 23:42:03 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "my.h"

int	separators(char *str, char sep)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (!str)
    return (-1);
  while (str[i] == sep && str[i])
    i++;
  while (str[i])
    {
      while (str[i] != sep && str[i])
	i++;
      c++;
      while (str[i] == sep && str[i])
	i++;
    }
  return (c);
}

int	word_size(char *str, int c, char sep)
{
  int	i;

  i = 0;
  if (!str)
    return (-1);
  while (str[i] == sep && str[i])
    i++;
  while (c != 1)
    {
      while (str[i] != sep && str[i])
	i++;
      while (str[i] == sep && str[i])
	i++;
      c--;
    }
  c = 0;
  while (str[i] != sep && str[i++] != '\0')
    c++;
  return (c + 1);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  k = 0;
  i = -1;
  if (!str || (tab =
		  malloc(sizeof(char *) * (separators(str, sep) + 1))) == NULL)
    return (NULL);
  while (++i != (separators(str, sep)))
    {
      j = 0;
      if ((tab[i] = malloc((word_size(str, (i + 1), sep)))) == NULL)
	return (0);
      while (str[k] == sep)
	k++;
      while (str[k] != sep && str[k])
	tab[i][j++] = str[k++];
      tab[i][j] = '\0';
      while (str[k] == sep && str[k])
	k++;
    }
  tab[i] = NULL;
  return (tab);
}
