/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:23:50 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/06 15:22:49 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_fill(int ac, char **av)
{
	int			i;
	long int	num;
	t_stack		*init;

	init = NULL;
	num = 0;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_exit(&init, NULL);
		if (i == 1)
			init = ft_stack_make((int)num);
		else
			ft_stack_append(&init, ft_stack_make((int)num));
		i++;
	}
	return (init);
}

void	ft_indexator(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		n;

	while (--size > 0)
	{
		n = INT_MIN;
		highest = NULL;
		ptr = stack_a;
		while (ptr)
		{
			if (ptr->nbr == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->nbr > n && ptr->index == 0)
			{
				n = ptr->nbr;
				highest = ptr;
				ptr = stack_a;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
