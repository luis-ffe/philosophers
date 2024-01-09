/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:11 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/09 04:56:04 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int set_to_dead(t_philo *philo)
{
	if (philo->data->running == true)
	{
		ft_current_time(philo);
		printf("%lld ms | %d died\n", philo->data->current_time, philo->id);
		philo->data->running = false;
		return (1);
	}
	return (0);
}

void ft_sleep_delay(t_philo *philo)
{
	long long time_since_last;
	long long time_to_die;
	
	time_since_last = philo->data->current_time - philo->lastmeal;
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
	if (philo->data->running == false)
		return ;
	if (philo->meals_count == philo->data->meals_nbr)
		return ;
	ft_current_time(philo);
	printf("%lld ms | %d is sleeping\n", philo->data->current_time, philo->id);
	ft_sleep_delay(philo);
	return ;
}

void ft_eat_delay(t_philo *philo)
{
	long long time_since_last;
	long long time_to_die;
	
	time_since_last = philo->data->current_time - philo->lastmeal;
	if (philo->data->die_time > (int)time_since_last)
	{
		time_to_die = (long long)philo->data->die_time - time_since_last;
		if ((int)time_to_die >= philo->data->eat_time)
		{
			usleep(philo->data->eat_time * 1000);
			return ;
		}
		usleep((int)time_to_die * 1000);
		set_to_dead(philo);
		return ;
	}
}

void ft_eating(t_philo *philo)
{
	if (philo->data->running == false)
		return ;
	if (philo->meals_count != philo->data->meals_nbr)
	{
		ft_current_time(philo);
		printf("%lld ms | %d is eating\n", philo->data->current_time, philo->id);
		ft_eat_delay(philo);
		philo->lastmeal = philo->data->current_time + philo->data->eat_time;
		philo->meals_count++;
	}
	return ;
}

int get_forks_eat(t_philo *philo)
{
	if (philo->data->running == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	ft_current_time(philo);
	if (pthread_mutex_lock(&philo->l_fork) == 0)
	{
		printf("%lld ms | %d has taken a fork\n", philo->data->current_time, philo->id);
		if (pthread_mutex_lock(philo->r_fork) == 0)
		{
			printf("%lld ms | %d has taken a fork\n", philo->data->current_time, philo->id);
			ft_eating(philo);
			pthread_mutex_unlock(&philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			ft_sleeping(philo);	
			return (1);
		}
		else
			pthread_mutex_unlock(&philo->l_fork);
	}
	return (0);
}

void ft_thinking(t_philo *philo)
{
	long long time_since_last;
	long long time_to_die;
	
	time_since_last = philo->data->current_time - philo->lastmeal;
	time_to_die = (long long)philo->data->die_time - time_since_last;
	usleep((int)time_to_die * 1000);
	set_to_dead(philo);
	return ;
}

int	go_think(t_philo *philo)
{
	if (philo->data->running == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	ft_current_time(philo);
	printf("%lld ms | %d is thinking\n", philo->data->current_time, philo->id);
	if (philo->meals_count == philo->data->meals_nbr)
		ft_thinking(philo);
	return (1);
}

void *routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->running == false)
		return (NULL);
	if (philo->id % 2 == 0)
	{
		get_forks_eat(philo);
		go_think(philo);
	}
	usleep(1);
	while (philo->data->running)
	{
		if (philo->meals_count == philo->data->meals_nbr)
			return (0);
		get_forks_eat(philo);
		go_think(philo);
	}
	return (NULL);
}

void thread_runner(t_philo *philos)
{
	int	i;
	if (philos->data->phil_nbr == 1)
	{
		printf("%lld ms | %d has taken a fork\n", philos->data->current_time, philos->id);
		usleep(philos->data->die_time * 1000);
		ft_current_time(philos);
		printf("%lld ms | %d is died\n", philos->data->current_time, philos->id);
		return ;
	}
	i = -1;
	while (++i < philos->data->phil_nbr)
		pthread_create(&philos[i].trd, NULL, &routine, &philos[i]);
	i = -1;
	while (++i < philos->data->phil_nbr)
		pthread_join(philos[i].trd, NULL);
	destroy_all_mutex(philos);
}
