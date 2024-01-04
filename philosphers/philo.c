#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j *= 10;
		j += str[i++] - '0';
	}
	return (j);
}

///////////////////////////////////////////////////////////////

void	print_error(void)
{
	printf("\nINPUT ERROR\n");
	printf("use as: ./philo <number_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]\n");
}

static int check_arg_content(char *str) // zero is invalid
{
	int i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		else
			i++;
	}
	return (1);
}

int ft_validate_args(int argc, char **argv) // 0 not valid,  1 is valid
{
	static int i;

	if (argc < 5 || argc > 6)
	{
		print_error();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (check_arg_content(argv[i]) == 0)
		{
			print_error();
			return (0);
		}
		i++;
	}
	return (1);
}

//////////////////////////////////////////////////////////////////////////////

t_philo *init_philo(int argc, char **argv)
{
	t_philo *philo;
	int nbr;
	int i;

	nbr = ft_atoi(argv[1]);
	philo = (t_philo *)malloc(sizeof(t_philo) * nbr);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		philo[i].id = i + 1;
		philo[i].die_time = ft_atoi(argv[2]);
		philo[i].eat_time = ft_atoi(argv[3]);
		philo[i].sleep_time = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].eat_count = ft_atoi(argv[5]);
		else
			philo[i].eat_count = -1;
		philo[i].running = true;
		philo[i].is_dead = false;
		i++;
	}
	return (philo);
}

void *routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	// if (philo.running == true)
	// {
//all the functionality implemented here now pls.///////////////
	// }
	//printf("%ld ms| %d is eating\n", runtime, philo->id);
	return (NULL);
}

void thread_init_or_destroy(t_philo *philos, int count, bool run)
{
	int i;

	i = -1;
	while (++i < count && run == true)
		pthread_mutex_init(&philos[i].l_fork, NULL);
	while (++i < count && run == false)
		pthread_mutex_destroy(&philos[i].l_fork);
}

void thread_runner(t_philo *philos, int count)
{
	int	i;
	
	thread_init_or_destroy(philos, count, true);
	i = -1;
	while (++i < count)
		pthread_create(&philos[i].trd, NULL, &routine, &philos[i]);
	i = -1;
	while (++i < count)
		pthread_join(philos[i].trd, NULL);
	thread_init_or_destroy(philos, count, false);
}

int main(int argc, char **argv)
{
	t_philo	*philos;
	int		phil_count;

	if (ft_validate_args(argc, argv) == 0)	
		return (0);
	philos = init_philo(argc, argv);
	phil_count = ft_atoi(argv[1]);
	thread_runner(philos, phil_count);
	free(philos);
	return (0);
}

////////////////////////////////////////////////////////////////
	// int i = 0;
	// while (i < phil_count)
	// {
	// 	printf("%d\n", philos[i].id);
	// 	printf("%d\n", philos[i].die_time);
	// 	printf("%d\n", philos[i].eat_time);
	// 	printf("%d\n", philos[i].sleep_time);
	// 	if (argc == 6)
	// 		printf("%d\n", philos[i].eat_count);
	// 	i++;
	// }

//printf("\n%d\n", philos[4].id);  //scope testing the threads.
//////////////////////////////////////////////////////////////