NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = mandatory/ft_printf.c mandatory/ft_format.c mandatory/ft_putchar.c \
       mandatory/ft_putnbr.c mandatory/ft_puthex.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/ft_printf_bonus.c bonus/ft_parse_bonus.c \
             bonus/ft_dispatch_bonus.c bonus/ft_nbr_bonus.c \
             bonus/ft_flags_bonus.c bonus/ft_prec_bonus.c \
             bonus/ft_width_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

bonus: fclean $(LIBFT) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus