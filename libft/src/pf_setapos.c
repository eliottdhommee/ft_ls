/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setapostrophe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:19:58 by mgalliou          #+#    #+#             */
/*   Updated: 2017/06/16 17:20:24 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*setapostrophe(char *str, t_env *env)
{
	char		*new;
	int			i;
	int			j;
	int			k;
	int			width;

	if (env->conv->flags->apos && ft_strchr("dub", env->conv->type))
	{
		i = ft_strlen(str);
		width = (env->conv->type != 'b' ? 3 : 4);
		k = i % width;
		j = i / width - (!k ? 1 : 0);
		new = ft_strnew(i + j);
		i = 0;
		j = 0;
		while (str[i])
		{
			new[j++] = str[i++];
			if (!--k || (k < 0 && !((k * -1) % width) && str[i]))
				new[j++] = ',';
		}
		ft_strdel(&str);
		return (new);
	}
	return (str);
}
