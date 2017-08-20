/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:19:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/18 21:15:46 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char		*init_flags(char **str)
{
	*str = ft_memalloc(sizeof(char*) * 128);
	ft_bzero(*str, sizeof(char) * 127);
	return (*str);
}

void		reset_padding(char *str)
{
	str['2'] = '\0';
	str['3'] = '\0';
	str['4'] = '\0';
	str['5'] = '\0';
	str['6'] = '\0';
}

void		delete_tab(char **tab)
{
	free(tab[0]);
	free(tab[2]);
	free(tab);
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
