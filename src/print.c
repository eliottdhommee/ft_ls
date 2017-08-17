/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:57:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/17 16:59:41 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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

static void		print_dir_long(t_btree *root, char *flags)
{
	char		*rights;
	char		*link;

	link = get_link(root->item);
	rights = get_rights(((t_file*)root->item)->file_stat);
	if (S_ISBLK(((t_file*)root->item)->file_stat.st_mode) ||
			S_ISCHR(((t_file*)root->item)->file_stat.st_mode))
		ft_printf("%s  %*u %*s  %*s  %*u,%4u %s %s\n", rights,
				(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
				(int)flags['3'], ((t_file*)root->item)->pass,
				(int)flags['4'], ((t_file*)root->item)->grp,
				(int)flags['6'], major(((t_file*)root->item)->file_stat.st_rdev)
				, minor(((t_file*)root->item)->file_stat.st_rdev),
				cut_time(get_time(((t_file*)root->item)->file_stat, flags)),
				((t_file*)root->item)->name);
	else
		ft_printf("%s  %*u %*s  %*s  %*u %s %s%s\n", rights,
				(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
				(int)flags['3'], ((t_file*)root->item)->pass,
				(int)flags['4'], ((t_file*)root->item)->grp,
				(int)flags['5'], ((t_file*)root->item)->file_stat.st_size,
				cut_time(get_time(((t_file*)root->item)->file_stat, flags)),
				((t_file*)root->item)->name, link);
	ft_strdel(&rights);
	ft_strdel(&link);
}

void			print_dir(t_btree *root, char *flags)
{
	if (root)
	{
		if (flags['r'] == 'r')
			print_dir(root->right, flags);
		else
			print_dir(root->left, flags);
		if (flags['l'] == 'l')
			print_dir_long(root, flags);
		else
			ft_printf("%s\n", ((t_file*)root->item)->name);
		if (flags['r'] == 'r')
			print_dir(root->left, flags);
		else
			print_dir(root->right, flags);
	}
}

int				print_main(t_btree *root, char *flags, int opt, int first)
{
	if (!root)
		return (first);
	first = (flags['r']) ? print_main(root->right, flags, opt, first) :
		print_main(root->left, flags, opt, first);
	if (((t_file*)root->item)->file_stat.st_mode
			& S_IFDIR && (flags['R'] == 'R' || opt == 1 || opt == 2))
	{
		if (first == 0)
			ft_printf("\n");
		first = 0;
		if (opt != 2)
			ft_printf("%s:\n", ((t_file*)root->item)->path);
		if (flags['l'] == 'l' && ((t_file*)root->item)->root_files)
			ft_printf("total %d\n", ((t_file*)root->item)->size);
		print_dir(((t_file*)root->item)->root_files, flags);
	}
	if (((t_file*)root->item)->root_files)
		first = print_main(((t_file*)root->item)->root_files, flags, 0, first);
	first = (flags['r']) ? print_main(root->left, flags, opt, first) :
		print_main(root->right, flags, opt, first);
	return (first);
}
