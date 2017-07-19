/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:40:27 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/19 11:49:21 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

void				ft_putchar(char c);
void				ft_putstr(const char *s);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
void				ft_strclr(char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_reverse(char *str, int size);
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *big, const char *little);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,\
					size_t len);
void				*ft_memcpy_rev(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_wchartoa(wint_t wint);
char				*ft_itoa_base(uintmax_t n, int base);
char				*ft_strlowcase(char *s);
char				*ft_strndup(const char *s1, size_t n);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));

int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);

enum				e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef	struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
	enum e_rb_color	color;
}					t_btree;

void				btree_print(t_btree *root, char *type, int level);
t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void(*applyf)(void*));
void				btree_apply_infix(t_btree *root, void(*applyf)(void*));
void				btree_apply_suffix(t_btree *root, void(*applyf)(void*));
void				btree_insert_data(t_btree **root, 
							void *item, int (*cmpf)(void*, void*));
void				*btree_search_item(t_btree *root, 
							void *data_ref, int (*cmpf)(void*, void*));
int					btree_level_count(t_btree *root);
void				btree_apply_by_level(t_btree *root, void (*applyf)
							(void *item, int current_level, int is_first_elem));
void				rb_left_rotate(t_btree *node);
void				rb_right_rotate(t_btree *node);

#endif
