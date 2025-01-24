/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:56:12 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:46:13 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	get_time(void)
{
	static long long	start;
	t_timeval			time;

	if (start == 0)
	{
		gettimeofday(&time, NULL);
		start = time.tv_sec * 1000 + time.tv_usec / 1000;
	}
	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - start);
}

int	is_simulation_stopped(t_philo *philo)
{
	int	stopped;

	pthread_mutex_lock(&philo->data->died_mutex);
	stopped = (philo->data->deat_i == -1);
	pthread_mutex_unlock(&philo->data->died_mutex);
	return (stopped);
}

void	usleep_philo(t_philo *philo, long long time)
{
	long long	start_time;

	start_time = get_time();
	while (get_time() - start_time <= time)
	{
		if (is_simulation_stopped(philo))
			break ;
		usleep(500);
	}
}

int	count_philosophers_with_enough_work(t_data *data, int i, int amount_food)
{
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&data->philo[i].current_eats_mutexm);
		if (data->philo[i].current_eats >= data->count_work)
			amount_food++;
		pthread_mutex_unlock(&data->philo[i].current_eats_mutexm);
		i++;
	}
	return (amount_food);
}

int	grab_forks_and_eat(t_philo *philo,
	pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	pthread_mutex_lock(left_fork);
	printf_mutex(philo, "has taken a fork\n");
	if (philo->data->nbr_philo == 1)
	{
		pthread_mutex_unlock(left_fork);
		return (1);
	}
	pthread_mutex_lock(right_fork);
	printf_mutex(philo, "has taken a fork\n");
	printf_mutex(philo, "is eating\n");
	last_eat_time(philo);
	usleep_philo(philo, philo->data->time_eat);
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	pthread_mutex_lock(&philo->current_eats_mutexm);
	philo->current_eats++;
	pthread_mutex_unlock(&philo->current_eats_mutexm);
	return (0);
}
