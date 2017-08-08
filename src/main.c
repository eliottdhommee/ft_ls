/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/02 18:31:44 by edhommee         ###   ########.fr       */
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

char		*get_flags_ls(char **argv, char *flags)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && flags['-'] != '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (ft_strchr("ABCFGHLOPRSTUW@abcdefghiklmnopqrstuwx1", argv[i][j]))
				flags[(int)argv[i][j]] = argv[i][j];
			else if (j == 1 && argv[i][j] == '-')
				flags[(int)argv[i][j]] = argv[i][j];
			/*
			**else
			**    error();
			*/
			j++;
		}
		i++;
	}
	return (flags);
}

void			get_args(t_btree **files, t_btree **dir, char **argv, char *flags)
{
	t_file	*tmp;
	int		i;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && (i == 1 || argv[i - 1][1] != '-'))
	{
		i++;
	}
	if (argv[i])
	{
		while (argv[i])
		{
			tmp = get_stat(NULL, argv[i]);
			if (tmp)
			{
				if (S_ISDIR(tmp->file_stat.st_mode))
				{
					tmp = get_dir(&tmp, flags);
					btree_insert_data(dir,tmp, &cmpf);
				}
				else
					btree_insert_data(files, tmp, &cmpf);
			}
			i++;
		}
	}
}

int				main(int argc, char **argv)
{
	char		*flags;
	t_btree		*files;
	t_btree		*dir;
	int			R;
	t_file		*tmp;

	tmp = NULL;
	R = 0;
	flags =NULL;
	flags = init_flags(flags);
	dir = NULL;
	if (argc > 1)
		flags = get_flags_ls(argv, flags);
	get_args(&files, &dir, argv, flags);
	if (dir == NULL)
	{
		tmp = get_stat(NULL, ft_strdup(".\0"));
		tmp = get_dir(&tmp, flags);
		print_dir(tmp->root_files, flags);
	}
	else
	{
		print_dir(files, flags);
		print_files(dir, flags);
	}
	return (0);
}
