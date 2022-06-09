/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:43:55 by mbishop-          #+#    #+#             */
/*   Updated: 2021/11/05 16:31:28 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (str == NULL)
		return (NULL);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		dest[i] = f(i, str [i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Applies the function 'f' to each character of the string 's'
** to create a new sting (with malloc(3)) resulting from
** successive applications of 'f'. */
