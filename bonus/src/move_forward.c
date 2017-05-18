/*
** move_forward.c for Wolf3d in /home/invicta/wolf3d/src/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Wed Dec 28 17:58:42 2016 Kellian CIPIERRE
** Last update May Apr 20 13:13:41 2017
*/

#include <stdio.h>
#include <math.h>
#include "graph.h"

sfVector2f	move_forward(sfVector2f *pos, float distance, float direction)
{
  sfVector2f	new_pos;

  direction = direction * 180 / M_PI;
  new_pos.x = pos->x + (distance * cos(direction));
  new_pos.y = pos->y + (distance * sin(direction));
  return (new_pos);
}
