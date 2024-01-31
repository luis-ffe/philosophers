/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:37:07 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 03:09:24 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
this function will improve the positions of the stack shifting it
used when most of the values are already sorted.
gets the lowest value at the top
*/

void	ft_stack_improve(t_stack **stack_a)
{
	int	min;
	int	size;

	size = ft_size(*stack_a);
	min = ft_min_pos(stack_a);
	if (min > size / 2)
	{
		while (min < size)
		{
			ft_rra(stack_a);
			min++;
		}
	}
	else
	{
		while (min > 0)
		{
			ft_ra(stack_a);
			min--;
		}
	}
}

/*
small sorting algorith to sort small inputs
checks if the stack is already sorted and sorts the stack
of 3 numbers or less in less or 2 moves.
*/

void	ft_sort_small(t_stack **stack)
{
	int		n;

	if (ft_sort_status(*stack))
		return ;
	n = ft_max_index(*stack);
	if ((*stack)->index == n)
	{
		ft_ra(stack);
	}
	else if ((*stack)->next->index == n)
	{
		ft_rra(stack);
	}
	if ((*stack)->index > (*stack)->next->index)
	{
		ft_sa(stack);
	}
}

/*
sort algorith for bigger user inputs
*/

void	ft_long_sort(t_stack **a, t_stack **b)
{
	ft_push_b(a, b);
	ft_sort_small(a);
	while (*b)
	{
		ft_target_pos(a, b);
		ft_get_cost(a, b);
		ft_cheapest_to_a(a, b);
	}
	if (!ft_sort_status(*a))
		ft_stack_improve(a);
}

/* get_cost:
gets the cost of moving ech stack b element into stack a
B cost is the cost to move it to the top of stack B
A cost is the cost of moving it into right stack A position
cost is negative in the bottom half of the stack and positive otherwise
*/

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_size(tmp_a);
	size_b = ft_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->b_cost = tmp_b->cur_pos;
		if (tmp_b->cur_pos > size_b / 2)
			tmp_b->b_cost = (size_b - tmp_b->cur_pos) * -1;
		tmp_b->a_cost = tmp_b->targ_pos;
		if (tmp_b->targ_pos > size_a / 2)
			tmp_b->a_cost = (size_a - tmp_b->targ_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
