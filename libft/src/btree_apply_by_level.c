/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 13:14:46 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/16 18:35:37 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		btree_apply_one_level(t_btree *root, int current_level,
						int wanted_level, int is_first_elem, void (*applyf)
						(void *item, int current_level, int is_first_elem))
{
	if (current_level == wanted_level)
	{
		applyf(root->item, current_level, is_first_elem);
		return;
	}
	if (root->left)
		btree_apply_one_level(root->left, current_level + 1, wanted_level,
				is_first_elem, applyf);
	if (root->right)
		btree_apply_one_level(root->right, current_level + 1, wanted_level,
				0, applyf);
}

void			btree_apply_by_level(t_btree *root, void (*applyf)
					(void *item, int current_level, int is_first_elem))
{
	int		i;

	i = 0;
	while (i <= btree_level_count(root))
	{
		btree_apply_one_level(root, 0, i, 1, applyf);
		i++;
	}
}
