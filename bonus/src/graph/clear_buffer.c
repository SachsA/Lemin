/*
** clear_buffer.c for clear_buffer in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 31 21:18:21 2017 Alexandre Sachs
** Last update Apr Apr 26 18:49:24 2017
*/

#include "graph.h"

int		clear_buffer(t_my_framebuffer *framebuffer)
{
  unsigned int		i;

  i = 0;
  while (i < (framebuffer->height * framebuffer->width * 4))
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (0);
}
