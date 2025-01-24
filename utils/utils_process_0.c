/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:04:14 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:43:45 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_and_start_philos(t_data *data, int i)
{
	get_time();
	while (++i < data->nbr_philo)
		pthread_create(&data->philo[i].tid, NULL,
			(void *)creat_print, &data->philo[i]);
}

void	finalize_and_cleanup(t_data *data, int i)
{
	while (1)
	{
		if (dead(data, 0) == -1 || count_work(data, 0) == 1)
			break ;
	}
	while (++i < data->nbr_philo)
	{
		pthread_join(data->philo[i].tid, NULL);
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].last_eat_mutex);
		pthread_mutex_destroy(&data->philo[i].current_eats_mutexm);
	}
	free(data->philo);
	free(data->fork);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->died_mutex);
}
