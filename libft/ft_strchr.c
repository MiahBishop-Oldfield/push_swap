/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:15:57 by mbishop-          #+#    #+#             */
/*   Updated: 2021/09/08 12:16:01 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

/* Locates the first occurrence of 'c' (converted to
** a char) in the string pointed to by 's'.
** The terminating null character is considered to be
** part of the string, therefore if 'c' is '\0', the
** function locates the terminating '\0'. */