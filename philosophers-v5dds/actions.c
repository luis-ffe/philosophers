#include "philo.h"

int	set_to_dead(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == true)
	{

		ft_print_status(philo, 4);
        pthread_mutex_lock(&philo->data->access);
		philo->data->running = false;
        pthread_mutex_unlock(&philo->data->access);
		return (1);
	}
	return (0);
}

void	ft_thinking(t_philo *philo)
{
	long long	time_since_last;
	long long	time_to_die;

	time_since_last = (ft_current_time(philo) - philo->lastmeal);
	time_to_die = (long long)philo->data->die_time - time_since_last;
	usleep((int)time_to_die * 1000);
	set_to_dead(philo);
	return ;
}

int	go_think(t_philo *philo)
{
	//check_dead(philo);
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	ft_print_status(philo, 5);
	if (philo->meals_count == philo->data->meals_nbr)
		ft_thinking(philo);
	return (1);
}

void	ft_eat_delay(t_philo *philo)
{
	long long	time_since_last;
	long long	time_to_die;

	time_since_last = ft_current_time(philo) - philo->lastmeal;
	time_to_die = philo->data->die_time - philo->lastmeal;
	if (time_since_last + philo->data->eat_time > philo->data->die_time)
	{
		usleep(time_to_die * 1000);
		set_to_dead(philo);
	}
	else
		usleep(philo->data->eat_time * 1000);
	return ;
}

void	ft_eating(t_philo *philo)
{
	//check_dead(philo);
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return ;
	if (philo->meals_count != philo->data->meals_nbr)
	{
		ft_print_status(philo, 2);
		ft_eat_delay(philo);
		philo->lastmeal = ft_current_time(philo);
		philo->meals_count++;
	}
	return ;
}

void	check_dead(t_philo *philo)
{
	if ((ft_current_time(philo) - philo->lastmeal) >= philo->data->die_time)
		set_to_dead(philo);
	return ;
}