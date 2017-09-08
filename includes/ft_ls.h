/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:44:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/08 15:36:22 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
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
	char			*pass;
	char			*grp;
	char			type;
}					t_file;

void				*ret_cmpf(char *flags);
int					cmpstr(void *data, void *data2);
void				delete_tab(char **tab);
void				error(void);
int					get_dir(t_file *file, char *flags);
t_file				*get_stat(t_file *dir, char *pathfile, char *flags);
int					print_main(t_btree *root, char *flags, int opt, int f);
void				print_dir(t_btree *root, char *flags);
char				*get_rights(struct stat filestat, char *path);
int					cmpt(void *data, void *data2);
int					cmptc(void *data, void *data2);
int					cmptu(void *data, void *data2);
int					cmptum(void *data, void *data2);
void				delete_file(void *file);
char				**get_long(t_file *file, char *flags);
void				reset_padding(char *str);
char				*check_padding(t_file *file, char *flags);
char				get_file_type(struct stat filestat);
void				*isnull(void *pt);
int					ft_error(int i);

#endif
