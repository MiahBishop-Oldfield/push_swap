/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:54:26 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/08 18:54:35 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				group;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		sizea;
	int		sizeb;
	t_stack	*moves;
	int		movenum;
}	t_data;

bool	loadargs(t_data *data, int argc, char **argv);

void	recursionbubblesort(t_data *data, int rec, int lastop, int maxrec);
void	groupsort(t_data *data);

bool	chkpos(t_stack *stack, int num, bool ascending);
bool	getrev(t_stack *stack, int num, int group, bool n);
void	setstack(t_data *data, int num, bool ascend);

bool	operation(t_data *data, int op, bool noupdate);
bool	undo(t_data *data, int op);

bool	swap(t_data *data, bool a, bool b);
bool	push(t_data *data, bool atob);
bool	rotate(t_data *data, bool a, bool b, bool rev);

void	cleandata(t_data *data);
void	cleanstack(t_stack *stack);
void	printmoves(t_stack *moves);
bool	checksort(t_data *data);

t_stack	*swapstack(t_stack *stack);
t_stack	*rotatestack(t_stack *stack, bool rev);
t_stack	*addnode(t_stack *stack, t_stack *new);
t_stack	*removenode(t_stack *stack);
t_stack	*newnode(int num);

#endif
