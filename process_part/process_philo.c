/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:03 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:43:09 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	take_forks(t_philo *philo, pthread_mutex_t *left_fork,
	pthread_mutex_t *right_fork)
{
	if (grab_forks_and_eat(philo, left_fork, right_fork) == 1)
		return (1);
	printf_mutex(philo, "is sleeping\n");
	usleep_philo(philo, philo->data->time_sleep);
	printf_mutex(philo, "is thinking\n");
	return (0);
}

void	*creat_print(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->data->fork[philo->id];
	right_fork = &philo->data->fork[(philo->id + 1)
		% (philo->data->nbr_philo)];
	last_eat_time(philo);
	if ((philo->id + 1) % 2 == 0)
		usleep(500);
	while (died_phiilo(philo) != -1)
	{
		if (take_forks(philo, left_fork, right_fork) == 1)
			return (NULL);
	}
	return (NULL);
}

int	count_work(t_data *data, int amount_food)
{
	if (data->count_work < 0)
		return (0);
	amount_food = count_philosophers_with_enough_work(data, 0, 0);
	if (amount_food == data->nbr_philo)
	{
		pthread_mutex_lock(&data->died_mutex);
		data->deat_i = -1;
		pthread_mutex_unlock(&data->died_mutex);
		return (1);
	}
	return (0);
}

int	dead(t_data *data, int i)
{
	while (i < data->nbr_philo)
	{
		if (check_philo_dead(&data->philo[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

void	process_philo(t_data *data)
{
	init_and_start_philos(data, -1);
	finalize_and_cleanup(data, -1);
}
