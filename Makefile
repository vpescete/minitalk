NAME_S = server
NAME_C = client

SRC_S = server.c 
SRC_C = client.c \
		mini_libft/ft_atoi.c

OBJ_S = $(SRC_S.O=.c)
OBJ_C = $(SRC_C.O=.c)

FTPRINTF := ft_printf/

FLAG = -Wall -Werror -Wextra
CC = gcc

all: 
	make -C $(FTPRINTF)
	$(CC) $(FLAGS) $(SRC_S) ft_printf/libftprintf.a -o $(NAME_S)
	$(CC) $(FLAGS) $(SRC_C) ft_printf/libftprintf.a -o $(NAME_C)

server: 
	make -C $(FTPRINTF)
	$(CC) $(FLAGS) $(SRC_S) ft_printf/libftprintf.a -o $(NAME_S)
client: 
	make -C $(FTPRINTF)
	$(CC) $(FLAGS) $(SRC_C) ft_printf/libftprintf.a -o $(NAME_C)

clean: 
	make clean -C $(FTPRINTF)
	rm -f $(OBJ_S)
	rm -f $(OBJ_C)
	
fclean:	clean
	make fclean -C $(FTPRINTF)
	rm -f $(NAME_S)
	rm -f $(NAME_C)

re:	fclean all clean