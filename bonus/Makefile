##
## Makefile for lemin in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin/
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Wed Apr 19 19:10:44 2017 Alexandre Sachs
## Last update Jan Apr 30 17:39:58 2017
##

CC		= gcc

RM		= rm -rf

ARRC		= ar crs

MK		= make

SRC_BIN		= src/main.c			\
		  src/visu_hex.c		\
		  src/get_ants.c		\
		  src/init_tab.c		\
		  src/graph/window.c		\
		  src/graph/clear_buffer.c	\
		  src/my_put_pixel.c		\
		  src/my_draw_line.c		\
		  src/draw_room.c		\
		  src/calc_dir_vector.c		\
		  src/move_forward.c		\
		  src/parsing/init.c		\
		  src/parsing/my_free.c		\
		  src/parsing/parsing.c		\
		  src/parsing/tri_list.c	\
		  src/parsing/my_clean.c	\
		  src/parsing/fill_links.c	\
		  src/parsing/nodes_carac.c	\
		  src/parsing/get_nb_ants.c

SRC_LIB		= ../src/basics/my_str1.c			\
		  ../src/basics/my_str2.c			\
		  ../src/basics/my_tablen.c			\
		  ../src/basics/my_getnbr.c			\
		  ../src/basics/get_next_line.c			\
		  ../src/basics/my_str_fusion.c			\
		  ../src/basics/my_show_wordtab.c		\
		  ../src/basics/my_str_to_wordtab.c		\
		  ../src/basics/my_str_to_wordtab_double.c

OBJ_BIN		= $(SRC_BIN:.c=.o)

OBJ_LIB		= $(SRC_LIB:.c=.o)

CFLAGS		+= -I ./include/ -I ../include
CFLAGS		+= -W -Wall -Wextra -Werror

LDFLAGS		+= -lc_graph_prog_full -lm -L./lib/my -lmy

NAME_BIN	= ./visu-hex

NAME_LIB	= ./lib/my/libmy.a

$(NAME_BIN):	$(OBJ_LIB) $(OBJ_BIN)
		$(ARRC) $(NAME_LIB) $(OBJ_LIB)
		$(CC) -o $(NAME_BIN) $(OBJ_BIN) $(LDFLAGS)

all:		$(NAME_BIN)

clean:
		$(RM) $(OBJ_BIN)
		$(RM) $(OBJ_LIB)

fclean:		clean
		$(RM) $(NAME_BIN)
		$(RM) $(NAME_LIB)

re:		fclean all

.PHONY:		all clean fclean re
