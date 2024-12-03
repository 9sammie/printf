
#####################################################
#####                   files                   #####
#####################################################

SRC = ft_printf.c usefull.c

#####################################################
#####                 variables                 #####
#####################################################

NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
HEADER = libftprintf.h
CC = cc
CFLAGS = -Wall -Werror -Wextra

#####################################################
#####                 commands                  #####
#####################################################

.PHONY: all
all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: clean
clean: $(OBJ)
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all