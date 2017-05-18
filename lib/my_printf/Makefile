##
## Makefile for Makefile in /home/sachs_a/delivery/system_unix/my_ls_documents
## 
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
## 
## Started on  Tue Nov 22 16:21:49 2016 Alexandre Sachs
## Last update Mon Feb 20 11:59:52 2017 Alexandre Sachs
##

ARRC			= ar crs

CC			= gcc

SRC			= ./src/main.c				\
			  ./src/my_fonction1.c			\
			  ./src/my_fonction2.c			\
			  ./src/my_fonction3.c			\
			  ./src/my_fonction_base.c		\
			  ./src/my_printf.c			\
			  ./src/my_putchar.c			\
			  ./src/my_put_nbr.c			\
			  ./src/my_putstr.c			\
			  ./src/my_strcpy.c			\
			  ./src/my_strlen.c

RM			= rm -f

OBJ			= $(SRC:.c=.o)

CFLAGS			+= -I ./include/
CFLAGS			+= -W -Wall -Wextra

LDFLAGS			+= -L./lib/my -lmy

NAME			= ./libmy_printf.a

all:			$(NAME)

$(NAME):		$(OBJ)
			$(ARRC) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
