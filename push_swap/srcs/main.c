/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:40:50 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 03:24:21 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
custom free function to clean the stacks properly
*/

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/*
custom clean and exit function with message for when erros happen
*/

void	ft_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_free(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_free(stack_b);
	ft_printf("Exit,\nError Detected.\n");
	exit (EXIT_SUCCESS);
}

/*
checks if the stack is sorted returning 0 if not and 1 if it is sorted. 
*/

int	ft_sort_status(t_stack *s)
{
	while (s->next != NULL)
	{
		if (s->nbr > s->next->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

/*
Main, has al the functions implemented to properly run the program
some improvements can be made regarding function names turning the code more
readable and also more modular. To do next. 
*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		n;

	if (argc < 2)
		return (0);
	if (!argv || ft_valid_input(argv) == 0)
		ft_exit(0, 0);
	b = NULL;
	a = ft_stack_fill(argc, argv);
	n = ft_size(a) + 1;
	ft_indexator(a, n);
	if (n - 1 == 2 && !ft_sort_status(a))
		ft_sa(&a);
	else if (n - 1 <= 3)
		ft_sort_small(&a);
	else if (n - 1 > 3 && !ft_sort_status(a))
		ft_long_sort(&a, &b);
	ft_free(&a);
	ft_free(&b);
	return (0);
}
