/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:48:42 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:48:52 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	checksort(t_data *data)
{
	t_stack	*curr;

	if (data->sizeb != 0)
		return (false);
	curr = data->stacka;
	while (curr->next != data->stacka)
	{
		if (curr->num > curr->next->num)
			return (false);
		curr = curr->next;
	}
	return (true);
}
