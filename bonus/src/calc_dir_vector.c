/*
** calc_dir_vector.c for Raytracer in /home/invicta/bsraytracer1/src/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Thu Feb  9 09:22:00 2017 Kellian CIPIERRE
** Last update May Apr 20 14:13:47 2017
*/

#include <stdlib.h>
#include <math.h>
#include "graph.h"

float		calc_dir_vector(sfVector2f *from, sfVector2f *to)
{
  float		adj;
  float		opp;
  float		way;

  adj = (to->x - from->x);
  opp = (to->y - from->y);
  if (opp == 0)
    return (1);
  way = atan(adj / opp);
  if (adj < 0)
    {
      if (opp < 0)
	return (way - 0.5);
      return (way + 0.5);
    }
  if (opp < 0)
    return (way + 0.5);
  return (way - 0.5);
}
