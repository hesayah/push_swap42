/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:15:41 by hesayah           #+#    #+#             */
/*   Updated: 2022/03/17 19:39:24 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_lst
{
	long			value;
	struct s_lst	*next;
}					t_lst;

char				*ft_char_to_str(char c);
void				ft_free(char **tab);
void				ft_strcpy(char *dst, const char *src);
void				*ft_memset(void *str, int c, size_t len);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
size_t				ft_strlen(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
long				ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_strtrim(char const *str1, char const *set);
char				**ft_split(char const *str, const char *set);
char				*ft_itoa(int nb);
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_add_str_tab(char **tab, char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_lstadd_back(t_lst **alst, t_lst *new);
void				ft_lstadd_front(t_lst **alst, t_lst *new);
void				ft_lstclear(t_lst **lst, void (*del)(int));
void				ft_lstdelone(t_lst *lst, void (*del)(int));
void				ft_lstiter(t_lst *lst, void (*f)(int));
t_lst				*ft_lstlast(t_lst *lst);
t_lst				*ft_lstmap(t_lst *lst, void *(*f)(int),
						void (*del)(int));
t_lst				*ft_lstnew(int value);
int					ft_lstsize(t_lst *lst);
int					ft_c_in_str(char c, char *s2);

#endif
