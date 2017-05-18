/*
** my_fonction_base.c for my_fonction_base in /home/sachs_a/delivery/system_unix/PSU_2016_my_printf/bonus
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Nov 13 10:55:18 2016 Alexandre Sachs
** Last update Thu Nov 17 22:08:57 2016 Alexandre Sachs
*/

#include "my.h"

int		*my_fonction_base(unsigned int nb, char *base, int *compteur)
{
  unsigned int	taille;
  unsigned int	modulo;

  taille = my_strlen(base);
  modulo = nb % taille;
  nb = nb / taille;
  if (nb > 0)
    my_fonction_base(nb, base, compteur);
  my_putchar(base[modulo]);
  *compteur = *compteur + 1;
  return (compteur);
}

int		*my_fonction_base_long(unsigned long nb, char *base, int *compteur)
{
  unsigned int  taille;
  unsigned int  modulo;

  taille = my_strlen(base);
  modulo = nb % taille;
  nb = nb / taille;
  if (nb > 0)
    my_fonction_base(nb, base, compteur);
  my_putchar(base[modulo]);
  *compteur = *compteur + 1;
  return (compteur);
}
