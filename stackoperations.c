/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackoperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:56:25 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:56:28 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_data *data, bool a, bool b)
{
	if ((!a && !b) || (a && data->sizea < 2) || (b && data->sizeb < 2))
		return (false);
	if (a)
		data->stacka = swapstack(data->stacka);
	if (b)
		data->stackb = swapstack(data->stackb);
	return (true);
}

bool	push(t_data *data, bool atob)
{
	t_stack	*temp;

	if ((atob && data->sizea == 0) || (!atob && data->sizeb == 0))
		return (false);
	if (atob)
	{
		temp = data->stacka;
		data->stacka = removenode(data->stacka);
		data->stackb = addnode(data->stackb, temp)->prev;
		data->sizea--;
		data->sizeb++;
	}
	else
	{
		temp = data->stackb;
		data->stackb = removenode(data->stackb);
		data->stacka = addnode(data->stacka, temp)->prev;
		data->sizeb--;
		data->sizea++;
	}
	return (true);
}

bool	rotate(t_data *data, bool a, bool b, bool rev)
{
	if ((!a && !b) || (a && data->sizea < 2) || (b && data->sizeb < 2))
		return (false);
	if (a)
		data->stacka = rotatestack(data->stacka, rev);
	if (b)
		data->stackb = rotatestack(data->stackb, rev);
	return (true);
}
