/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:11 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/13 00:20:56 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_delay(t_philo *philo)
{
	long long	time_since_last;
	long long	time_to_die;

	time_since_last = (ft_current_time(philo) - philo->lastmeal);
	if (philo->data->die_time >= (int)time_since_last)
	{
		time_to_die = (long long)philo->data->die_time - time_since_last;
		ft_print_status(philo, 3);
		if ((int)time_to_die > philo->data->sleep_time)
		{
			usleep(philo->data->sleep_time * 1000);
			return ;
		}
		else
		{
			usleep((int)time_to_die * 1000);
			set_to_dead(philo);
		}
		return ;
	}
	return ;
}

void	ft_sleeping(t_philo *philo)
{
	check_dead(philo);
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return ;
	if (philo->meals_count == philo->data->meals_nbr)
		return ;
	ft_sleep_delay(philo);
	return ;
}

int	get_forks_eat(t_philo *philo)
{
	check_dead(philo);
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	lock_forks(philo);
	ft_print_status(philo, 1);
	ft_print_status(philo, 1);
	ft_eating(philo);
	unlock_forks(philo);
	check_dead(philo);
	ft_sleeping(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		usleep(1);
	if (philo->id % 2 == 0)
		get_forks_eat(philo);
	else
		usleep(philo->data->eat_time * 1000);
	while (get_mutex_bool(&philo->data->access, &philo->data->running))
	{
		if (philo->meals_count == philo->data->meals_nbr)
			return (0);
		get_forks_eat(philo);
		go_think(philo);
	}
	return (NULL);
}

void	thread_runner(t_philo *philos)
{
	int	i;
	long long time;
	
	if (philos->data->phil_nbr == 1)
	{
		pthread_mutex_lock(&philos->data->access);
		philos->data->start_time = my_gettimeofday();
		pthread_mutex_unlock(&philos->data->access);
		time = ft_current_time(philos);
		printf("%lld ms | %d has taken a fork\n", time, philos->id);
		usleep(philos->data->die_time * 1000);
		time = ft_current_time(philos);
		printf("%lld ms | %d died\n", time, philos->id);
		return ;
	}
	i = -1;
	while (++i < philos->data->phil_nbr)
		pthread_create(&philos[i].trd, NULL, &routine, &philos[i]);
	pthread_mutex_lock(&philos->data->access);
	philos->data->start_time = my_gettimeofday();
	philos->data->running = true;
	pthread_mutex_unlock(&philos->data->access);
	i = -1;
	while (++i < philos->data->phil_nbr)
		pthread_join(philos[i].trd, NULL);
	destroy_all_mutex(philos);
}
