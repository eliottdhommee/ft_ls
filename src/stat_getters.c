/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 17:52:54 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/20 13:16:41 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		*get_uid(uid_t uid, char *flags)
{
	struct passwd	*pass;

	pass = getpwuid(uid);
	if (pass && flags['n'] != 'n')
		return (ft_strdup(pass->pw_name));
	else
		return (ft_itoa(uid));
}

static char		*get_gid(gid_t gid, char *flags)
{
	struct group	*grp;

	grp = getgrgid(gid);
	if (grp && flags['n'] != 'n')
		return (ft_strdup(grp->gr_name));
	else
		return (ft_itoa(gid));
}

static char		*create_path(char *str1, char *str2)
{
	char	*res;
	int		size;

	size = ft_strlen(str1) + ft_strlen(str2);
	res = ft_strnew(size + 1);
	ft_strcpy(res, str1);
	ft_strcat(res, "/");
	ft_strcat(res, str2);
	return (res);
}

t_file			*get_stat(t_file *dir, char *pathfile, char *flags)
{
	t_file		*file;
	char		*path_final;

	if (dir != NULL)
		path_final = create_path(dir->path, pathfile);
	else
		path_final = ft_strdup(pathfile);
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	if (flags['L'])
		stat(path_final, &file->file_stat);
	else
		lstat(path_final, &file->file_stat);
	file->path = path_final;
	file->name = ft_strdup(pathfile);
	file->pass = (flags['g'] != 'g') ? get_uid(file->file_stat.st_uid, flags)
		: ft_strdup("\0");
	file->grp = (flags['o'] != 'o') ? get_gid(file->file_stat.st_gid, flags)
		: ft_strdup("\0");
	file->root_files = NULL;
	file->size = 0;
	return (file);
}
