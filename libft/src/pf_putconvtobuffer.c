/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putconvtobuffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:23:37 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:23:38 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_env	*hash_to_buffer(t_env *env)
{
	if (env->conv->flags->hash)
		if (ft_strchr("xXp", env->conv->type))
		{
			if (env->conv->type == 'X')
				env = putstr_to_buffer("0X", env);
			else
				env = putstr_to_buffer("0x", env);
		}
	return (env);
}

static t_env	*sign_to_buffer(t_env *env)
{
	if (env->conv->flags->plus == 1)
		env = putchar_to_buffer('+', env);
	else if (env->conv->flags->plus == -1)
		env = putchar_to_buffer('-', env);
	else if (env->conv->flags->space)
		env = putchar_to_buffer(' ', env);
	return (env);
}

static t_env	*padding_to_buffer(int len, char c, t_env *env)
{
	char		*new;

	new = ft_strnew(len);
	while (len--)
		new[len] = c;
	env = putstr_to_buffer(new, env);
	ft_strdel(&new);
	return (env);
}

static int		getpaddinglen(char *str, t_env *env)
{
	int			len;

	len = 0;
	len = ft_strlen(str);
	if (!str[0] && env->conv->type == 'c')
		len++;
	if (env->conv->preci > len && len > env->conv->width)
		len = env->conv->preci;
	if (env->conv->flags->plus || env->conv->flags->space)
		len++;
	if (env->conv->flags->hash && env->conv->type != 'o')
	{
		len += 2;
	}
	if (env->conv->width > len)
		return (env->conv->width - len);
	return (0);
}

t_env			*putconv_to_buffer(char *str, t_env *env)
{
	int			padlen;

	str = setprecision(str, env);
	str = setapostrophe(str, env);
	padlen = getpaddinglen(str, env);
	if (!env->conv->flags->zero && !env->conv->flags->min && padlen)
		env = padding_to_buffer(padlen, ' ', env);
	env = hash_to_buffer(env);
	env = sign_to_buffer(env);
	if (env->conv->flags->zero && padlen)
		env = padding_to_buffer(padlen, '0', env);
	if (ft_strchr("xp", env->conv->type))
		str = ft_strlowcase(str);
	if (!str)
		return (NULL);
	if (env->conv->type == 'c' && (!str[0] || env->conv->len != l))
		env = putchar_to_buffer(str[0], env);
	else
		env = putstr_to_buffer(str, env);
	if (!env->conv->flags->zero && env->conv->flags->min && padlen)
		env = padding_to_buffer(padlen, ' ', env);
	ft_strdel(&str);
	return (env);
}
