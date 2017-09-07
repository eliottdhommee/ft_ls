/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:28:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 16:02:01 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char			*check_padding(t_file *file, char *flags)
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

static int		check_file(t_file *file, char *name, char *flags)
{
	t_file		*tmp;

	if ((name[0] != '.' || flags['a'] || flags['A']) && ((ft_strcmp(name, ".\0")
					&& ft_strcmp(name, "..\0")) || (!flags['A'] || flags['a'])))
	{
		tmp = get_stat(file, name, flags);
		if (tmp)
		{
			btree_insert_data(&(file->root_files), tmp, ret_cmpf(flags));
			flags = check_padding(tmp, flags);
			return (tmp->file_stat.st_blocks);
		}
	}
	return (0);
}

int				get_dir(t_file *file, char *flags)
{
	DIR				*fd;
	struct dirent	*dir;
	int				size;

	size = 0;
	if (!file)
		return (0);
	if (!(fd = opendir((file)->path)))
		return (ft_error(0));
	while ((dir = readdir(fd)))
		size += check_file(file, dir->d_name, flags);
	closedir(fd);
	return (size);
}
