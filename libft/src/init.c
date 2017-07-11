/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 03:07:57 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/21 03:23:13 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_flags		*flagsnew(t_flags *new)
{
	new = ft_memalloc(sizeof(t_flags));
	new->hash = 0;
	new->zero = 0;
	new->min = 0;
	new->space = 0;
	new->plus = 0;
	new->apos = 0;
	return (new);
}

t_conv		*convnew(t_conv *new)
{
	new = ft_memalloc(sizeof(t_conv));
	new->id = 0;
	new->flags = flagsnew(new->flags);
	new->width = 0;
	new->preci = 0;
	new->len = 0;
	new->type = NULL;
	return (new);
}

t_env		*envnew(t_env *new, char *format)
{
	new = ft_memalloc(sizeof(t_env));
	new->form = format;
	new->str = ft_strnew(0);
	new->i = 0;
	new->numbered = 0;
	new->conv = NULL;
	return (new);
}
