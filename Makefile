NAME = push_swap.a

SOURCES = *.c\

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