/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:02 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/09 05:44:23 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_current_time(t_philo *philo)
{
	philo->data->current_time = (my_gettimeofday() - philo->data->start_time);
}

long long my_gettimeofday(void)
{
	struct timeval t_time;
	long long time_long;

	gettimeofday(&t_time, NULL);
	time_long = (t_time.tv_sec * 1000 + t_time.tv_usec / 1000);
	return (time_long);
}

int	ft_atoi(const char *str)
{
	int	i;
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
	printf("use as: ./philo <number_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]\n");
}
