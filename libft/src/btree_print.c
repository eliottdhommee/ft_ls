/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:45:36 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/19 11:48:19 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		btree_print(t_btree *root, char *type, int level)
{
	int		cpt;

	if (root)
	{
		cpt = 0;
		while (cpt < level)
		{
			ft_putstr("    ");
			++cpt;
		}
		ft_putstr("[");
		ft_putstr(type);
		ft_putstr(" ");
		ft_putstr((char *)root->item);
		ft_putstr("]\n");
		btree_print(root->left, "LEFT", level + 1);
		btree_print(root->right, "RIGHT", level + 1);
	}
}
