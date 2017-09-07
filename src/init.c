/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:19:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 21:57:55 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		*isnull(void *pt)
{
	if (!pt)
	{
		perror("ls");
		exit(1);
	}
	return (pt);
}

int			ft_error(int i)
{
	perror("ls");
	return (i);
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
	t_file		*tmp;

	if (file)
	{
		tmp = file;
		ft_strdel(&tmp->pass);
		ft_strdel(&tmp->path);
		ft_strdel(&tmp->grp);
		ft_memdel(&file);
	}
}
