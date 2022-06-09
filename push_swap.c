/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:53:55 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:54:01 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initdata(t_data *data)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->sizea = 0;
	data->sizeb = 0;
	data->moves = NULL;
	data->movenum = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	initdata(&data);
	if (!loadargs(&data, argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!checksort(&data))
	{
		if (data.sizea < 7)
			recursionbubblesort(&data, 1, -1, (data.sizea * data.sizea) / 3);
		else
			groupsort(&data);
	}
	printmoves(data.moves);
	cleandata(&data);
	return (0);
}
