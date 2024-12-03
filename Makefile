
#####################################################
#####                   files                   #####
#####################################################

SRC = ft_printf.c useful.c ft_strlen.c

#####################################################
#####                 variables                 #####
#####################################################

NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h
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
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all