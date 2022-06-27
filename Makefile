NAME = server client

all : $(NAME)

$(NAME):
	@make -sC ./Libft
	@gcc -Wall -Wextra -Werror libft/libft.a server.c -o server
	@gcc -Wall -Wextra -Werror libft/libft.a client.c -o client
	@echo "✅🤖✅"
clean:
	@rm -f $(NAME) server client
	@make -sC ./Libft/ fclean
	@echo "🚮🚮🚮"
fclean: clean
re: clean all