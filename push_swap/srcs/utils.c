/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:03:11 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 03:26:25 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
	{
		return (1);
	}
	return (0);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_size(t_stack	*stack)
{
	int	n;

	n = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}
