/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:44:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/14 18:17:16 by edhommee         ###   ########.fr       */
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
}					t_file;

int				cmpf(void *data, void *data2);
char			*init_flags(char *str);
void			error(void);
t_file			*get_dir(t_file **file, char *flags);
t_file			*get_stat(t_file *dir, char *pathfile);
void			print_main(t_btree *root, char *flags);
void			print_dir(t_btree *root, char *flags);
char			get_file_type(struct stat filestat);
char			*get_rights(struct stat filestat);
char			*get_time(const time_t *time);
char			*create_path(char *str1, char *str2);

#endif
