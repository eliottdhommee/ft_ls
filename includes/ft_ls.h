/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:44:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/17 17:45:43 by edhommee         ###   ########.fr       */
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
	char			*pass;
	char			*grp;
	int				size;
}					t_file;

void				*ret_cmpf(char *flags);
char				*init_flags(char **str);
void				error(void);
t_file				*get_dir(t_file **file, char *flags);
t_file				*get_stat(t_file *dir, char *pathfile);
int					print_main(t_btree *root, char *flags, int opt, int first);
void				print_dir(t_btree *root, char *flags);
char				get_file_type(struct stat filestat);
char				*get_rights(struct stat filestat);
int					get_time(struct stat file_stat, char *flags);
char				*create_path(char *str1, char *str2);
int					cmpt(void *data, void *data2);
int					cmptc(void *data, void *data2);
int					cmptu(void *data, void *data2);
int					cmptum(void *data, void *data2);

#endif
