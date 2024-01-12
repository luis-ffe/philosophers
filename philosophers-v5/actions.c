#include "philo.h"

int	set_to_dead(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == true)
	{

		printf("%lld ms | %d died\n", ft_current_time(philo), philo->id);
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
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return (0);
	if (philo->meals_count == philo->data->meals_nbr)
		return (0);
	printf("%lld ms | %d is thinking\n", ft_current_time(philo), philo->id); //////////////////////////////////////
	if (philo->meals_count == philo->data->meals_nbr)
		ft_thinking(philo);
	return (1);
}

void	ft_eat_delay(t_philo *philo)
{
	long long	time_since_last;
	long long	time_to_die;

	time_since_last = ft_current_time(philo) - philo->lastmeal;
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

void	ft_eating(t_philo *philo)
{
	if (get_mutex_bool(&philo->data->access, &philo->data->running) == false)
		return ;
	if (philo->meals_count != philo->data->meals_nbr)
	{
		printf("%lld ms | %d is eating\n", ft_current_time(philo), philo->id);
		ft_eat_delay(philo);
		philo->lastmeal = ft_current_time(philo) + philo->data->eat_time;
		philo->meals_count++;
	}
	return ;
}
