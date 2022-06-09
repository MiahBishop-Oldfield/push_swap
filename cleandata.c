/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleandata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:03 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:48:02 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanstack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!stack)
		return ;
	curr = stack;
	while (true)
	{
		next = curr->next;
		free(curr);
		if (next == stack)
			break ;
		curr = next;
	}
}

void	cleandata(t_data *data)
{
	cleanstack(data->stacka);
	cleanstack(data->stackb);
	cleanstack(data->moves);
}
