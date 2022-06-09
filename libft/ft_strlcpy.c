/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:16:49 by mbishop-          #+#    #+#             */
/*   Updated: 2021/09/08 12:16:52 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/* Copies and concatenates (apends to the end) strings with the same input 
** parameters and output result as snprintf (a function that formats and 
** stores a series of characters and values in the array buffer. 
** The 'sn' part is used to direct the output of printf function into 
**a buffer). */

/* strlcpy takes the full size of the destination buffer and guarentees 
** NUL-termination if there is room. (room for the NUL should be included 
** in dstsize). It copies up to dstsize - 1 characters from the string 
** src to dst, NUL-terminating the result if dstsie is not 0. */