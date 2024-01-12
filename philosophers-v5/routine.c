/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:11 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/09 07:35:40 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_delay(t_philo *philo)
{
	long long	time_since_last;
	long long	time_to_die;

	time_since_last = (ft_current_time(philo) - philo->lastmeal);
	if (philo->data->die_time > (int)time_since_last)
	{
		time_to_die = (long long)philo->data->die_time - time_since_last;
		if ((int)time_to_die >= philo->data->sleep_time)
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
}

void	ft_sleeping(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return ;
	if (philo->meals_count == philo->data->meals_nbr)
		return ;
	printf("%lld ms | %d is sleeping\n", ft_current_time(philo), philo->id);
	ft_sleep_delay(philo);
	return ;
}

int	get_forks_eat(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	lock_forks(philo);
	//pthread_mutex_lock(&philo->l_fork);
	printf("%lld ms | %d has taken a fork\n",  ft_current_time(philo), philo->id);
	//pthread_mutex_lock(philo->r_fork);
	printf("%lld ms | %d has taken a fork\n", ft_current_time(philo), philo->id);
	ft_eating(philo);
	unlock_forks(philo);
	//pthread_mutex_unlock(&philo->l_fork);
	//pthread_mutex_unlock(philo->r_fork);
	ft_sleeping(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (get_mutex_bool(&philo->data->access, &philo->data->running) == false) //////////////////////////////////
	// 	return (NULL);
	// if (philo->id % 2 == 0)
	// {
	// 	get_forks_eat(philo);
	// 	go_think(philo);
	// }
	// else
	// 	usleep(philo->data->eat_time * 100);
	while (get_mutex_bool(&philo->data->access, &philo->data->running)) /////////////////////////////////
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

	if (philos->data->phil_nbr == 1)
	{
		printf("%lld ms | %d has taken a fork\n", ft_current_time(philos), philos->id);
		usleep(philos->data->die_time * 1000);
		printf("%lld ms | %d died\n", ft_current_time(philos), philos->id);
		return ;
	}
	i = -1;
	while (++i < philos->data->phil_nbr)
	{
		pthread_create(&philos[i].trd, NULL, &routine, &philos[i]);
		printf("philos id = %d + 1 = %d\n", i, philos[i].id);
	}
	i = -1;
	while (++i < philos->data->phil_nbr)
		pthread_join(philos[i].trd, NULL);
	destroy_all_mutex(philos);
}
