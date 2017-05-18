/*
** my.h for myh in /home/sachs_a/delivery/system_unix/PSU_2016_my_ls/include
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Mon Nov 28 21:39:34 2016 Alexandre Sachs
** Last update Sat Jan 14 15:19:20 2017 Alexandre Sachs
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct          s_pointeur
{
  char  flag;
  int   (*fptr)(va_list list, int *);
}                       t_pointeur;

void    my_putchar(char);
int     my_putstr2(char *, int *);
int     my_putstr(char *);
int     my_put_nbr(int);
int     my_put_nbr2(int, int *);
int     my_strlen(char *);
char    *my_strcpy(char *, char *);
int     *my_fonction_base(unsigned int, char *, int *);
int     *my_fonction_base_long(unsigned long, char *, int *);
int     my_printf(char *, ...);
int     exec_pointeur(int, char *, va_list, int *);
void    display(t_pointeur *);
void    display_next(t_pointeur *);
int     display_char(va_list, int *);
int     display_str(va_list, int *);
int     display_nbr(va_list, int *);
int     display_nbr_bis(va_list, int *);
int     display_unsigned_int(va_list, int *);
int     display_hex_maj(va_list, int *);
int     display_hex_min(va_list, int *);
int     display_octale(va_list, int *);
int     display_str_octale2(char *, int, int *);
int     display_binaire(va_list, int *);
int     display_pointeur(va_list, int *);
int     display_str_octale(va_list, int *);

#endif /* !MY_H_ */
