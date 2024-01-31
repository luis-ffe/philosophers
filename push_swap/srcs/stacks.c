/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:17:23 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/07 16:35:48 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

t_stack	*ft_stack_last(t_stack *s)
{
	while (s && s->next != NULL)
		s = s->next;
	return (s);
}

t_stack	*ft_stack_bfor_last(t_stack *s)
{
	while (s && s->next && s->next->next != NULL)
		s = s->next;
	return (s);
}

t_stack	*ft_stack_make(int nbr)
{
	t_stack	*make;

	make = malloc(sizeof(t_stack));
	if (!make)
		return (NULL);
	make->nbr = nbr;
	make->index = 0;
	make->cur_pos = -1;
	make->targ_pos = -1;
	make->a_cost = -1;
	make->b_cost = -1;
	make->next = NULL;
	return (make);
}

void	ft_stack_append(t_stack **stack, t_stack *add)
{
	t_stack	*end;

	if (!add)
		return ;
	if (!*stack)
	{
		*stack = add;
		return ;
	}
	end = ft_stack_last(*stack);
	end->next = add;
}
