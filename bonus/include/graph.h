/*
** my.h for lemin in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin/bonus/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Wed Apr 19 19:08:50 2017 Alexandre Sachs
** Last update Jan Apr 30 18:26:42 2017
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include <SFML/Graphics.h>
# include "my.h"

# define UNUSED __attribute__((unused))

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 980

typedef struct		s_my_framebuffer
{
  sfUint8               *pixels;
  unsigned int          width;
  unsigned int          height;
}			t_my_framebuffer;

typedef struct          s_window
{
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  sfEvent               event;
  sfColor               color;
}                       t_window;

typedef struct		s_ants
{
  sfVector2f		pos;
  sfVector2f		way;
  struct s_ants		*next;
}			t_ants;

/*
** INIT_WINDOW
*/
t_my_framebuffer	*my_framebuffer_create(int, int);
sfRenderWindow		*create_window(char *, int, int);
void			my_window_update(t_my_framebuffer *, t_window *);
void			set_window(t_my_framebuffer **, t_window **);
int			my_event(t_window*, t_my_framebuffer*);
int			my_init_window(t_window *, t_room**);
int			clear_buffer(t_my_framebuffer*);

/*
** PRINT_OBJ
*/
int			draw_room(t_my_framebuffer*, sfVector2f*,
				  sfVector2i*, sfColor);
int			draw_link(t_my_framebuffer*, t_room*, sfVector2i*);
void			my_draw_line(t_my_framebuffer*, sfVector2i, sfVector2i,
			     sfColor);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
int			tab_size(t_room**, sfVector2i*);
float			calc_dir_vector(sfVector2f*, sfVector2f*);
sfVector2f		move_forward(sfVector2f*, float, float);
int			get_ants(t_my_framebuffer*, t_room**, t_ants**, char*);
int			free_ants_list(t_ants*);

#endif /* !MY_H_ */
