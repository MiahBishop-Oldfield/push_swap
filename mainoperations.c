/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:53:19 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 19:51:53 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	updatemoves(t_data *data, int op, bool ran, bool noupdate)
{
	if (!ran)
		return (false);
	if (noupdate)
		return (ran);
	data->moves = addnode(data->moves, newnode(op));
	data->movenum++;
	return (true);
}

bool	operation(t_data *data, int op, bool noupdate)
{
	bool	ran;

	if (op == 0)
		ran = swap(data, true, false);
	else if (op == 1)
		ran = swap(data, false, true);
	else if (op == 2)
		ran = swap(data, true, true);
	else if (op == 3)
		ran = push(data, false);
	else if (op == 4)
		ran = push(data, true);
	else if (op == 5)
		ran = rotate(data, true, false, false);
	else if (op == 6)
		ran = rotate(data, false, true, false);
	else if (op == 7)
		ran = rotate(data, true, true, false);
	else if (op == 8)
		ran = rotate(data, true, false, true);
	else if (op == 9)
		ran = rotate(data, false, true, true);
	else
		ran = rotate(data, true, true, true);
	return (updatemoves(data, op, ran, noupdate));
}

bool	undo(t_data *data, int op)
{
	bool	ran;

	if (op == 0)
		ran = swap(data, true, false);
	else if (op == 1)
		ran = swap(data, false, true);
	else if (op == 2)
		ran = swap(data, true, true);
	else if (op == 3)
		ran = push(data, true);
	else if (op == 4)
		ran = push(data, false);
	else if (op == 5)
		ran = rotate(data, true, false, true);
	else if (op == 6)
		ran = rotate(data, false, true, true);
	else if (op == 7)
		ran = rotate(data, true, true, true);
	else if (op == 8)
		ran = rotate(data, true, false, false);
	else if (op == 9)
		ran = rotate(data, false, true, false);
	else
		ran = rotate(data, true, true, false);
	return (ran);
}
