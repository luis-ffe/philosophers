/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:18:47 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 03:20:42 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
postion assignement, each value of the stack will get a position
value assigned from top to bottom to help calculate costs
*/

void	ft_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->cur_pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*
returns the position of a node in the stack with
the the minimal / lowest index
*/

int	ft_min_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		min_index;
	int		min_pos;

	tmp = *stack;
	min_index = INT_MAX;
	ft_pos(stack);
	min_pos = tmp->cur_pos;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->cur_pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

/*
gets the best position in stack A for the index of the element in B
only if element is possible 
to be inserted betwen 2 elements of stack A
else it will target the smallest indexed element in stack A
*/

int	ft_find_target(t_stack **a, int b_idx, int targ_index, int targ_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < targ_index)
		{
			targ_index = tmp_a->index;
			targ_pos = tmp_a->cur_pos;
		}
		tmp_a = tmp_a->next;
	}
	if (targ_index != INT_MAX)
		return (targ_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < targ_index)
		{
			targ_index = tmp_a->index;
			targ_pos = tmp_a->cur_pos;
		}
		tmp_a = tmp_a->next;
	}
	return (targ_pos);
}

/*
this function assigns a target position forr each of A elements
that target is what the elements in b need to go to.
used to calculate cost
*/

void	ft_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target;

	tmp_b = *b;
	ft_pos(a);
	ft_pos(b);
	target = 0;
	while (tmp_b)
	{
		target = ft_find_target(a, tmp_b->index, INT_MAX, target);
		tmp_b->targ_pos = target;
		tmp_b = tmp_b->next;
	}
}
