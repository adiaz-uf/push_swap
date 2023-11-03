NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft/
SRC_DIR = src/

SRC = src/push_swap.c \
		src/operations.c \
		src/swap_and_push.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/sort_small.c \
		src/sort_medium.c \
		src/sort_big.c \
		src/ft_in_order.c \
		src/algorithm.c \
		src/multiple_numbers.c \
		src/parser.c \
		
OBJS = $(SRC:.c=.o)

INCLUDE = -L ./libft -lft

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(NAME)
	@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus

