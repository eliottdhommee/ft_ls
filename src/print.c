/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:57:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 16:11:47 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		print_dir_long(t_btree *root, char *flags)
{
	char	**tab;

	tab = get_long((t_file*)root->item, flags);
	if (((t_file*)root->item)->type == 'b' ||
			((t_file*)root->item)->type == 'c')
		ft_printf("%s %*u %*s  %*s  %*u,%4u %s %s\n", tab[2],
				(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
				(int)flags['3'], ((t_file*)root->item)->pass,
				(int)flags['4'], ((t_file*)root->item)->grp,
				(int)flags['6'], major(((t_file*)root->item)->file_stat.st_rdev)
				, minor(((t_file*)root->item)->file_stat.st_rdev),
				tab[1],
				((t_file*)root->item)->name);
	else
		ft_printf("%s %*u %*s  %*s  %*u %s %s%c%s\n", tab[2],
				(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
				(int)flags['3'], ((t_file*)root->item)->pass,
				(int)flags['4'], ((t_file*)root->item)->grp,
				(int)flags['5'], (int)((t_file*)root->item)->file_stat.st_size,
				tab[1], ((t_file*)root->item)->name, (flags['p'] &&
					((t_file*)root->item)->type == 'd') ? '/' :
				'\0', tab[0]);
	delete_tab(tab);
}

void			print_dir(t_btree *root, char *flags)
{
	if (root)
	{
		if (!flags['r'])
			print_dir(root->right, flags);
		else
			print_dir(root->left, flags);
		if (flags['i'])
			ft_printf("%d ", (int)((t_file*)root->item)->file_stat.st_ino);
		if (flags['s'])
			ft_printf("%d ", (int)((t_file*)root->item)->file_stat.st_blocks);
		if (flags['l'])
			print_dir_long(root, flags);
		else
			ft_printf("%s%c\n", ((t_file*)root->item)->name, (flags['p'] &&
					((t_file*)root->item)->type == 'd') ? '/' : '\0');
		if (!flags['r'])
			print_dir(root->left, flags);
		else
			print_dir(root->right, flags);
	}
}

static int		print_recursion(t_btree *root, char *flags, int opt, int f)
{
	int		size;
	void	*comp;

	comp = ret_cmpf(flags);
	if (f == 0)
		ft_printf("\n");
	f = 0;
	if (opt != 2)
		ft_printf("%s:\n", ((t_file*)root->item)->path);
	size = get_dir((t_file*)(root->item), flags);
	if ((flags['l'] || flags['s']) && ((t_file*)root->item)->root_files)
		ft_printf("total %d\n", size);
	print_dir(((t_file*)root->item)->root_files, flags);
	if (flags['R'])
		f = print_main(((t_file*)root->item)->root_files, flags, 0, f);
	reset_padding(flags);
	btree_delete(((t_file*)root->item)->root_files, &delete_file);
	return (f);
}

int				print_main(t_btree *root, char *flags, int opt, int f)
{
	if (!root)
		return (f);
	f = (!flags['r']) ? print_main(root->right, flags, opt, f) :
		print_main(root->left, flags, opt, f);
	if (((t_file*)root->item)->type == 'd' && (flags['R'] || opt != 0) &&
			(ft_strcmp(".\0", ((t_file*)root->item)->name) || opt == 2)
			&& ft_strcmp("..\0", ((t_file*)root->item)->name))
	{
		f = print_recursion(root, flags, opt, f);
	}
	f = (!flags['r']) ? print_main(root->left, flags, opt, f) :
		print_main(root->right, flags, opt, f);
	return (f);
}
