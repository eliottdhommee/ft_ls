/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:34:43 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:20:24 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list*new_element;

	new_element = malloc(sizeof(*new_element));
	if (!new_element)
		return (NULL);
	if (!content)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	else
	{
		new_element->content = malloc(content_size * sizeof(char));
		if (!content)
		{
			free(new_element);
			return (NULL);
		}
		ft_memcpy(new_element->content, content, content_size);
		new_element->content_size = content_size;
	}
	new_element->next = NULL;
	return (new_element);
}
