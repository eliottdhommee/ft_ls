/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:44:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/25 14:59:11 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <dirent.h>
# include <sys/stat.h>
typedef struct	s_file
{
	struct stat	file_stat;
	char		*name;
	char		*path;
	t_btree		**root_files;
	t_btree		**root_dir;
}				t_file;

int				cmpf(void *data, void *data2);
char			*init_flags(char *str);
char			*get_flags_ls(char **argv);
void			error(void);
void			get_args(t_btree **files, t_btree **dir, char **argv);
t_file			*get_dir(t_file **file, int R);
t_file			*get_stat(char *pathfile);
void			print_files(t_btree **root);
#endif
