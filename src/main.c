/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/20 17:29:44 by edhommee         ###   ########.fr       */
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
			else if (ft_strchr("nog", argv[i][j]))
				flags['l'] = 'l';
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
		tmp = get_stat(NULL, tab[i], flags);
		if (tmp)
		{
			if (S_ISDIR(tmp->file_stat.st_mode) && !flags['d'])
				btree_insert_data(dir, tmp, ret_cmpf(flags));
			else
				btree_insert_data(fil, tmp, ret_cmpf(flags));
			flags = check_padding(tmp, flags);
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

	files = NULL;
	flags = init_flags(&flags);
	if (argc > 1)
	{
		get_args(&files, &dir, argv, flags);
		print_dir(files, flags);
		btree_delete(files, &delete_file);
	}
	if (!files && !dir)
	{
		tmp = get_stat(NULL, ".\0", flags);
		btree_insert_data(&dir, tmp, ret_cmpf(flags));
	}
	print_main(dir, flags, (files || dir->left || dir->right) ? 1 : 2, 1);
	btree_delete(dir, &delete_file);
	ft_strdel(&flags);
	return (0);
}
