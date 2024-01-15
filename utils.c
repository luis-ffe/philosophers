/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:02 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/15 17:19:22 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	update_current_time(t_philo *philo)
{
	long long ret;

	pthread_mutex_lock(&philo->data->access);
	philo->data->current_time = (my_gettimeofday() - philo->data->start_time);
	ret = philo->data->current_time;
	pthread_mutex_unlock(&philo->data->access);
	return (ret);
}

long long	my_gettimeofday(void)
{
	struct timeval	t_time;
	long long		time_long;

	gettimeofday(&t_time, NULL);
	time_long = (t_time.tv_sec * 1000 + t_time.tv_usec / 1000);
	return (time_long);
}

bool	get_mutex_bool(pthread_mutex_t *mutex, bool *info)
{
	bool	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}

bool	is_he_alive(t_philo *philo)
{
	long long time_since_last_meal;

	time_since_last_meal = update_current_time(philo) - philo->lastmeal;
	if (time_since_last_meal < (long long)philo->data->die_time)
		return true;
	else
		kill_philosopher_and_stop_running(philo);
	return false;
}

int philosopher_is_on_time(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	if (is_he_alive(philo) == false)
		return (0);
	return (1);
}