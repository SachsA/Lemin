/*
** path.h for  in /home/BLENEA_T/Projects/Semestre_2/CPE/CPE_2016_Lemin
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Apr 18 12:38:43 2017 Thomas BLENEAU
** Last update Mon Apr 24 21:30:05 2017 Thomas BLENEAU
*/

#ifndef PATH_H_
# define PATH_H_

# include "my.h"

/*
** Prototypes de fonctions
*/
int	check_order_path(t_save **);
int	check_path(t_link **, t_room *);
int	check_room_path(t_link *, t_link *);
int	display_path(t_save **, t_room **);
int	link_len(t_link *);
int	path_cmp_len(t_save *, t_save *);
int	push_out_save(t_save **, t_save *);
int	put_stack_list(t_link **, t_room *);
int	reverse_save(t_save **);
int	save_len(t_save **);
int	swap_save(t_save **, t_save *);
int	valid_save(t_save **, t_room **);
int	valid_stack(t_room **, t_room *, t_link *, t_save **);
void	free_end_stack(t_link *);
void	free_link(t_link *);
void	free_save(t_save **);

#endif /* !PATH_H_ */
