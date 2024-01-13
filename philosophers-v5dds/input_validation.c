/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:25:21 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/09 07:26:09 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_extra_errors(t_philo philo)
{
	if (philo.data->die_time == 0)
		return (1);
	return (0);
}

static int	check_arg_content(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_validate_args(int argc, char **argv)
{
	static int	i;

	if (argc < 5 || argc > 6)
	{
		print_error();
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (check_arg_content(argv[i]) == 0)
		{
			print_error();
			return (0);
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	j;

	i = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j *= 10;
		j += str[i++] - '0';
	}
	return ((int)j);
}

void	print_error(void)
{
	printf("\nINPUT ERROR\n");
	printf("use as: ./philo <number_of_philos> <time_to_die> <time_to_eat>");
	printf(" <time_to_sleep> [number_of_meals]\n");
}
