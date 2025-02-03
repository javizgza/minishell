NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS =  ./execute/main.c\
		./libft/ft_strlen.c ./libft/ft_strjoin.c ./libft/ft_split.c ./libft/ft_substr.c ./libft/ft_strchr.c ./libft/ft_strncmp.c ./libft/ft_strlcat.c ./libft/ft_calloc.c ./libft/ft_bzero.c ./libft/ft_atoi.c ./libft/ft_strdup.c ./libft/ft_strlcpy.c ./libft/ft_memset.c ./libft/get_next_line_bonus.c ./libft/ft_strrchr.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c\
		./execute/utils/util.c ./execute/utils/env_utils.c ./execute/utils/file_utils.c\
		./execute/builtins/echo.c ./execute/builtins/pwd.c ./execute/builtins/env.c ./execute/builtins/cd.c ./execute/builtins/exit.c ./execute/builtins/export.c ./execute/builtins/unset.c\
		./execute/env/enviroment.c ./execute/env/execute.c ./execute/env/rediret.c ./execute/env/heredoc.c\

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