/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:28:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/17 18:34:19 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char			*create_path(char *str1, char *str2)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	if (str1 == NULL)
		return (str2);
	i = ft_strlen(str1);
	size = i + ft_strlen(str2);
	if (!(res = ft_strnew(size + 1)))
		return (NULL);
	ft_strcpy(res, (char *)str1);
	ft_strcat(res, "/");
	ft_strcat(res, str2);
	return (res);
}

static char		*check_padding(t_file *file, char *flags)
{
	if ((int)flags['2'] < ft_nbrlen(file->file_stat.st_nlink))
		flags['2'] = (char)ft_nbrlen(file->file_stat.st_nlink);
	if ((size_t)flags['3'] < ft_strlen(file->pass))
		flags['3'] = (char)ft_strlen(file->pass);
	if ((size_t)flags['4'] < ft_strlen(file->grp))
		flags['4'] = (char)ft_strlen(file->grp);
	if (S_ISBLK(file->file_stat.st_mode) || S_ISCHR(file->file_stat.st_mode))
	{
		if ((int)flags['5'] < 9)
			flags['5'] = 9;
		flags['6'] = flags['5'] - 5;
	}
	else if ((int)flags['5'] < ft_nbrlen(file->file_stat.st_size))
		flags['5'] = (char)ft_nbrlen(file->file_stat.st_size);
	return (flags);
}

t_file			*get_dir(t_file **file, char *flags)
{
	DIR				*fd;
	struct dirent	*dir;
	t_file			*tmp;

	if (!file || !(fd = opendir((*file)->path)))
		return (NULL);
	while ((dir = readdir(fd)))
	{
		if ((dir->d_name[0] != '.') || flags['a'] == 'a')
		{
			tmp = get_stat(*file, dir->d_name);
			(*file)->size += tmp->file_stat.st_blocks;
			if ((tmp->file_stat.st_mode & S_IFDIR) && flags['R'] == 'R' &&
					ft_strcmp(tmp->name, ".\0") && ft_strcmp(tmp->name, "..\0"))
				tmp = get_dir(&(tmp), flags);
			if (tmp)
				btree_insert_data(&((*file)->root_files), tmp, ret_cmpf(flags));
			flags = check_padding(tmp, flags);
		}
	}
	closedir(fd);
	return (*file);
}
