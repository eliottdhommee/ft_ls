/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:57:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/08 15:57:33 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_ls.h>

static void		print_dir_long(t_btree *root)
{
	ft_printf("%s\n", get_rights(((t_file*)root->item)->file_stat));
}

void		print_dir(t_btree *root, char *flags)
{
	if (root)
	{
		if (flags['r'] == 'r')
			print_dir(root->right, flags);
		else
			print_dir(root->left, flags);
		if (flags['l'] == 'l')
			print_dir_long(root);
		else
			ft_printf("\n%s", ((t_file*)root->item)->name);
		if (flags['r'] == 'r')
			print_dir(root->left, flags);
		else
			print_dir(root->right, flags);
	}
}

void		print_main(t_btree *root, char *flags)
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
		if (((t_file*)root->item)->root_files != NULL)
			print_main(((t_file*)root->item)->root_files, flags);
		if(flags['r'])
			print_main(root->left, flags);
		else
			print_main(root->right, flags);
	}
}

