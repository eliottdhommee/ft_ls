/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:18:05 by edhommee          #+#    #+#             */
/*   Updated: 2017/05/20 17:17:18 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_itoa_intermediate(int n, char *str, int size)
{
	int		i;
	int		rec;

	rec = n;
	i = 0;
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	if (rec < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	ft_reverse(str, size);
}

char			*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (tmp <= 0)
	{
		tmp = -tmp;
		i++;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_itoa_intermediate(n, str, i);
	return (str);
}
