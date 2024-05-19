NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -f

LIB = ar rcs

SRCS =  ./execute/main.c\
		./libft/ft_strlen.c ./libft/ft_strjoin.c\

OBJTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJTS) -lreadline

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJTS)

re: all clean

.PHONY: all clean fclean re