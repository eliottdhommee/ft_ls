/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 17:52:54 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 16:40:25 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		*get_uid(uid_t uid, char *flags)
{
	struct passwd	*pass;

	pass = getpwuid(uid);
	if (pass && !flags['n'])
		return (ft_strdup(pass->pw_name));
	else
		return (ft_itoa(uid));
}

static char		*get_gid(gid_t gid, char *flags)
{
	struct group	*grp;

	grp = getgrgid(gid);
	if (grp && !flags['n'])
		return (ft_strdup(grp->gr_name));
	else
		return (ft_itoa(gid));
}

t_file			*get_stat(t_file *dir, char *pathfile, char *flags)
{
	t_file		*file;
	char		*path_final;
	int			i;

	path_final = isnull((dir != NULL) ? ft_strcjoin(dir->path, pathfile, '/') :
		ft_strdup(pathfile));
	file = isnull(ft_memalloc(sizeof(t_file)));
	i = (!flags['L']) ? lstat(path_final, &file->file_stat) :
		stat(path_final, &file->file_stat);
	if (i != 0)
	{
		ft_strdel(&path_final);
		ft_memdel((void*)&file);
		ft_error(0);
		return (NULL);
	}
	file->path = path_final;
	file->name = isnull(ft_strdup(pathfile));
	file->pass = isnull((!flags['g']) ? get_uid(file->file_stat.st_uid, flags)
		: ft_strdup(""));
	file->grp = isnull((!flags['o']) ? get_gid(file->file_stat.st_gid, flags)
		: ft_strdup(""));
	file->type = get_file_type(file->file_stat);
	file->root_files = NULL;
	return (file);
}
