/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:29:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/18 16:42:33 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int				get_time(struct stat file_stat, char *flags)
{
	if (flags['c'] == 'c')
		return (file_stat.st_ctime);
	else if (flags['u'] == 'u')
		return (file_stat.st_atime);
	else if (flags['U'] == 'U')
		return (file_stat.st_birthtime);
	else
		return (file_stat.st_mtime);
}

static char		*cut_time(const time_t time)
{
	int		len;
	char	*str;

	str = ctime(&time);
	len = ft_strlen(str);
	str[len - 9] = '\0';
	str = &str[4];
	return (str);
}

static char		*get_link(t_file *file)
{
	char	*link;
	char	*tmp;
	int		r;

	r = 0;
	tmp = NULL;
	if (S_ISLNK(file->file_stat.st_mode))
	{
		link = ft_strnew(file->file_stat.st_size);
		r = readlink(file->path, link, file->file_stat.st_size + 1);
		if (r > 0 && link)
		{
			link[file->file_stat.st_size] = '\0';
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
	res[1] = cut_time(get_time(file->file_stat, flags));
	res[2] = get_rights(file->file_stat);
	return (res);
}
