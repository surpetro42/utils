/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:56:12 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:46:23 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_philo_dead(t_philo *philo)
{
	long long	current_time;

	current_time = get_time();
	pthread_mutex_lock(&philo->last_eat_mutex);
	if (current_time - philo->last_eat >= philo->data->time_die)
	{
		pthread_mutex_lock(&philo->data->died_mutex);
		philo->data->deat_i = -1;
		pthread_mutex_unlock(&philo->data->died_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%lld %d died\n", current_time, philo->id + 1);
		pthread_mutex_unlock(&philo->data->print_mutex);
		pthread_mutex_unlock(&philo->last_eat_mutex);
		return (-1);
	}
	pthread_mutex_unlock(&philo->last_eat_mutex);
	return (0);
}

void	last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->last_eat_mutex);
}

int	died_phiilo(t_philo *philo)
{
	int	is_died;

	pthread_mutex_lock(&philo->data->died_mutex);
	is_died = philo->data->deat_i;
	pthread_mutex_unlock(&philo->data->died_mutex);
	return (is_died);
}

void	printf_mutex(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (died_phiilo(philo) != -1)
		printf("%lld %d %s", get_time(), philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
