NAME = push_swap.a

SOURCES = push_swap.c push_swap_utils.c small_sort.c functions.c big_sort_part2.c \
			big_sort_part3.c big_sort_part4.c functions_part2.c big_sort_onehalf.c big_sort.c \
			small_sort_part2.c big_sort_twohalf.c big_sort_last.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
libft = ./libft/libft.a

all: $(NAME)

$(NAME) : $(OBJECTS) 
	$(AR) -r $@ $? ./libft/*.o
	gcc push_swap.c $(NAME) -o push_swap

%.o: %.c
	make -C ./libft
	$(CC) -c $(CFLAGS) $? 

clean:
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft 
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re