NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS =  ./execute/main.c\
		./libft/ft_strlen.c ./libft/ft_strjoin.c ./libft/ft_split.c ./libft/ft_substr.c\
		./execute/utils/util.c\
		./execute/builtins/echo.c\

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