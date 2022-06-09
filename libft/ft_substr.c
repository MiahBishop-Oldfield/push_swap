/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:57:44 by mbishop-          #+#    #+#             */
/*   Updated: 2021/11/08 11:48:56 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{	
	char	*dest;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str) || len == 0)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[start + i] != '\0' && i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* allocates and returns a substring from the strings.
** The substring bgins at index 'start' 
** and is of maximum size 'len'. */
