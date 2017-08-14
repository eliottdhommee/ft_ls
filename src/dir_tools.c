/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:28:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/14 16:40:14 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			cmpf(void *data, void *data2)
{
	return(ft_strcmp(((t_file*)data)->name, ((t_file*)data2)->name));
}

char		*create_path(char *str1, char *str2)
{
	char	*res;
	int		size;
	int		i;

	i = ft_strlen(str1);
	size = i + ft_strlen(str2);
	if (!(res = ft_strnew(size + 1)))
		return (NULL);
	ft_strcpy(res, (char *)str1);
	if (str1[i - 1] != '/')
		ft_strcat(res, "/");
	ft_strcat(res, str2);
	return (res);
}

char		*get_uid(uid_t uid)
{
	struct passwd	*pass;

	pass = getpwuid(uid);
	if (pass)
		return (ft_strdup(pass->pw_name));
	else
		return (ft_itoa(uid));
}

char		*get_gid(gid_t gid)
{
	struct group	*grp;

	grp = getgrgid(gid);
	if (grp)
		return (ft_strdup(grp->gr_name));
	else
		return (ft_itoa(gid));
}

t_file		*get_stat(t_file *dir, char *pathfile)
{
	t_file		*file;
	t_btree		*root1;
	char		*path_final;

	root1 = NULL;
	if (dir)
		path_final = create_path(dir->path, pathfile);
	else
		path_final = ft_strcat(pathfile, "/");
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	lstat(path_final, &file->file_stat);
	file->pass = get_uid(file->file_stat.st_uid);
	file->grp = get_gid(file->file_stat.st_gid);
	file->path = ft_strdup(path_final);
	file->name = ft_strdup(pathfile);
	file->root_files = root1;
	return (file);
}

char		*check_padding(t_file *file, char *flags)
{
	if ((int)flags['2'] < ft_nbrlen(file->file_stat.st_nlink))
		flags['2'] = (char)ft_nbrlen(file->file_stat.st_nlink);
	if ((size_t)flags['3'] < ft_strlen(file->pass))
		flags['3'] = (char)ft_strlen(file->pass);
	if ((size_t)flags['4'] < ft_strlen(file->grp))
		flags['4'] = (char)ft_strlen(file->grp);
	if ((int)flags['5'] < ft_nbrlen(file->file_stat.st_size))
		flags['5'] = (char)ft_nbrlen(file->file_stat.st_size);
	return (flags);
}

t_file		*get_dir(t_file **file, char *flags)
{
	DIR				*fd;
	struct dirent	*dir;
	t_file			*tmp;

	if (!file || !(fd = opendir((*file)->path)))
		return (NULL);
	while ((dir = readdir(fd)))
	{
		tmp = get_stat(*file, dir->d_name);
		if ((dir->d_name[0] != '.') || flags['a'] == 'a')
		{
			if ((tmp->file_stat.st_mode & S_IFDIR) && flags['R'] == 'R' && 
					ft_strcmp(tmp->name, ".\0") && ft_strcmp(tmp->name, "..\0"))
				tmp = get_dir(&(tmp), flags);
			if (tmp)
				btree_insert_data(&((*file)->root_files), tmp, &cmpf);
			flags = check_padding(tmp, flags);
		}
		/*
		**else
		**    free_file();
		*/
	}
	closedir(fd);
	return (*file);
}
