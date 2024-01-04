#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
	int id;
	pthread_t trd;
	struct timeval lastmeal;
	int die_time;
	int eat_time;
	int sleep_time;
	int eat_count;
	bool running; // if true stop all from runing
	bool is_dead; // if true sends message to stop all from running and sends dead message
	pthread_mutex_t l_fork;
	pthread_mutex_t *r_fork;
}	t_philo;

#endif

/*

*********** Entry argumens ***********

◦ number_of_philosophers                           -ac 2
◦ time_to_die                                      -ac 3
◦ time_to_eat                                      -ac 4
◦ time_to_sleep                                    -ac 5
◦ [number_of_times_each_philosopher_must_eat]      -ac 6    ***optional***

◦ time_in ms X has taken a fork
◦ time_in ms X is eating
◦ time_in ms X is sleeping
◦ time_in ms X is thinking
◦ time_in ms X died
	
	//printf("%ld ms| %d has taken a fork\n", runtime, philo->id);
	//printf("%ld ms| %d is eating\n", runtime, philo->id);
	//printf("%ld ms| %d is sleeping\n", runtime, philo->id);
	//printf("%ld ms| %d is thinking\n", runtime, philo->id);
	//printf("%ld ms| %d died\n", runtime, philo->id);

flags cc -pthread -Wall -Wextra -Werror -fsanitize=address philo.c philo.h

//////// TO DO //////////
  Make the Makefille
  Time in ms
  all the funtions that run inside routine
  -fork locking and unlocking.
  -eating.
  -sleeping.
  -thinking.
*/