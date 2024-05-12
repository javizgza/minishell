/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonza2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:06:48 by cagonza2          #+#    #+#             */
/*   Updated: 2023/10/08 12:47:50 by cagonza2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t			ft_strlcat(char *dst, char const *src, size_t size);
size_t			ft_strlcpy(char *dst, char const *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnstr(char const *str, char const *to_find, size_t size);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
char			**ft_split(char const *s, char c);
void			ft_bzero(void *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			*ft_memset(void *s, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(char const *str);
int				ft_lstsize(t_list *lst);
int				ft_atoi(char const *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strncmp(char *s1, char *S2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
#endif
