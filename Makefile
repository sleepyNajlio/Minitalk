NAME= talk


$(NAME):
	@make -sC ./Libft
	@cp ./Libft/libft.a .
	gcc -Wall -Werror -Wextra -fsanitize=address -g libft.a server.c -o server
	gcc -Wall -Werror -Wextra -fsanitize=address -g libft.a client.c -o client
all: $(NAME)

re: fclean all

clean:
	@rm -rf $(NAME) $(OBJ) a.out server client
	@make -sC ./Libft/ fclean
	@clear

fclean: clean
		@rm -rf libft.a talk.a

.PHONY: all clean re fclean