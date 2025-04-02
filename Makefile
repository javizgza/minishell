NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -f

LIB = ar rcs

SRCS =  ./src/execute/main.c ./src/execute/main_extra.c\
		./libft/ft_strlen.c ./libft/ft_strjoin.c ./libft/ft_split.c ./libft/ft_substr.c ./libft/ft_strchr.c ./libft/ft_strncmp.c ./libft/ft_strlcat.c ./libft/ft_calloc.c ./libft/ft_bzero.c ./libft/ft_atoi.c ./libft/ft_strdup.c ./libft/ft_strlcpy.c ./libft/ft_memset.c ./libft/get_next_line_bonus.c ./libft/ft_strrchr.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_itoa.c ./libft/ft_putnbr_fd.c\
		./src/execute/utils/util.c ./src/execute/utils/env_utils.c ./src/execute/utils/file_utils.c ./src/execute/utils/command_utils.c\
		./src/execute/builtins/echo.c ./src/execute/builtins/pwd.c ./src/execute/builtins/env.c ./src/execute/builtins/cd.c ./src/execute/builtins/exit.c ./src/execute/builtins/export.c ./src/execute/builtins/unset.c\
		./src/execute/env/enviroment.c ./src/execute/env/execute.c ./src/execute/env/rediret.c ./src/execute/env/heredoc.c\
		./src/parsing/define_tokens.c ./src/parsing/lexer.c ./src/parsing/parser_utils2.c ./src/parsing/parser_utils.c ./src/parsing/has_dollar.c ./src/parsing/signals.c

OBJTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJTS) -lreadline

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJTS)

re: fclean all

.PHONY: all clean fclean re