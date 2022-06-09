/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:55:51 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:55:58 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotatestack(t_stack *stack, bool rev)
{
	if (!stack)
		return (NULL);
	if (!rev)
		return (stack->next);
	else
		return (stack->prev);
}

t_stack	*swapstack(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return (NULL);
	if (stack->next == stack)
		return (stack);
	if (stack->next == stack->prev)
		return (stack->next);
	curr = stack->next;
	removenode(stack->next);
	stack = addnode(stack, curr);
	return (curr);
}

t_stack	*removenode(t_stack *stack)
{
	t_stack	*curr;

	if (!stack || stack->next == stack)
		return (NULL);
	curr = stack->prev;
	curr->next = stack->next;
	curr = stack->next;
	curr->prev = stack->prev;
	return (curr);
}

t_stack	*addnode(t_stack *stack, t_stack *new)
{
	if (!stack)
		stack = new;
	else
	{
		stack->prev->next = new;
		new->prev = stack->prev;
	}
	new->next = stack;
	stack->prev = new;
	return (stack);
}

t_stack	*newnode(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->group = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
