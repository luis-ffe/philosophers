/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:02 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/09 07:38:06 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_current_time(t_philo *philo)
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

int	get_mutex_int(pthread_mutex_t *mutex, int *info)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}

bool	get_mutex_bool(pthread_mutex_t *mutex, bool *info)
{
	bool	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
}

void	unlock_forks(t_philo *philo)
{

		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->l_fork);
}