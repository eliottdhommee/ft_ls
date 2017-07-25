/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/25 15:51:56 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_ls.h>

void		print_files(t_btree **root)
{
	if (root)
	{
		print_files(&(*root)->left);
		ft_printf(((t_file*)(*root)->item)->path);
		if (((t_file*)(*root)->item)->root_files)
			print_files(((t_file*)(*root)->item)->root_files);
		if (((t_file*)(*root)->item)->root_dir)
			print_files(((t_file*)(*root)->item)->root_dir);
		print_files(&(*root)->right);
	}
}

char		*get_flags_ls(char **argv)
{
	int			i;
	int			j;
	char		*flags;

	flags = NULL;
	flags = init_flags(flags);
	i = 1;
	while (*argv[i] && argv[i][0] == '-' && flags['-'] != '-')
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

void			get_args(t_btree **files, t_btree **dir, char **argv)
{
	t_file	*tmp;
	int		i;

	i = 1;
	while (*argv[i] && argv[i][0] == '-' && (i == 1 || argv[i - 1][1] != '-'))
	{
		i++;
	}
	while (*argv[i])
	{
		tmp = get_stat(argv[i]);
		if (tmp)
		{
			if (tmp->file_stat.st_mode & S_IFDIR)
				btree_insert_data(&(*dir),tmp, &cmpf);
			else
				btree_insert_data(&(*files), tmp, &cmpf);
			i++;
		}
	}
}

int				main(int argc, char **argv)
{
	char		*flags;
	t_btree		*files;
	t_btree		*dir;

	flags =NULL;
	dir = NULL;
	argc = 1;
	flags = get_flags_ls(argv);
	get_args(&files, &dir, argv);
	print_files(&(files));
	print_files(&(dir));
	return (0);
}
