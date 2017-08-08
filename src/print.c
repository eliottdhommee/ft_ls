/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:57:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/08 11:37:14 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <ft_ls.h>

void		print_dir(t_btree *root, char *flags)
{
	if (root)
	{
		if (flags['r'] == 'r')
			print_dir(root->right, flags);
		else
			print_dir(root->left, flags);
		ft_printf("\n%s", ((t_file*)root->item)->name);
		if (flags['r'] == 'r')
			print_dir(root->left, flags);
		else
			print_dir(root->right, flags);
	}
}

void		print_files(t_btree *root, char *flags)
{
	if (root)
	{
		if (flags['r'])
			print_files(root->right, flags);
		else
			print_files(root->left, flags);
		if (((t_file*)root->item)->file_stat.st_mode & S_IFDIR && flags['R'] == 'R')
		{
			ft_printf("\n%s:", ((t_file*)root->item)->path);
			print_dir(((t_file*)root->item)->root_files, flags);
			ft_printf("\n");
		}
		if (((t_file*)root->item)->root_files != NULL)
			print_files(((t_file*)root->item)->root_files, flags);
		if(flags['r'])
			print_files(root->left, flags);
		else
			print_files(root->right, flags);
	}
}

