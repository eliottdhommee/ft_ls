/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/18 16:25:33 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int		get_flags_ls(char **argv, char *flags)
{
	int			i;
	int			j;

	i = 0;
	while (argv[++i] && argv[i][0] == '-' && flags['-'] != '-')
	{
		j = 0;
		while (argv[i][++j])
		{
			if (ft_strchr(OPTIONS, argv[i][j]))
				flags[(int)argv[i][j]] = argv[i][j];
			else if (j == 1 && argv[i][j] == '-')
				flags[(int)argv[i][j]] = argv[i][j];
			if (argv[i][j] == 'f')
				flags['a'] = 'a';
			else if (argv[i][j] == 'c')
				flags['u'] = 0;
			else if (argv[i][j] == 'u')
				flags['c'] = 0;
		}
	}
	return (i);
}

static void		get_args(t_btree **fil, t_btree **dir, char **tab, char *flags)
{
	t_file	*tmp;
	int		i;

	i = get_flags_ls(tab, flags);
	while (tab[i])
	{
		ft_printf(tab[i]);
		tmp = get_stat(NULL, tab[i]);
		if (tmp)
		{
			if (S_ISDIR(tmp->file_stat.st_mode))
				btree_insert_data(dir, tmp, ret_cmpf(flags));
			else
				btree_insert_data(fil, tmp, ret_cmpf(flags));
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	char		*flags;
	t_btree		*files;
	t_btree		*dir;
	t_file		*tmp;

	flags = init_flags(&flags);
	get_args(&files, &dir, argv, flags);
	if (!argc || (dir == NULL && files == NULL))
	{
		tmp = get_stat(NULL, ".\0");
		btree_insert_data(&dir, tmp, ret_cmpf(flags));
	}
	print_dir(files, flags);
	print_main(dir, flags, (files || dir->left || dir->right) ? 1 : 2, 1);
	btree_delete(files, &delete_file);
	btree_delete(dir, &delete_file);
	ft_strdel(&flags);
	while (1);
	return (0);
}
