# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 11:40:28 by Carlos            #+#    #+#              #
#    Updated: 2025/01/24 14:33:51 by cravegli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
							ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
							ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
							ft_putendl_fd.c  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
							ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
							ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
							ft_tolower.c ft_toupper.c ft_printf.c ft_printf_aux.c ft_printf_utils.c
							ft_get_next_line_bonus.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
						ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstclear.c

BONUS_OBJS		=$(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
AR				= ar rcs
NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(AR) $(NAME) $(OBJS)

bonus:			$(BONUS_OBJS)
				@$(AR) $(NAME) $(BONUS_OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all
