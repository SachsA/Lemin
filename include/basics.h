/*
** basics.h for basics in /home/sachs_a/delivery/c_prog_elem/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Wed Apr  5 15:20:47 2017 Alexandre Sachs
** Last update Wed Apr  5 15:20:47 2017 Alexandre Sachs
*/

#ifndef BASICS_H_
# define BASICS_H_

int	my_getnbr(char *);
int	my_strlen(char *);
int	my_tablen(char **);
char	*my_strdup(char *);
int     my_str_isnum(char *);
int	my_printf(char *, ...);
int	my_show_wordtab(char **);
int	my_strcmp(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
char    *my_str_fusion(char *, char *);
int     my_strncmp(char *, char *, int);
char    *my_strncpy(char *, char *, int);
char    *my_strncat(char *, char *, int);
char	**my_str_to_wordtab(char *, char);
char	**my_str_to_wordtab_double(char *, char, char);

#endif /* !BASICS_H_ */
