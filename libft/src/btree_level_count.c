/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 11:40:02 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/15 13:24:08 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int			btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return(ft_max(btree_level_count(root->left),
			btree_level_count(root->right)) + 1);
}
