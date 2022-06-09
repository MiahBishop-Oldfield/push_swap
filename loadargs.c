/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:52:15 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:52:25 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	chkdup(t_stack *stack, int num)
{
	t_stack	*curr;

	if (!stack)
		return (false);
	curr = stack;
	while (true)
	{
		if (curr->num == num)
			return (true);
		if (curr->next == stack)
			break ;
		curr = curr->next;
	}
	return (false);
}

static bool	validint(char *num, bool neg)
{
	int		len;
	char	*maxint;

	len = ft_strlen(num);
	maxint = "2147483647";
	if (neg)
		maxint = "2147483648";
	if (len > 10 || (len == 10 && ft_strncmp(num, maxint, len + 1) > 0))
		return (false);
	while (num[0] != '\0')
	{
		if (!ft_isdigit(num[0]))
			return (false);
		num++;
	}
	return (true);
}

static bool	validarg(char *arg)
{
	bool	neg;

	if (!arg || arg[0] == '\0')
		return (false);
	neg = arg[0] == '-';
	if (neg)
		arg++;
	while (arg[0] == '0')
		arg++;
	if (arg[0] != '\0' && !validint(arg, neg))
		return (false);
	return (true);
}

bool	loadargs(t_data *data, int argc, char **argv)
{
	int	num;

	if (argc == 1)
		return (false);
	while (data->sizea + 1 < argc)
	{
		num = ft_atoi(argv[data->sizea + 1]);
		if (!validarg(argv[data->sizea + 1]) || chkdup(data->stacka, num))
		{
			cleanstack(data->stacka);
			return (false);
		}
		data->stacka = addnode(data->stacka, newnode(num));
		data->sizea++;
	}
	return (true);
}
