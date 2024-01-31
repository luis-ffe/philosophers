/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:38:05 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 02:55:04 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_zero_check(char *av)
{
	int	i;

	i = 0;
	if (ft_is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/*
Checks the validity of the arguments returns 0 or 1
*/

int	ft_check_args(char *av)
{
	int	i;

	i = 0;
	if (ft_is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_is_digit((av[i])))
		i++;
	if (av[i] != '\0' && !ft_is_digit(av[i]))
		return (0);
	return (1);
}

/*
Checks the validity of the user input returns 0 or 1 acordingly
Zero is returned if a duplicated number is found.
*/

int	ft_valid_input(char **av)
{
	int	i;
	int	status;

	status = 0;
	i = 1;
	while (av[i])
	{
		if (!ft_check_args(av[i]))
			return (0);
		else
			status += ft_zero_check(av[i]);
		i++;
	}
	if (status > 1)
		return (0);
	if (ft_dupe_checker(av))
		return (0);
	return (1);
}

/*
1 (ONE) is returned if a duplicated argument is found.
*/

int	ft_dupe_checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if ((j != i) && (ft_atoi(av[i]) == ft_atoi(av[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
