#include "philo.h"

t_data	init_data(int argc, char **argv)
{
	t_data data;

	data.start_time = my_gettimeofday();
	data.current_time = 0;
	data.phil_nbr = ft_atoi(argv[1]);
	data.die_time = ft_atoi(argv[2]);
	data.eat_time = ft_atoi(argv[3]);
	data.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data.meals_nbr = ft_atoi(argv[5]);
	else
		data.meals_nbr = -1;
	data.running = true;
	return (data);
}

t_philo	*init_philo(t_data *data)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->phil_nbr);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < data->phil_nbr)
	{
		pthread_mutex_init(&philo[i].l_fork, NULL);
		if (i == data->phil_nbr - 1)
			philo[i].r_fork = &philo[0].l_fork;
		else
			philo[i].r_fork = &philo[i + 1].l_fork;
		philo[i].id = i + 1;
		philo[i].meals_count = 0;
		philo[i].lastmeal = 0;
		philo[i].data = data;
	}
	return (philo);
}

void	destroy_all_mutex(t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->data->phil_nbr && philos->data->running == false)
		pthread_mutex_destroy(&philos[i].l_fork);
}
