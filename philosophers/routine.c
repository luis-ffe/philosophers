/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:14:11 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/15 19:58:43 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_is_thinking(t_philo *philo)
{
	if (philosopher_is_allowed_to(philo))
	{
		ft_print_status(philo, 5);
		if (philo->data->eat_time * 2 > philo->data->die_time)
		{
			usleep((philo->data->die_time 
					- (update_current_time(philo) - philo->lastmeal)) * 1000);
			kill_philosopher_and_stop_running(philo);
		}
		usleep(100);
	}
	return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
	{
		if (philosopher_try_to_eat(philo) == true)
			philosopher_goes_to_sleep(philo);
		philosopher_is_thinking(philo);
	}
	usleep(500);
	while (philosopher_is_allowed_to(philo) != 0)
	{
		if (philosopher_try_to_eat(philo) == true)
			philosopher_goes_to_sleep(philo);
		philosopher_is_thinking(philo);
	}
	return (NULL);
}

void	thread_runner(t_philo *philos)
{
	int	i;

	if (philos->data->phil_nbr == 1)
	{
		ft_print_status(philos, 1);
		usleep(philos->data->die_time * 1000);
		ft_print_status(philos, 4);
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
