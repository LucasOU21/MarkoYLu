# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 16:44:16 by mmitrovi          #+#    #+#              #
#    Updated: 2026/09/29 18:19:27 by mmitrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS = main.c \
bench.c \
disorder_m.c \
ops_push.c \
ops_rotate.c \
ops_rrotate.c \
ops_swap.c \
error.c \
parsing_args.c \
adqptive_strat.c \
complex_strat.c \
medium_strat.c \
simple_strat.c \
strats_select.c \
chunk_sort.c \
insertion_sort.c \
selection_sort.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re