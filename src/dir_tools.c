/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:28:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/25 15:51:01 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			cmpf(void *data, void *data2)
{
	return(ft_strcmp(((t_file*)data)->path, ((t_file*)data2)->path));
}

t_file		*get_stat(char *pathfile)
{
	t_file		*file;

	file = malloc(sizeof(t_file*));
	stat(pathfile, &file->file_stat);
	file->root_files = NULL;
	file->root_dir = NULL;
	file->path = pathfile;
	return (file);
}

t_file		*get_dir(t_file **file, int R)
{
	DIR				*fd;
	struct dirent	*dir;
	t_btree			*root_files;
	t_btree			*root_dir;
	t_file			*tmp;

	dir = NULL;
	fd = opendir((*file)->name);
	while ((dir = readdir(fd)))
	{
		tmp = get_stat(dir->d_name);
		if ((tmp->file_stat.st_mode & S_IFDIR) && R)
			tmp = get_dir(&(tmp), R);
		if (tmp->file_stat.st_mode & S_IFDIR)
			btree_insert_data(&(root_dir), tmp, &cmpf);
		else
			btree_insert_data(&(root_files), tmp, &cmpf);
	}
	closedir(fd);
	return (&(*tmp));
}
