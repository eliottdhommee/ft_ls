/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 17:37:25 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 16:17:44 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int		cmpstr(void *data, void *data2)
{
	return (ft_strcmp(((t_file*)data)->name, ((t_file*)data2)->name));
}

static int		cmpsize(void *data, void *data2)
{
	return (((t_file*)data)->file_stat.st_size -
			((t_file*)data2)->file_stat.st_size);
}

static int		cmpnosort(void *data, void *data2)
{
	if (data && data2)
		return (0);
	return (0);
}

void			*ret_cmpf(char *flags)
{
	if (flags['t'])
	{
		if (flags['c'])
			return (&cmptc);
		else if (flags['u'])
			return (&cmptu);
		else if (flags['U'])
			return (&cmptum);
		else
			return (&cmpt);
	}
	else if (flags['S'])
		return (&cmpsize);
	else if (flags['f'])
		return (&cmpnosort);
	else
		return (&cmpstr);
}
