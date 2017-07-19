/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:22:35 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:22:37 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	new->width = 0;
	new->preci = -1;
	new->len = NONE;
	new->type = 0;
	new->id = 0;
	new->ptr = NULL;
	return (new);
}

t_env		*envnew(t_env *new, const char *format)
{
	new = ft_memalloc(sizeof(t_env));
	new->form = format;
	new->i = 0;
	new->j = 0;
	new->numbered = 0;
	new->conv = NULL;
	new->ret = 0;
	new->nbarg = 0;
	new->fd = 1;
	return (new);
}

void		convdel(t_conv **conv)
{
	t_conv	*tmp;

	tmp = *conv;
	ft_memdel((void*)&tmp->flags);
	ft_memdel((void*)&tmp);
}

void		envdel(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	tmp->form = NULL;
	ft_memdel((void*)&tmp);
}
