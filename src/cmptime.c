/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmptime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:20:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/08 15:38:52 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			cmpt(void *data1, void *data2)
{
	if (((t_file*)data2)->file_stat.st_mtimespec.tv_sec !=
			((t_file*)data1)->file_stat.st_mtimespec.tv_sec)
		return (((t_file*)data2)->file_stat.st_mtimespec.tv_sec -
			((t_file*)data1)->file_stat.st_mtimespec.tv_sec);
	else if (((t_file*)data2)->file_stat.st_mtimespec.tv_nsec !=
			((t_file*)data1)->file_stat.st_mtimespec.tv_nsec)
		return (((t_file*)data2)->file_stat.st_mtimespec.tv_nsec -
			((t_file*)data1)->file_stat.st_mtimespec.tv_nsec);
	else
		return (cmpstr(data1, data2));
}

int			cmptc(void *data1, void *data2)
{
	if (((t_file*)data2)->file_stat.st_ctimespec.tv_sec !=
			((t_file*)data1)->file_stat.st_ctimespec.tv_sec)
		return (((t_file*)data2)->file_stat.st_ctimespec.tv_sec -
			((t_file*)data1)->file_stat.st_ctimespec.tv_sec);
	else if (((t_file*)data2)->file_stat.st_ctimespec.tv_nsec !=
			((t_file*)data1)->file_stat.st_ctimespec.tv_nsec)
		return (((t_file*)data2)->file_stat.st_ctimespec.tv_nsec -
			((t_file*)data1)->file_stat.st_ctimespec.tv_nsec);
	else
		return (cmpstr(data1, data2));
}

int			cmptu(void *data1, void *data2)
{
	if (((t_file*)data2)->file_stat.st_atimespec.tv_sec !=
			((t_file*)data1)->file_stat.st_atimespec.tv_sec)
		return (((t_file*)data2)->file_stat.st_atimespec.tv_sec -
			((t_file*)data1)->file_stat.st_atimespec.tv_sec);
	else if (((t_file*)data2)->file_stat.st_atimespec.tv_nsec !=
			((t_file*)data1)->file_stat.st_atimespec.tv_nsec)
		return (((t_file*)data2)->file_stat.st_atimespec.tv_nsec -
			((t_file*)data1)->file_stat.st_atimespec.tv_nsec);
	else
		return (cmpstr(data1, data2));
}

int			cmptum(void *data1, void *data2)
{
	if (((t_file*)data2)->file_stat.st_birthtimespec.tv_sec !=
			((t_file*)data1)->file_stat.st_birthtimespec.tv_sec)
		return (((t_file*)data2)->file_stat.st_birthtimespec.tv_sec -
			((t_file*)data1)->file_stat.st_birthtimespec.tv_sec);
	else if (((t_file*)data2)->file_stat.st_birthtimespec.tv_nsec !=
			((t_file*)data1)->file_stat.st_birthtimespec.tv_nsec)
		return (((t_file*)data2)->file_stat.st_birthtimespec.tv_nsec -
			((t_file*)data1)->file_stat.st_birthtimespec.tv_nsec);
	else
		return (cmpstr(data1, data2));
}
