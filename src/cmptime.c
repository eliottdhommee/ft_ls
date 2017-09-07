/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmptime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:20:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 22:46:11 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			cmpt(void *data, void *data2)
{
	return (((t_file*)data2)->file_stat.st_mtime -
			((t_file*)data)->file_stat.st_mtime);
}

int			cmptc(void *data, void *data2)
{
	return (((t_file*)data2)->file_stat.st_ctime -
			((t_file*)data)->file_stat.st_ctime);
}

int			cmptu(void *data, void *data2)
{
	return (((t_file*)data2)->file_stat.st_atime -
			((t_file*)data)->file_stat.st_atime);
}

int			cmptum(void *data, void *data2)
{
	return (((t_file*)data2)->file_stat.st_birthtime -
			((t_file*)data)->file_stat.st_birthtime);
}
