/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:29:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/20 17:44:38 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int				get_time(struct stat file_stat, char *flags)
{
	if (flags['c'])
		return (file_stat.st_ctime);
	else if (flags['u'])
		return (file_stat.st_atime);
	else if (flags['U'])
		return (file_stat.st_birthtime);
	else
		return (file_stat.st_mtime);
}

static char		*cut_time(const time_t file_time, char *flags)
{
	char	*str;

	str = ctime(&file_time);
	str[24] = '\0';
	if (!flags['T'])
	{
		if (file_time < time(NULL) - 15778800 || file_time > time(NULL) + 15778800)
		{
			str[11] = ' ';
			str[12] = str[20];
			str[13] = str[21];
			str[14] = str[22];
			str[15] = str[23];
		}
		str[16] = '\0';
	}
	str = &str[4];
	return (str);
}

static char		*get_link(t_file *file)
{
	char	*link;
	char	*tmp;
	int		r;

	tmp = NULL;
	if (S_ISLNK(file->file_stat.st_mode))
	{
		r = (file->file_stat.st_size < 32) ? 32 : file->file_stat.st_size;
		link = ft_strnew(r);
		r = readlink(file->path, link, r + 1);
		if (r > 0 && link)
		{
			link[r] = '\0';
			tmp = link;
			link = ft_strjoin(" -> ", tmp);
			ft_strdel(&tmp);
		}
	}
	else
		link = ft_strdup("");
	return (link);
}

char		**get_long(t_file *file, char *flags)
{
	char	**res;

	res = (char**)ft_memalloc(sizeof(char*) * 3);
	res[0] = get_link(file);
	res[1] = cut_time(get_time(file->file_stat, flags), flags);
	res[2] = get_rights(file->file_stat, file->path);
	return (res);
}
