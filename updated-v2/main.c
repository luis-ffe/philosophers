#include "philo.h"




int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	if (ft_validate_args(argc, argv) == 0)	
		return (0);
	data = init_data(argc, argv);
	philos = init_philo(&data);
	thread_runner(philos);
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