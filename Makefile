# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 18:33:11 by lmatthes          #+#    #+#              #
#    Updated: 2025/11/29 18:52:46 by lmatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I .
AR		= ar rcs
RM		= rm -f

SRC		= src/ft_printf.c \
		  src/ft_putchar.c \
		  src/ft_putstr.c \
		  src/ft_putptr.c \
		  src/ft_putnbr.c \
		  src/ft_putuint.c \
		  src/ft_puthex.c

OBJ		= $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(NAME) created!"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "Object files removed!"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re