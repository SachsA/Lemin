/*
** get_ants.c for Lemin_Bonus in /home/invicta/CPE_2016_Lemin/bonus/src/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Tue Apr 25 11:15:25 2017 Kellian CIPIERRE
** Last update Jan Apr 30 17:34:52 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "graph.h"
#include "limits.h"
#include "basics.h"

int		free_ants_list(t_ants *ants)
{
  t_ants	*tmp;

  while (ants != NULL)
    {
      tmp = ants;
      ants = ants->next;
      free(tmp);
    }
  return (0);
}

int		new_ant(t_room **room, t_ants **ants, int id_ant,
			char *name)
{
  t_ants	*node;
  t_room	*ori;
  t_room	*dest;

  if ((node = malloc(sizeof(t_ants))) == NULL)
    return (0);
  ori = *room;
  while (ori != NULL && id_ant != ori->id_ant)
    ori = ori->next;
  if (ori == NULL)
    ori = *room;
  dest = *room;
  while (dest != NULL && my_strcmp(dest->name, name) != 0)
    dest = dest->next;
  node->next = *ants;
  ori->id_ant = 0;
  ori->nb_ant -= 1;
  dest->id_ant = id_ant;
  dest->nb_ant = 1;
  node->pos.y = ori->pos.y;
  node->pos.x = ori->pos.x;
  *ants = node;
  return (1);
}

void		update_ant(t_ants **ants, sfVector2f *scale, t_room *dest)
{
  (*ants)->way.y = ((dest->pos.y - (*ants)->pos.y));
  (*ants)->way.x = ((dest->pos.x - (*ants)->pos.x));
  (*ants)->pos.y = (*ants)->pos.y * scale->y + 100;
  (*ants)->pos.x = (*ants)->pos.x * scale->x + 100;
  (*ants)->way.y = ((*ants)->way.y * scale->y) / SPEED;
  (*ants)->way.x = ((*ants)->way.x * scale->x) / SPEED;
}

int		get_ants(t_my_framebuffer *pix, t_room **room, t_ants **ants,
			 char *str)
{
  int		i;
  int		id_ant;
  char		**moves;
  char		**stats;
  t_room	*dest;
  sfVector2f	scale;
  sfVector2i	tab;

  tab_size(room, &tab);
  moves = my_str_to_wordtab(str, ' ');
  i = -1;
  while (moves[++i] != NULL)
    {
      stats = my_str_to_wordtab(moves[i], '-');
      id_ant = my_getnbr(stats[0] + 1);
      scale.y = (pix->height - 200) / tab.y;
      scale.x = (pix->width - 200) / tab.x;
      new_ant(room, ants, id_ant, stats[1]);
      dest = *room;
      while (dest != NULL && my_strcmp(dest->name, stats[1]) != 0)
	dest = dest->next;
      update_ant(ants, &scale, dest);
    }
  return (0);
}
