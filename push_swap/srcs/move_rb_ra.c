/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rb_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:56:32 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 03:30:51 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rot_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra(a);
			(*cost) -= 1;
		}
		else if (*cost < 0)
		{
			ft_rra(a);
			(*cost) += 1;
		}
	}
}

void	ft_rot_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb(b);
			(*cost) -= 1;
		}
		else if (*cost < 0)
		{
			ft_rrb(b);
			(*cost) += 1;
		}
	}
}

/*
choses what movements to do acording to the costs
*/

void	ft_make_movement(t_stack **a, t_stack **b, int c_a, int c_b)
{
	if (c_a < 0 && c_b < 0)
		ft_rev_all(a, b, &c_a, &c_b);
	else if (c_a > 0 && c_b > 0)
		ft_rot_all(a, b, &c_a, &c_b);
	ft_rot_a(a, &c_a);
	ft_rot_b(b, &c_b);
	ft_pa(a, b);
}

/*
utilitary to get the numbers to positiv value if negative for further use
*/

static int	ft_nbrup(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

/*
choses what movements to do acording to the costs
*/

void	ft_cheapest_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheap;
	int		a_cost;
	int		b_cost;

	tmp = *stack_b;
	cheap = INT_MAX;
	while (tmp)
	{
		if (ft_nbrup(tmp->a_cost) + ft_nbrup(tmp->b_cost) < ft_nbrup(cheap))
		{
			cheap = ft_nbrup(tmp->b_cost) + ft_nbrup(tmp->a_cost);
			a_cost = tmp->a_cost;
			b_cost = tmp->b_cost;
		}
		tmp = tmp->next;
	}
	ft_make_movement(stack_a, stack_b, a_cost, b_cost);
}
