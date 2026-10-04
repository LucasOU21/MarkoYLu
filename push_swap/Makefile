NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I . -I libft

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS = main.c \
src/parsing/parse_args.c \
src/parsing/ps_atoi.c \
src/stack/stack_new.c \
src/stack/stack_print.c \
src/stack/stack_utils.c \
src/stack/stack_index.c \
src/ops/ops_push.c \
src/ops/ops_rotate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re