# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 16:44:16 by mmitrovi          #+#    #+#              #
#    Updated: 2026/09/29 17:50:40 by mmitrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a


SRCS = main.c \
       src/ops_cons/ops_swap.c \
       src/ops_cons/ops_push.c \
       src/create_node.c \
       src/print_stack.c \
       src/push.c \
       src/rotate.c \
       src/ra.c \
       src/rb.c \
       src/rr.c \
       src/insertion_sort.c \
       selection_sort.c \
       chunk_sort.c


OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re