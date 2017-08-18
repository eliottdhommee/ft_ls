/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:44:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/18 16:37:44 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <grp.h>
# define OPTIONS "ABCFGHLOPRSTUW@abcdefghiklmnopqrstuwx1"

typedef struct		s_file
{
	struct stat		file_stat;
	char			*name;
	char			*path;
	t_btree			*root_files;
	int				size;
	char			*pass;
	char			*grp;
}					t_file;

void				*ret_cmpf(char *flags);
char				*init_flags(char **str);
void				delete_tab(char **tab);
void				error(void);
void				get_dir(t_file *file, char *flags);
t_file				*get_stat(t_file *dir, char *pathfile);
int					print_main(t_btree *root, char *flags, int opt, int f);
void				print_dir(t_btree *root, char *flags);
char				*get_rights(struct stat filestat);
int					cmpt(void *data, void *data2);
int					cmptc(void *data, void *data2);
int					cmptu(void *data, void *data2);
int					cmptum(void *data, void *data2);
void				delete_file(void *file);
char				**get_long(t_file *file, char *flags);

#endif
