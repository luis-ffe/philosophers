#include "philo.h"

int find_dead(t_philo *philo)
{
	if (philo->is_dead == true)
	{
		printf("time_in_ms %i died\n", philo->id);
		return (1);
	}
	if(philo->data->running == true)
		philo->data->running = false;
	return (0);
}

// void update_termination_status(t_philo *philo)
// {
// 	//all alive
// 	//some one died
// 	// all eaten 
// }


int	get_forks_eat(t_philo *philo)
{
	if (philo->data->running == false)
		return (0);
	if (pthread_mutex_lock(&philo->l_fork) == 0 && pthread_mutex_lock(philo->r_fork) == 0)
	{
		printf("ld ms | %d has taken a fork\n", philo->id);
		printf("ld ms | %d has taken a fork\n", philo->id);
		if(philo->meals_count != philo->data->meals_nbr )
		{
			printf("ld ms | %d is eating\n", philo->id);
			usleep(philo->data->eat_time);
			philo->lastmeal = ms_calc_diff(philo->data->current_time, philo->data->start_time);
			philo->meals_count++;
		}
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->l_fork);
		return (1);
	}
	return (0);
}

int	go_sleep(t_philo *philo)
{
	if (philo->data->running == false)
		return (0);
	printf("ld ms | %d is sleeping\n", philo->id);
	usleep(philo->data->sleep_time);
	return (1);
}

int	go_think(t_philo *philo)
{
	if (philo->data->running == false)
		return (0);
	printf("ld ms | %d is thinking\n", philo->id);
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
		go_sleep(philo);
		go_think(philo);
	}
	else
		go_think(philo);
	while (philo->data->running)
	{
		//update_termination_status(philo);
		get_forks_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}

// void fork_pointers(t_philo *philo)
// {
// 	while (philo.id == philo.data->phil_nbr)  update fork pointings
// 		philo.r_fork =
// }

void thread_runner(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->phil_nbr)
	{

		pthread_create(&philos[i].trd, NULL, &routine, &philos[i]);
	}
	while (philos->data->running == true)
		gettimeofday(&philos->data->current_time, NULL);
	i = -1;
	while (++i < philos->data->phil_nbr)
		pthread_join(philos[i].trd, NULL);
	destroy_all_mutex(philos);
}
