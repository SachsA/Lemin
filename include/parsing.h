/*
** parsing.h for parsing.h in /home/sachs_a/delivery/c_prog_elem/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Apr 10 17:58:58 2017 Alexandre Sachs
** Last update May Apr 27 12:08:04 2017
*/

#ifndef PARSING_H_
# define PARSING_H_

# include "my.h"

int	get_nb_ants();
char	*my_clean(char *);
void	free_link(t_link*);
int	tri_list(t_room **);
char	*parsing(t_room **);
int	opti_list(t_room **);
void	my_free_tab(char **);
int     comment(char *, int);
int	init_room(t_room **);
void	free_list(t_room **, int);
int	fill_links(char *, t_room **);
int	nodes_carac(char *, char *, t_room **);

#endif /* !PARSING_H_ */
