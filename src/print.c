/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:57:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/14 18:29:45 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		print_dir_long(t_btree *root, char *flags)
{
	ft_printf("%s %*u %*s %*s %*u %s %s \n",
			get_rights(((t_file*)root->item)->file_stat),
			(int)flags['2'], ((t_file*)root->item)->file_stat.st_nlink,
			(int)flags['3'], ((t_file*)root->item)->pass,
			(int)flags['4'], ((t_file*)root->item)->grp,
			(int)flags['5'], ((t_file*)root->item)->file_stat.st_size,
			get_time(&((t_file*)root->item)->file_stat.st_mtime),
			((t_file*)root->item)->name);
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
			ft_printf("\n%s", ((t_file*)root->item)->name);
		if (flags['r'] == 'r')
			print_dir(root->left, flags);
		else
			print_dir(root->right, flags);
	}
}

void			print_main(t_btree *root, char *flags)
{
	if (root)
	{
		if (flags['r'])
			print_main(root->right, flags);
		else
			print_main(root->left, flags);
		if (((t_file*)root->item)->file_stat.st_mode
				& S_IFDIR && flags['R'] == 'R')
		{
			ft_printf("\n%s:", ((t_file*)root->item)->path);
			print_dir(((t_file*)root->item)->root_files, flags);
			ft_printf("\n");
		}
		if (((t_file*)root->item)->root_files)
			print_main(((t_file*)root->item)->root_files, flags);
		if (flags['r'])
			print_main(root->left, flags);
		else
			print_main(root->right, flags);
	}
}
