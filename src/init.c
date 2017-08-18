/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:19:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/18 16:45:33 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char		*init_flags(char **str)
{
	*str = ft_memalloc(sizeof(char*) * 128);
	ft_bzero(*str, sizeof(char) * 127);
	return (*str);
}

void		delete_tab(char **tab)
{
	free(tab[0]);
	free(tab[2]);
}

void		delete_file(void *file)
{
	if (!file)
		return ;
	else
	{
		ft_memdel((void*)&((t_file*)file)->name);
		ft_memdel((void*)&((t_file*)file)->pass);
		ft_memdel((void*)&((t_file*)file)->path);
		ft_memdel((void*)&((t_file*)file)->grp);
		ft_memdel((void*)&file);
	}
}
