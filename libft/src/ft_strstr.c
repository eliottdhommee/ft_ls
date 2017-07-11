/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:38:43 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:28:37 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	int		possition;
	int		recherche;

	possition = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[possition] != '\0')
	{
		recherche = 0;
		while (little[recherche] == big[possition + recherche])
		{
			if (little[recherche + 1] == '\0')
			{
				return ((char *)big + possition);
			}
			recherche++;
		}
		possition++;
	}
	return (NULL);
}
