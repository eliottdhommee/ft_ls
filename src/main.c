/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:45:40 by edhommee          #+#    #+#             */
/*   Updated: 2017/07/20 15:48:23 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_ls.h>

int			cmpf(void *str1, void *str2)
{
	return (ft_strcmp((const char *)str1, (const char *)str2));
}

void		sisi(void *str)
{
	ft_printf((char*)str);
}
int			main(void)
{
	t_btree *root;
	char		*i;
	char		*j;
	char		*k;
	char		*l;
	char		*m;
	char		*n;
	char		*o;
	char		*p;
	char		*q;
	root = NULL;
	i = ft_strdup("1");
	j = ft_strdup("2");
	k = ft_strdup("3");
	l = ft_strdup("4");
	m = ft_strdup("5");
	n = ft_strdup("6");
	o = ft_strdup("7");
	p = ft_strdup("8");
	q = ft_strdup("9");
	rb_insert(&root, i, &cmpf);
	rb_insert(&root, j, &cmpf);
	rb_insert(&root, k, &cmpf);
	rb_insert(&root, l, &cmpf);
	rb_insert(&root, m, &cmpf);
	rb_insert(&root, n, &cmpf);
	rb_insert(&root, o, &cmpf);
	rb_insert(&root, p, &cmpf);
	rb_insert(&root, q, &cmpf);
	btree_print(root, "root", 0);
	return (0);
}
