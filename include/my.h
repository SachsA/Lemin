/*
** my.h for myh in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Tue Apr 11 13:32:57 2017 Alexandre Sachs
** Last update Mon Apr 24 16:15:40 2017 Thomas BLENEAU
*/

#ifndef MY_H_
# define MY_H_

/*
** Structure Partie Graphique
*/
typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

/*
** Structure Parsing et Algo
*/
typedef struct	s_room
{
  char		*name;
  int		id_ant;
  int		place;
  int		nb_ant;
  t_pos		pos;
  struct s_room	*next;
  struct s_link	*link;
}		t_room;

typedef struct	s_link
{
  t_room	*room;
  struct s_link	*next;
}		t_link;

/*
** Liste chainée stack pour sauvegarder chemin le plus court
*/
typedef struct		s_save
{
  t_link		*link;
  struct s_save		*prev;
  struct s_save		*next;
}			t_save;

#endif /* !MY_H_ */
