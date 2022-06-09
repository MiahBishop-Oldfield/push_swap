/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:52:54 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:52:58 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*getmove(int move)
{
	char	*moves[11];

	moves[0] = "sa\n";
	moves[1] = "sb\n";
	moves[2] = "ss\n";
	moves[3] = "pa\n";
	moves[4] = "pb\n";
	moves[5] = "ra\n";
	moves[6] = "rb\n";
	moves[7] = "rr\n";
	moves[8] = "rra\n";
	moves[9] = "rrb\n";
	moves[10] = "rrr\n";
	return (moves[move]);
}

void	printmoves(t_stack *moves)
{
	t_stack	*curr;
	char	*str;

	if (!moves)
		return ;
	curr = moves;
	while (true)
	{
		str = getmove(curr->num);
		write(1, str, ft_strlen(str));
		if (curr->next == moves)
			break ;
		curr = curr->next;
	}
}
