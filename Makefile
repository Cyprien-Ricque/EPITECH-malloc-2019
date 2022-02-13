##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	malloc.c	\
		free.c	\
		utils.c

OBJ     =	$(SRC:.c=.o)

CFLAGS    =    -W -Wall -Wextra  -I include -fpic

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -shared -o $(NAME) $(OBJ) -I include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all