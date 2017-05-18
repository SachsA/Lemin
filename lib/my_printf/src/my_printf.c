/*
** my_printf.c for my_printf in /home/sachs_a/delivery/system_unix/PSU_2016_my_printf/bonus/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Nov 13 12:03:29 2016 Alexandre Sachs
** Last update Sat Jan 14 15:22:37 2017 Alexandre Sachs
*/

#include "my.h"

void		display(t_pointeur *tab_ptr)
{
  tab_ptr[0].flag = 'c';
  tab_ptr[0].fptr = &display_char;
  tab_ptr[1].flag = 's';
  tab_ptr[1].fptr = &display_str;
  tab_ptr[2].flag = 'd';
  tab_ptr[2].fptr = &display_nbr;
  tab_ptr[3].flag = 'i';
  tab_ptr[3].fptr = &display_nbr_bis;
  tab_ptr[4].flag = 'u';
  tab_ptr[4].fptr = &display_unsigned_int;
  tab_ptr[5].flag = 'X';
  tab_ptr[5].fptr = &display_hex_maj;
  tab_ptr[6].flag = 'x';
  tab_ptr[6].fptr = &display_hex_min;
  tab_ptr[7].flag = 'o';
  tab_ptr[7].fptr = &display_octale;
  tab_ptr[8].flag = 'b';
  tab_ptr[8].fptr = &display_binaire;
  tab_ptr[9].flag = 'p';
  tab_ptr[9].fptr = &display_pointeur;
  tab_ptr[10].flag = 'S';
  tab_ptr[10].fptr = &display_str_octale;
}

int		exec_pointeur(int i, char *str, va_list list, int *compteur)
{
  int		j;
  t_pointeur    tab_ptr[11];

  display(tab_ptr);
  j = -1;
  while (++j < 11)
    {
      if (str[i] == tab_ptr[j].flag)
	{
	  tab_ptr[j].fptr(list, compteur);
	  j = j + 11;
	}
    }
  if (j == 11)
    {
      my_putchar('%');
      *compteur = *compteur + 1;
    }
  return (0);
}

int		my_printf(char *str, ...)
{
  int		i;
  va_list	list;
  int		compteur;
  int		final;

  i = -1;
  final = 0;
  compteur = 0;
  va_start(list, str);
  while (str[++i] != '\0')
    {
      compteur = 0;
      if (str[i] == '%')
	exec_pointeur(++i, str, list, &compteur);
      else
	{
	  my_putchar(str[i]);
	  compteur = compteur + 1;
	}
      final = final + compteur;
    }
  va_end(list);
  return (final);
}
