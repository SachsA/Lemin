/*
** my_putchar.c for my_putchar in /home/sachs_a/delivery/fonctions_utiles
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Jan 11 14:52:08 2017 Alexandre Sachs
** Last update Sat Jan 14 14:59:08 2017 Alexandre Sachs
*/

#include "my.h"

void	my_putchar(char z)
{
  write(1, &z, 1);
}
