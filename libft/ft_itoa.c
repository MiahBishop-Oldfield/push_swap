/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:43:24 by mbishop-          #+#    #+#             */
/*   Updated: 2021/11/12 10:23:14 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts an interger data type to a string data type. */

#include "libft.h"

size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	size_t			len;

	len = get_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = (unsigned int) -n;
	}
	else
		num = (unsigned int)n;
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
