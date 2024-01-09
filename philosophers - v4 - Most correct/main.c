/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:26:25 by luis-ffe          #+#    #+#             */
/*   Updated: 2024/01/09 07:26:53 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	if (ft_validate_args(argc, argv) == 0)
		return (0);
	data = init_data(argc, argv);
	philos = init_philo(&data);
	if (check_extra_errors(*philos))
	{
		print_error();
		free(philos);
		return (1);
	}
	thread_runner(philos);
	free(philos);
	return (0);
}
