/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:24:12 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:24:14 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char		*stringprecision(char *new, char *str, t_env *env)
{
	if (env->conv->len == l && env->conv->preci > 0)
	{
		while (isbegwchar(str[env->conv->preci - 1]) ||
				(ismidwchar(str[env->conv->preci - 1]) &&
				ismidwchar(str[env->conv->preci])))
			env->conv->preci--;
	}
	new = ft_strndup(str, env->conv->preci);
	return (new);
}

char			*setprecision(char *str, t_env *env)
{
	char		*new;
	int			precilen;

	new = NULL;
	precilen = (env->conv->preci - ft_strlen(str));
	if (!ft_strchr("c%", env->conv->type))
	{
		if (env->conv->type != 's' && !env->conv->ptr && !env->conv->preci)
			new = ft_strnew(0);
		else if (env->conv->type == 's' && env->conv->preci >= 0)
			new = stringprecision(new, str, env);
		else if (precilen > 0)
		{
			new = ft_strnew(precilen + ft_strlen(str));
			while (precilen--)
				new[precilen] = '0';
			new = ft_strcat(new, str);
		}
		if (new)
		{
			ft_strdel(&str);
			return (new);
		}
	}
	return (str);
}
