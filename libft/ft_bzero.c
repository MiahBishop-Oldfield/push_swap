/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:56:20 by mbishop-          #+#    #+#             */
/*   Updated: 2021/09/08 11:56:26 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)

{
	ft_memset(s, 0, n);
}

/* A non-standard and portable C function that writes n zeroed bytes 
** to the string s. If n is zero, bzero() does nothing. Standard C 
** function is memset, which can be any unsigned int */