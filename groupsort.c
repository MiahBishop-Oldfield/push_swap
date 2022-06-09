/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groupsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:51:30 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:51:47 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	isgroupremaining(t_stack *stack, int group)
{
	t_stack	*curr;

	if (!stack)
		return (false);
	curr = stack;
	while (true)
	{
		if (curr->group == group)
			return (true);
		if (curr->next == stack)
			break ;
		curr = curr->next;
	}
	return (false);
}

static void	pushgroups(t_data *data)
{
	int		group;
	bool	rev;

	group = 1;
	while (data->sizea > 0)
	{
		if (data->stacka->group != group)
		{
			rev = getrev(data->stacka, 0, group, false);
			while (data->stacka->group != group)
				operation(data, 5 + (rev * 3), false);
		}
		operation(data, 4, false);
		if (!isgroupremaining(data->stacka, group))
			group++;
	}
}

static void	groupnumbers(t_stack *stack, int count, int groupsmax)
{
	int		i;
	int		group;
	t_stack	*curr;
	t_stack	*min;

	group = 1;
	i = 0;
	while (i < count)
	{
		min = NULL;
		curr = stack;
		while (true)
		{
			if (curr->group == 0 && (!min || curr->num < min->num))
				min = curr;
			if (curr->next == stack)
				break ;
			curr = curr->next;
		}
		min->group = group;
		i++;
		if (group < groupsmax && count / groupsmax * group <= i)
			group++;
	}
}

static int	maxgroupsize(int size)
{
	int	i;

	i = 20;
	if (size <= 250)
		return (i);
	while (size > 0)
	{
		size -= 500;
		i += 15;
	}
	return (i);
}

void	groupsort(t_data *data)
{
	int		groupsmax;
	int		smallest;
	bool	rev;

	groupsmax = 1;
	while (data->sizea / groupsmax > maxgroupsize(data->sizea))
		groupsmax++;
	groupnumbers(data->stacka, data->sizea, groupsmax);
	pushgroups(data);
	smallest = data->stackb->num;
	while (data->sizeb > 0)
	{
		if (data->stackb->num < smallest)
			smallest = data->stackb->num;
		setstack(data, data->stackb->num, true);
		operation(data, 3, false);
	}
	rev = getrev(data->stacka, smallest, -1, false);
	while (data->stacka->num != smallest)
		operation(data, 5 + (rev * 3), false);
}
