# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 16:44:16 by mmitrovi          #+#    #+#              #
#    Updated: 2026/09/29 17:15:25 by mmitrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a


SRCS = insertion_sort.c \
selection_sort.c \
chunk_sort.c \
insertion_sort.c \
selection_sort.c \
chunk_sort.c \
sa.c \
sb.c \
create_node.c \
print_stack.c \
push.c \
rotate.c \
ra.c \
rb.c \
rr.c \


OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

# Ukupni include flegovi za zaglavlja (-I)
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re