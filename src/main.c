/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/15 17:20:28 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		*get_flags_ls(char **argv, char *flags)
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
			/*
			**else
			**    error();
			*/
		}
	}
	return (flags);
}

static void		get_args(t_btree **fil, t_btree **dir, char **tab, char *flags)
{
	t_file	*tmp;
	int		i;

	i = 1;
	while (tab[i] && tab[i][0] == '-' && (i == 1 || tab[i - 1][1] != '-'))
	{
		i++;
	}
	while (tab[i])
	{
		tmp = get_stat(NULL, tab[i]);
		if (tmp)
		{
			if (S_ISDIR(tmp->file_stat.st_mode))
			{
				tmp = get_dir(&tmp, flags);
				btree_insert_data(dir, tmp, &cmpf);
			}
			else
				btree_insert_data(fil, tmp, &cmpf);
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	char		*flags;
	t_btree		*files;
	t_btree		*dir;
	t_file		*tmp;

	tmp = NULL;
	flags = NULL;
	flags = init_flags(flags);
	dir = NULL;
	if (argc > 1)
		flags = get_flags_ls(argv, flags);
	get_args(&files, &dir, argv, flags);
	if (dir == NULL && files == NULL)
	{
		tmp = get_stat(NULL, ft_strdup(".\0"));
		tmp = get_dir(&tmp, flags);
		btree_insert_data(&dir, tmp, &cmpf);
	}
	print_dir(files, flags);
	print_main(dir, flags, 1);
	return (0);
}
