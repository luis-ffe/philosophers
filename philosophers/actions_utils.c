/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:55:33 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/15 20:03:16 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_lastmeal_time(t_philo *philo)
{
	philo->lastmeal = update_current_time(philo);
}

int	philosopher_grabs_forks(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->l_fork);
		return (1);
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		return (1);
	}
	return (0);
}

void	philosopher_drops_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}

void	ft_print_status(t_philo *philo, int status)
{
	long long	time;

	time = update_current_time(philo);
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == true)
	{
		if (status == 1)
			printf("%lld %d has taken a fork\n", time, philo->id);
		if (status == 2)
			printf("%lld %d is eating\n", time, philo->id);
		if (status == 3)
			printf("%lld %d is sleeping\n", time, philo->id);
		if (status == 4)
			printf("%lld %d died\n", time, philo->id);
		if (status == 5)
			printf("%lld %d is thinking\n", time, philo->id);
	}
	return ;
}
