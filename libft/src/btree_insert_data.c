/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:42:33 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/13 15:39:30 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void*, void*))
{
	if (!*root)
		*root = btree_create_node(item);
	if ((*cmpf)(item, (*root)->item) > 0)
		btree_insert_data(&(*root)->left, item, (*cmpf));
	else
		btree_insert_data(&(*root)->right, item, (*cmpf));
}
