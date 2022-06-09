/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:44:18 by mbishop-          #+#    #+#             */
/*   Updated: 2021/09/14 16:44:22 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (str == NULL || f == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		f(i, str + i);
		i++;
	}
}

/* Applies the function 'f' to each character of the string passed
** as an argument, and passing its index as first argument. 
** Each charater is passed by address to 'f' to be modified if
** necessary. */