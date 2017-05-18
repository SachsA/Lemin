##
## Makefile for Makefile in /home/sachs_a/delivery/c_prog_elem/CPE_2016_Lemin
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Wed Apr  5 15:16:59 2017 Alexandre Sachs
## Last update Jan Apr 30 17:39:51 2017
##

ARRC			= ar crs

CC			= gcc

RM			= rm -rf

MK			= make

SRC_BIN			= src/main.c					\
			  src/parsing/init.c				\
			  src/parsing/my_free.c				\
			  src/parsing/parsing.c				\
			  src/parsing/tri_list.c			\
			  src/parsing/my_clean.c			\
			  src/parsing/fill_links.c			\
			  src/parsing/nodes_carac.c			\
			  src/parsing/opti_list.c			\
			  src/parsing/get_nb_ants.c			\
			  src/path/check_path.c				\
			  src/path/display_path.c			\
			  src/path/path_len.c				\
			  src/path/reverse_save.c			\
			  src/path/valid_save.c				\
			  src/path/valid_stack.c			\
			  src/path/show_path.c

SRC_LIB			= ./src/basics/my_str1.c			\
			  ./src/basics/my_str2.c			\
			  ./src/basics/my_tablen.c			\
			  ./src/basics/my_getnbr.c			\
			  ./src/basics/get_next_line.c			\
			  ./src/basics/my_str_fusion.c			\
			  ./src/basics/my_show_wordtab.c		\
			  ./src/basics/my_str_to_wordtab.c		\
			  ./src/basics/my_str_to_wordtab_double.c

OBJ_BIN			= $(SRC_BIN:.c=.o)

OBJ_LIB			= $(SRC_LIB:.c=.o)

CFLAGS			+= -I ./include/
CFLAGS			+= -I ./lib/my_printf/include/
CFLAGS			+= -W -Wall -Wextra

LDFLAGS			+= -L./lib/my -lmy
LDFLAGS			+= -L./lib/my_printf -lmy_printf

NAME_BIN		= ./lem_in

NAME_LIB		= ./lib/my/libmy.a

NAME_PRINT		= lib/my_printf/

$(NAME_BIN):		$(OBJ_LIB) $(OBJ_BIN)
			$(ARRC) $(NAME_LIB) $(OBJ_LIB)
			$(MK) -C $(NAME_PRINT)
			$(CC) -o $(NAME_BIN) $(OBJ_BIN) $(LDFLAGS)

all:			$(NAME_BIN)

clean:
			$(RM) $(OBJ_BIN)
			$(RM) $(OBJ_LIB)
			$(MK) clean -C $(NAME_PRINT)

fclean:			clean
			$(RM) $(NAME_BIN)
			$(RM) $(NAME_LIB)
			$(MK) fclean -C $(NAME_PRINT)

re:			fclean all

.PHONY:			all clean fclean re
