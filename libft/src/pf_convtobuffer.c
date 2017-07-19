/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convtobuffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:22:14 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:22:18 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*get_arg(int id, va_list *ap)
{
	va_list		tmp;
	void		*ptr;
	int			j;

	j = 0;
	va_copy(tmp, *ap);
	while (j < id)
	{
		ptr = va_arg(tmp, void*);
		j++;
	}
	return (ptr);
}

static t_env	*prebuffersimplify(char *str, t_env *env)
{
	if (!env->conv->ptr && ft_strchr("xX", env->conv->type))
		env->conv->flags->hash = 0;
	if (env->conv->flags->hash && env->conv->type == 'o')
	{
		if (env->conv->preci <= 0)
			env->conv->preci = ft_strlen(str) + 1;
		if (!env->conv->ptr)
			env->conv->preci = 1;
	}
	return (env);
}

static char		*invalidetype(char *str, t_env *env)
{
	str = ft_strnew(1);
	str[0] = env->conv->type;
	env->conv->type = 'c';
	return (str);
}

static void		ptrtype(t_env *env)
{
	int			*ptr;

	ptr = env->conv->ptr;
	*ptr = env->ret + env->j;
}

t_env			*conv_to_buffer(t_env *env)
{
	char		*str;

	str = NULL;
	if (!istype(env->conv->type))
		str = invalidetype(str, env);
	else if (ft_strchr("douxXpb", env->conv->type))
		str = nbr_to_str(env);
	else if (ft_strchr("f", env->conv->type))
		str = float_to_str(env);
	else if (ft_strchr("cs%", env->conv->type))
		str = chars_to_str(env);
	else if (env->conv->type == 'n')
		ptrtype(env);
	else if (env->conv->type == 'w')
		env->fd = (int)env->conv->ptr;
	if (!str && !ft_strchr("wn", env->conv->type))
		return (NULL);
	if (str)
	{
		env = prebuffersimplify(str, env);
		env = putconv_to_buffer(str, env);
	}
	return (env);
}
