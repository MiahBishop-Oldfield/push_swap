/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:16:21 by mbishop-          #+#    #+#             */
/*   Updated: 2021/09/08 12:16:24 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		dest_size;
	size_t		src_size;

	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dest_size)
		return (src_size + dstsize);
	i = 0;
	while (src[i] && (dest_size + i) < (dstsize - 1))
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (dest_size + src_size);
}

/* Copies and concatenates (apends to the end) strings with the same 
** input parameters and output result as snprintf (a function that
** formats and stores a series of characters and values in the array
** buffer. The 'sn' part is used to direct the output of printf 
** function into a buffer). */

/* strlcat takes the full size of the destination buffer and guarentees 
** NUL-termination if there is room. (room for the NUL should be
** included in dstsize). It appends string src to the end of dst. 
** It wil append at most dstsize - strlen(dst) - 1 characters. 
** It will then NUL-terminate, unless dstsize is 0 or the origional dst 
** string was longer than dstsize (in practice this should not happen 
** as it means that either dstsize is incorrect or that dst is not a
** proper string). If the src and dst strings overlap, the behaviour 
** is undefined. */