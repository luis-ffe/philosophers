/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:53:54 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/15 20:16:24 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philosopher_and_stop_running(t_philo *philo)
{
	ft_print_status(philo, 4);
	pthread_mutex_lock(&philo->data->access);
	philo->data->running = false;
	pthread_mutex_unlock(&philo->data->access);
}

int	philosopher_is_allowed_to(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	return (1);
}

void	philosopher_is_eating(t_philo *philo)
{
	if (philosopher_is_allowed_to(philo))
	{
		philo->meals_count++;
		ft_print_status(philo, 2);
		update_lastmeal_time(philo);
		usleep(philo->data->eat_time * 1000);
	}
}

bool	philosopher_try_to_eat(t_philo *philo)
{
	if (philosopher_is_allowed_to(philo))
	{
		if (philosopher_grabs_forks(philo))
		{
			ft_print_status(philo, 1);
			ft_print_status(philo, 1);
			philosopher_is_eating(philo);
			philosopher_drops_forks(philo);
			is_he_alive(philo);
			return (true);
		}
	}
	return (false);
}

void	philosopher_goes_to_sleep(t_philo *philo)
{
	long long	time_since_last_meal;
	long long	time_left;

	time_since_last_meal = update_current_time(philo) - philo->lastmeal;
	time_left = philo->data->die_time - time_since_last_meal;
	if (philosopher_is_allowed_to(philo) == false)
		return ;
	ft_print_status(philo, 3);
	if (time_left <= 0)
	{
		kill_philosopher_and_stop_running(philo);
		return ;
	}
	if (time_left < philo->data->sleep_time)
	{
		usleep(time_left * 1000);
		kill_philosopher_and_stop_running(philo);
		return ;
	}
	else
		usleep(philo->data->sleep_time * 1000);
	return ;
}
