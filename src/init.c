/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:19:49 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/24 13:30:29 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>


char		*init_flags(char	*str)
{
	str = ft_memalloc(sizeof(char*) * 128);
	ft_bzero(str, sizeof(char) * 127);
	return (str);
}
