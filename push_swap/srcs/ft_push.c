/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:44:59 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 03:11:53 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
pushes element from stack source to dest
used in all the pushers
*/

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/*
pushes stack top element of A to B and prints the code
*/

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

/*
pushes stack top element of B to A and prints the code
*/

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

/*
pushes all elements to stack b but 3
first the smallest values then the bigger this improves efficiency
*/

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	count;
	int	i;

	size = ft_size(*stack_a);
	count = 0;
	i = 0;
	while (size > 6 && i < size && count < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			count++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (size - count > 3)
	{
		ft_pb(stack_a, stack_b);
		count++;
	}
}
