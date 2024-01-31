/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:54:12 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/07 16:42:05 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*b_last;

	last = ft_stack_last(*stack);
	b_last = ft_stack_bfor_last(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	b_last->next = NULL;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_printf("rrr\n");
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse(stack_b);
	ft_printf("rrb\n");
}

void	ft_rev_all(t_stack **a, t_stack **b, int *c_a, int *c_b)
{
	while (*c_a < 0 && *c_b < 0)
	{
		(*c_a) += 1;
		(*c_b) += 1; 
		ft_rrr(a, b);
	}
}
