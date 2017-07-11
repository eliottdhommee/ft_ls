/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:22:27 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/21 17:37:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

va_list			*get_arg(t_env *env, va_list ap)
{
	static int		i = 1;
	int				j;

	j = 1;
	if (env->numbered > 0)
	{
		while (env->conv.id > 1)
		{
			va_arg(ap, void *);
			env->conv.id--;
		}
	}
	else
	{
		while (j < i)
		{
			va_arg(ap, void *);
			j++;
		}
	}
	return (ap);
}
