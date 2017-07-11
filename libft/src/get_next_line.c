/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:14:07 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:13:56 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static t_gnl		*new_element(int fd)
{
	struct s_gnl	*new_element;

	new_element = malloc(sizeof(*new_element));
	if (!new_element)
		return (NULL);
	new_element->fd = fd;
	new_element->str = NULL;
	new_element->next = NULL;
	return (new_element);
}

static t_gnl		*check_fd(int fd, t_gnl *begin_list)
{
	t_gnl			*tmp;

	tmp = begin_list;
	if (tmp == NULL)
		tmp = new_element(fd);
	while (tmp->next != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp->fd != fd)
	{
		tmp->next = new_element(fd);
		tmp = tmp->next;
	}
	return (tmp);
}

static int			gnl(char *str, char **line)
{
	char	*eol;

	eol = ft_strchr(str, '\n');
	if (eol)
	{
		eol[0] = '\0';
		*line = ft_strdup(str);
		str = ft_strncpy(str, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

static char			*norme(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*begin_list = NULL;
	t_gnl			*this_fd;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (!begin_list)
		begin_list = new_element(fd);
	this_fd = check_fd(fd, begin_list);
	if (fd < 0 || !this_fd || !line || BUFF_SIZE <= 0)
		return (-1);
	if (this_fd->str == NULL)
		this_fd->str = ft_strnew(0);
	while (!ft_strchr(this_fd->str, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (gnl(this_fd->str, line));
		buf[ret] = '\0';
		this_fd->str = norme(this_fd->str, buf);
	}
	return (gnl(this_fd->str, line));
}
