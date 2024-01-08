#include "philo.h"

long long ms_calc_diff(struct timeval a, struct timeval b)
{
	long long diff_ms;

	diff_ms = (b.tv_sec * 1000 + b.tv_usec / 1000) - (a.tv_sec * 1000 + a.tv_usec / 1000);
	return (diff_ms);
}


long long set_time(t_philo philo)
{
	long long current_ms;

	current_ms = (philo.data->current_time.tv_sec * 1000 + philo.data->current_time.tv_sec / 1000) 
	- (philo.data->start_time.tv_sec * 1000 + philo.data->start_time.tv_usec / 1000);
	return (current_ms);
}

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

void	print_error(void)
{
	printf("\nINPUT ERROR\n");
	printf("use as: ./philo <number_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]\n");
}
