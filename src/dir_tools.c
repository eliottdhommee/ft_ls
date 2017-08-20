/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:28:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/20 14:32:41 by edhommee         ###   ########.fr       */
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

void			get_dir(t_file *file, char *flags)
{
	DIR				*fd;
	struct dirent	*dir;
	t_file			*tmp;

	if (!file || !(fd = opendir((file)->path)))
		return ;
	while ((dir = readdir(fd)))
	{
		tmp = NULL;
		if ((dir->d_name[0] != '.' || flags['a'] == 'a' || flags['A'] == 'A') &&
				((ft_strcmp(dir->d_name, ".\0") &&
				ft_strcmp(dir->d_name, "..\0")) ||
				 (flags['A'] != 'A'  || flags['a'])))
		{
			tmp = get_stat(file, dir->d_name, flags);
			if (tmp)
			{
				(file)->size += tmp->file_stat.st_blocks;
				btree_insert_data(&((file)->root_files), tmp, ret_cmpf(flags));
				flags = check_padding(tmp, flags);
			}
		}
	}
	closedir(fd);
}
