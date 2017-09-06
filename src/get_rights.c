/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:48:12 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/06 17:36:30 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char			get_file_type(struct stat filestat)
{
	if (S_ISBLK(filestat.st_mode))
		return ('b');
	else if (S_ISCHR(filestat.st_mode))
		return ('c');
	else if (S_ISDIR(filestat.st_mode))
		return ('d');
	else if (S_ISLNK(filestat.st_mode))
		return ('l');
	else if (S_ISFIFO(filestat.st_mode))
		return ('p');
	else if (S_ISREG(filestat.st_mode))
		return ('-');
	else if (S_ISSOCK(filestat.st_mode))
		return ('s');
	else
		return ('w');
}

static char		get_exec_permissions(int a, int b, int c)
{
	if (!c)
	{
		if (!a && b)
			return ('S');
		else if (a && b)
			return ('s');
		else if (a)
			return ('x');
		else
			return ('-');
	}
	else
	{
		if (!a && b)
			return ('T');
		else if (a && b)
			return ('t');
		else if (a)
			return ('x');
		else
			return ('-');
	}
}

static int		is_acl(char *path)
{
	acl_t		get;
	int			i;

	i = 0;
	get = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (get != (acl_t)NULL)
		i = 1;
	acl_free(get);
	return (i);
}

static int		is_ext_attr(char *path)
{
	char		*liste;

	liste = NULL;
	if (listxattr(path, liste, 0, 0) > 0)
		return (1);
	return (0);
}

char			*get_rights(struct stat filestat, char *path)
{
	char	*rights;

	rights = isnull(ft_strnew(11));
	rights[0] = get_file_type(filestat);
	rights[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = get_exec_permissions(filestat.st_mode & S_IXUSR,
			filestat.st_mode & S_ISUID, 0);
	rights[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = get_exec_permissions(filestat.st_mode & S_IXGRP,
			filestat.st_mode & S_ISGID, 0);
	rights[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = get_exec_permissions(filestat.st_mode & S_IXOTH,
			filestat.st_mode & S_ISVTX, 1);
	if (is_acl(path))
		rights[10] = '+';
	if (is_ext_attr(path))
		rights[10] = '@';
	if (rights[10] == '\0')
		rights[10] = ' ';
	return (rights);
}
