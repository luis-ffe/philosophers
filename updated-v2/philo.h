#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data
{
	bool			running;
	int				phil_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_nbr;
	struct timeval	start_time;
	struct timeval	current_time;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_count;
	bool			is_dead;
	long long		lastmeal;
	pthread_t		trd;
	t_data			*data;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

///////////////////////////////////////////////////////////////
//                         UTILS.C                           //
///////////////////////////////////////////////////////////////

long long ms_calc_diff(struct timeval a, struct timeval b);
void		print_error(void);
int			ft_atoi(const char *str);

///////////////////////////////////////////////////////////////
//                   INPUT_VALIDATION.C                      //
///////////////////////////////////////////////////////////////

int			ft_validate_args(int argc, char **argv);

///////////////////////////////////////////////////////////////
//                          INIT.C                           //
///////////////////////////////////////////////////////////////

t_data		init_data(int argc, char **argv);
t_philo		*init_philo(t_data *data);
void		destroy_all_mutex(t_philo *philos);

///////////////////////////////////////////////////////////////
//                         ROUTINE.C                         //
///////////////////////////////////////////////////////////////

long long set_time(t_philo philo);
int find_dead(t_philo *philo);
int	get_forks_eat(t_philo *philo);
int	go_sleep(t_philo *philo);
int	go_think(t_philo *philo);

void		*routine(void *arg);
void		thread_runner(t_philo *philos);

#endif













/*
*********** INPUT ARGUMENTS ***********
RULES: only positive numerical characters

◦ number_of_philosophers                           -ac 2
◦ time_to_die                                      -ac 3
◦ time_to_eat                                      -ac 4
◦ time_to_sleep                                    -ac 5
◦ [number_of_times_each_philosopher_must_eat]      -ac 6    ***optional***

Must display:
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