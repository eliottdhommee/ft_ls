/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:18:39 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/19 11:42:19 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		rb_left_rotate(t_btree *node)
{
	t_btree		*tmp;

	tmp = node->left;
	node->left = tmp->right;
	tmp->right->parent = node;
	tmp->right = node;
	node->parent = tmp;
}

void		rb_right_rotate(t_btree *node)
{
	t_btree		*tmp;

	tmp = node->right;
	node->right = tmp->left;
	tmp->left->parent = node;
	tmp->left = node;
	node->parent = tmp;
}
