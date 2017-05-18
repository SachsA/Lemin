/*
** window.c for Lemin_graph in /home/invicta/CPE_2016_Lemin/bonus/src/graph/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Wed Apr 19 19:55:58 2017 Kellian CIPIERRE
** Last update Apr Apr 26 20:01:10 2017
*/

#include <stdlib.h>
#include "graph.h"

void			my_window_update(t_my_framebuffer *framebuffer,
					 t_window *my_window)
{
  sfRenderWindow_clear(my_window->window, sfBlack);
  sfTexture_updateFromPixels(my_window->texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(my_window->window, my_window->sprite, NULL);
  sfRenderWindow_display(my_window->window);
  clear_buffer(framebuffer);
}

t_my_framebuffer       	*my_framebuffer_create(int width, int height)
{
  int		       	i;
  t_my_framebuffer     	*framebuffer;

  i = -1;
  framebuffer = malloc(sizeof(t_my_framebuffer));
  if (framebuffer == NULL)
    return (0);
  framebuffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
  if (framebuffer->pixels == NULL)
    return (0);
  while (++i < width * height * 4)
    framebuffer->pixels[i] = 0;
  framebuffer->width = SCREEN_WIDTH;
  framebuffer->height = SCREEN_HEIGHT;
  return (framebuffer);
}

sfRenderWindow		*create_window(char *str, int width,
				       int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.bitsPerPixel = 32;
  mode.width = width;
  mode.height = height;
  window = sfRenderWindow_create(mode, str, sfResize |
				 sfClose, NULL);
  return (window);
}

void			set_window(t_my_framebuffer **framebuffer,
				   t_window **my_window)
{
  (*my_window)->window = create_window("LEMIN BLENEAU COTONI CIPIERRE SACHS",
				       SCREEN_WIDTH, SCREEN_HEIGHT);
  sfRenderWindow_setVerticalSyncEnabled((*my_window)->window, sfTrue);
  *framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  (*my_window)->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  (*my_window)->sprite = sfSprite_create();
  sfSprite_setTexture((*my_window)->sprite, (*my_window)->texture, sfTrue);
}

int			my_event(t_window *my_window,
				 t_my_framebuffer *framebuffer)
{
  sfEvent      		event;

  while (sfRenderWindow_pollEvent(my_window->window, &event))
    {
      if ((event.type == sfEvtClosed) ||
	  (sfKeyboard_isKeyPressed(sfKeyEscape)))
	{
	  sfRenderWindow_close(my_window->window);
	  free(framebuffer->pixels);
	  free(framebuffer);
	  sfRenderWindow_destroy(my_window->window);
	  return (0);
	}
    }
  return (1);
}
