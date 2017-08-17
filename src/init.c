/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:19:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/17 17:39:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char		*init_flags(char **str)
{
	*str = ft_memalloc(sizeof(char*) * 128);
	ft_bzero(*str, sizeof(char) * 127);
	return (*str);
}

void		delete_file(t_file *file)
{
	if (!file)
		return ;
	else
	{
		ft_memdel((void*)&file->name);
		ft_memdel((void*)&file->pass);
		ft_memdel((void*)&file->pass);
		ft_memdel((void*)&file->grp);
		ft_memdel((void*)&file->size);
		ft_memdel((void*)&file->root_files);
		ft_memdel((void*)&file->file_stat);
		ft_memdel((void*)&file);
	}
}
