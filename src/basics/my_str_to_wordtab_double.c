/*
** my_str_to_wordtab_double.c for mysh in /home/sachs_a/delivery/system_unix/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Mar 15 10:59:39 2017 Alexandre Sachs
** Last update Mon Apr  3 20:45:16 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "basics.h"

int	separators_double(char *str, char sep, char sep2)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (!str)
    return (-1);
  while ((str[i] == sep && str[i]) || (str[i] == sep2 && str[i]))
    i++;
  while (str[i])
    {
      while ((str[i] != sep && str[i]) && (str[i] != sep2 && str[i]))
	i++;
      c++;
      while ((str[i] == sep && str[i]) || (str[i] == sep2 && str[i]))
	i++;
    }
  return (c);
}

int	word_size_double(char *str, int c, char sep, char sep2)
{
  int	i;

  i = 0;
  if (!str)
    return (-1);
  while ((str[i] == sep && str[i]) || (str[i] == sep2 && str[i]))
    i++;
  while (c != 1)
    {
      while ((str[i] != sep && str[i]) && (str[i] != sep2 && str[i]))
	i++;
      while ((str[i] == sep && str[i]) || (str[i] == sep2 && str[i]))
	i++;
      c--;
    }
  c = 0;
  while ((str[i] != sep && str[i] != sep2) && str[i++] != '\0')
    c++;
  return (c + 1);
}

char	**my_str_to_wordtab_double(char *str, char sep, char sep2)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  k = 0;
  i = 0;
  if (!str || (tab = malloc(sizeof(char *) *
			    (separators_double(str, sep, sep2) + 1))) == NULL)
    return (NULL);
  while (i != (separators_double(str, sep, sep2)))
    {
      j = 0;
      if ((tab[i] = malloc(sizeof(char) * (word_size_double(str, (i + 1), sep,
							    sep2)))) == NULL)
	return (NULL);
      while ((str[k] != sep && str[k]) && (str[k] != sep2 && str[k]))
	tab[i][j++] = str[k++];
      tab[i][j] = '\0';
      while ((str[k] == sep && str[k]) || (str[k] == sep2 && str[k]))
	k++;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
