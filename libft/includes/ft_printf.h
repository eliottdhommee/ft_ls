/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:18:58 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:19:08 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 1024

typedef enum	e_lenght
{
	hh, h, l, ll, j, t, z, q, L, NONE
}				t_lenght;

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			min;
	int			space;
	int			plus;
	int			apos;
}				t_flags;

typedef struct	s_conv
{
	t_flags		*flags;
	int			width;
	int			preci;
	t_lenght	len;
	char		type;
	int			id;
	void		*ptr;
}				t_conv;

typedef struct	s_env
{
	const char	*form;
	int			i;
	char		buf[BUFF_SIZE];
	int			j;
	int			nbarg;
	int			numbered;
	t_conv		*conv;
	int			ret;
	int			fd;
}				t_env;

/*
** MAIN
*/

int				ft_printf(const char *format, ...);
t_env			*conv_to_buffer(t_env *env);
t_env			*normal_to_buffer(t_env *env);

/*
** TO STR
*/

char			*nbr_to_str(t_env *env);
char			*float_to_str(t_env *env);
char			*chars_to_str(t_env *env);

/*
** INIT
*/

t_flags			*flagsnew(t_flags *flags);
t_conv			*convnew(t_conv *conv);
t_env			*envnew(t_env *env, const char *format);
void			convdel(t_conv **conv);
void			envdel(t_env **env);

/*
** CONV GETTERS
*/

int				get_id(t_env *env);
void			*get_arg(int id, va_list *ap);
t_flags			*get_flags(t_env *env);
int				get_width(va_list *ap, t_env *env);
int				get_preci(va_list *ap, t_env *env);
t_lenght		get_len(t_env *env);

/*
** FORMATING
*/

t_env			*putconv_to_buffer(char *str, t_env *env);
char			*setprecision(char *str, t_env *env);
char			*setapostrophe(char *str, t_env *env);

/*
** BUFFERING
*/

int				print_buffer(int size, t_env *env);
t_env			*putchar_to_buffer(char c, t_env *env);
t_env			*putstr_to_buffer(char *str, t_env *env);

/*
**	TOOLKIT
*/

int				isconv(char c);
int				istype(int c);
int				isflag(char c);
int				islenght(char c);
int				ismidwchar(unsigned int c);
int				isbegwchar(unsigned int c);

#endif
