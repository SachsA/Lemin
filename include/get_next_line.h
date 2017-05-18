/*
** get_next_line.h for gnlh in /home/sachs_a/delivery/fonction_utiles/repo
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Tue Apr 11 18:12:46 2017 Alexandre Sachs
** Last update Tue Apr 11 18:12:46 2017 Alexandre Sachs
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE 30
# endif /* !READ_SIZE */

typedef struct	s_var_gnl
{
  int	fin;
  int	pos;
  char	buffer[READ_SIZE + 1];
}		t_var_gnl;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
