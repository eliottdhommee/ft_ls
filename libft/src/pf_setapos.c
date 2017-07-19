/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setapos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:23:54 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:23:56 by edhommee         ###   ########.fr       */
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
