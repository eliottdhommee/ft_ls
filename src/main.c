/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/06 18:01:50 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		ft_usage(char c)
{
	ft_printf("%s %c\nusage: ls [-%s] [file...]\n",
			"ls: illegal option --", c, OPTIONS);
	exit(1);
}

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
			if (ft_strchr(OPTIONS, argv[i][j]) || (j == 1 && argv[i][j] == '-'))
				flags[(int)argv[i][j]] = argv[i][j];
			else
				ft_usage(argv[i][j]);
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
	if (!tab[i])
	{
		tmp = get_stat(NULL, ".\0", flags);
		if (tmp)
			btree_insert_data(dir, tmp, ret_cmpf(flags));
	}
	while (tab[i])
	{
		tmp = get_stat(NULL, tab[i], flags);
		if (tmp)
		{
			if (tmp->type != 'd')
				btree_insert_data(fil, tmp, ret_cmpf(flags));
			else if (tmp->type == 'd' && !flags['d'])
				btree_insert_data(dir, tmp, ret_cmpf(flags));
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

	files = NULL;
	dir = NULL;
	flags = NULL;
	flags = isnull(ft_strnew(127));
	if (argc)
		get_args(&files, &dir, argv, flags);
	if (files)
	{
		print_dir(files, flags);
		btree_delete(files, &delete_file);
	}
	if (dir)
	{
		print_main(dir, flags, (files || dir->left || dir->right) ? 1 : 2, 1);
		btree_delete(dir, &delete_file);
	}
	ft_strdel(&flags);
	return (0);
}
