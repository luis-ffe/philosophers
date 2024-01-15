/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 01:39:37 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/15 20:02:58 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_data
{
	pthread_mutex_t	access;
	bool			running;
	int				phil_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_nbr;
	long long		start_time;
	long long		current_time;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_count;
	long long		lastmeal;
	pthread_t		trd;
	t_data			*data;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

///////////////////////////////////////////////////////////////
//                         UTILS.C                           //
///////////////////////////////////////////////////////////////

int			philosopher_is_on_time(t_philo *philo);
bool		get_mutex_bool(pthread_mutex_t *mutex, bool *info);
long long	update_current_time(t_philo *philo);
long long	my_gettimeofday(void);
bool		is_he_alive(t_philo *philo);

///////////////////////////////////////////////////////////////
//                   INPUT_VALIDATION.C                      //
///////////////////////////////////////////////////////////////

int			check_extra_errors(t_philo philo);
int			check_arg_content(char *str);
int			ft_validate_args(int argc, char **argv);
int			ft_atoi(const char *str);
void		print_error(void);

///////////////////////////////////////////////////////////////
//                          INIT.C                           //
///////////////////////////////////////////////////////////////

t_data		init_data(int argc, char **argv);
t_philo		*init_philo(t_data *data);
void		destroy_all_mutex(t_philo *philos);

///////////////////////////////////////////////////////////////
//                         ROUTINE.C                         //
///////////////////////////////////////////////////////////////

void		philosopher_is_thinking(t_philo *philo);
void		*routine(void *arg);
void		thread_runner(t_philo *philos);

///////////////////////////////////////////////////////////////
//                         ACTIONS.C                         //
///////////////////////////////////////////////////////////////

void		kill_philosopher_and_stop_running(t_philo *philo);
void		philosopher_is_eating(t_philo *philo);
int			philosopher_is_allowed_to(t_philo *philo);
bool		philosopher_try_to_eat(t_philo *philo);
void		philosopher_goes_to_sleep(t_philo *philo);

///////////////////////////////////////////////////////////////
//                     ACTIONS_UTILS.C                       //
///////////////////////////////////////////////////////////////

void		update_lastmeal_time(t_philo *philo);
int			philosopher_grabs_forks(t_philo *philo);
void		philosopher_drops_forks(t_philo *philo);
void		ft_print_status(t_philo *philo, int status);
int			philosopher_is_on_time(t_philo *philo);

#endif
