/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/19 12:06:27 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_ls.h>

int			main(void)
{
	t_btree *root;
	char		*i;
	char		*j;
	char		*k;
	char		*l;

	i = "afd";
	j = "gerqf";
	k = "refgregk";
	l = "pjoigjerhh";
	btree_insert_data(&root, &i, ft_strcmp);
	return (0);
}
