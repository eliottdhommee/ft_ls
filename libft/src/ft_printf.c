/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:25:04 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:25:06 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_conv	*simplify_conv(t_conv *conv)
{
	if (conv->type == 'i')
		conv->type = 'd';
	if (ft_strchr("DOUCSp", conv->type))
	{
		conv->type = ft_tolower(conv->type);
		conv->len = l;
	}
	if (conv->width < 0)
	{
		conv->flags->min = 1;
		conv->width *= -1;
	}
	if (conv->type == 'p')
		conv->flags->hash = 1;
	if (conv->flags->min || (ft_strchr("douxX", conv->type) && conv->preci > 0))
		conv->flags->zero = 0;
	if (conv->type != 'd')
	{
		conv->flags->plus = 0;
		conv->flags->space = 0;
	}
	if (conv->flags->plus)
		conv->flags->space = 0;
	return (conv);
}

static t_env	*get_conv(va_list *ap, t_env *env)
{
	env->i++;
	env->conv = convnew(env->conv);
	env->conv->id = get_id(env);
	env->conv->flags = get_flags(env);
	env->conv->width = get_width(ap, env);
	if (env->form[env->i] == '.')
		env->conv->preci = get_preci(ap, env);
	if (islenght(env->form[env->i]))
		env->conv->len = get_len(env);
	env->conv->type = env->form[env->i];
	if (istype(env->conv->type) && env->conv->type != '%')
		env->conv->ptr = get_arg(env->conv->id, ap);
	else
		env->nbarg--;
	env->conv = simplify_conv(env->conv);
	return (env);
}

static t_env	*print(va_list *ap, t_env *env)
{
	while (env->form[env->i])
	{
		if (env->form[env->i] == '%')
		{
			env = get_conv(ap, env);
			if (env->conv->type)
			{
				if (!(env = conv_to_buffer(env)))
					return (NULL);
				env->i++;
			}
			convdel(&env->conv);
		}
		else
			env = normal_to_buffer(env);
	}
	if (env && env->j)
		env->ret += print_buffer(env->j, env);
	return (env);
}

int				ft_printf(const char *format, ...)
{
	t_env		*env;
	va_list		ap;
	int			ret;

	env = NULL;
	env = envnew(env, format);
	if (!format)
		return (-1);
	else
	{
		va_start(ap, format);
		if (!(env = print(&ap, env)))
			ret = -1;
		va_end(ap);
	}
	if (env)
	{
		ret = env->ret;
		envdel(&env);
	}
	return (ret);
}
