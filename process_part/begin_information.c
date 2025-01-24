/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:02 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:18:07 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	initialize(int i, t_data *data)
{
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i;
		data->philo[i].current_eats = 0;
		data->philo[i].dead = data->deat_i;
		data->philo[i].last_eat = LLONG_MAX;
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->philo[i].last_eat_mutex, NULL);
		pthread_mutex_init(&data->philo[i].current_eats_mutexm, NULL);
		data->philo[i].data = data;
		i++;
	}
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo)
			* (data->nbr_philo));
	if (!data->philo)
		return (0);
	data->fork = malloc(sizeof(pthread_mutex_t)
			* (data->nbr_philo));
	if (!data->fork)
	{
		free(data->philo);
		return (0);
	}
	initialize(i, data);
	return (1);
}

int	valid_philo(int argc, char **s, t_data *data)
{
	if (inspect(s, 1) == 0)
		return (0);
	data->nbr_philo = ft_atoi(s[1]);
	if (data->nbr_philo < 1 || data->nbr_philo > 200)
		return (0);
	if (data_arg_assigns_atoi(data, s) == 0)
		return (0);
	data->deat_i = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->died_mutex, NULL);
	if (argc == 6)
		data->count_work = ft_atoi(s[5]);
	else
		data->count_work = -1;
	if (argc == 6 && data->count_work < 0)
		return (0);
	return (1);
}

int	begin_information(int argc, char **argv, t_data *data)
{
	if (valid_philo(argc, argv, data) == 0)
		return (0);
	if (init_philo(data) == 0)
		return (0);
	return (1);
}
