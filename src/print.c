/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:57:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/15 20:10:27 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		print_link(t_file *file)
{
	char	*link;
	int		r;

	r = 0;
	if (!(link = malloc(file->file_stat.st_size)))
		return;
	r = readlink(file->path, link, file->file_stat.st_size + 1);
	if (r > 0)
	{
		link[file->file_stat.st_size] = '\0';
		ft_printf(" -> %s", link);
	}
}
static void		print_dir_long(t_btree *root, char *flags)
{
	if (S_ISBLK(((t_file*)root->item)->file_stat.st_mode) ||
			S_ISCHR(((t_file*)root->item)->file_stat.st_mode))
	{
		ft_printf("\n%s %*u %*s %*s %*u,%4u %s %s",
				get_rights(((t_file*)root->item)->file_stat),
				(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
				(int)flags['3'], ((t_file*)root->item)->pass,
				(int)flags['4'], ((t_file*)root->item)->grp,
				(int)flags['6'], major(((t_file*)root->item)->file_stat.st_rdev),
				minor(((t_file*)root->item)->file_stat.st_rdev),
				get_time(&((t_file*)root->item)->file_stat.st_mtime),
				((t_file*)root->item)->name);
	}
	else
		ft_printf("\n%s %*u %*s %*s %*u %s %s",
				get_rights(((t_file*)root->item)->file_stat),
				(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
				(int)flags['3'], ((t_file*)root->item)->pass,
				(int)flags['4'], ((t_file*)root->item)->grp,
				(int)flags['5'], ((t_file*)root->item)->file_stat.st_size,
				get_time(&((t_file*)root->item)->file_stat.st_mtime),
				((t_file*)root->item)->name);
	if (S_ISLNK(((t_file*)root->item)->file_stat.st_mode))
		print_link((t_file*)root->item);
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

int			print_main(t_btree *root, char *flags, int opt, int first)
{
	if (root)
	{
		if (flags['r'])
			first = print_main(root->right, flags, opt, first);
		else
			first = print_main(root->left, flags, opt, first);
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
		if (flags['r'])
			first = print_main(root->left, flags, opt, first);
		else
			first = print_main(root->right, flags, opt, first);
	}
	return (first);
}
