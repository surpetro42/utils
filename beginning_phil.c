/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning_phil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:46:41 by kali              #+#    #+#             */
/*   Updated: 2025/01/22 05:50:52 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*creat_print(t_philosophers *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->info->fork[philo->id];
	right_fork = &philo->info->fork[(philo->id + 1)
		% (philo->info->number_philo)];
	get_last_eat_time_mutex(philo);
	if ((philo->id + 1) % 2 == 0)
		usleep(500);
	while (is_died(philo) != -1)
	{
		if (take_forks(philo, left_fork, right_fork) == 1)
			return (NULL);
	}
	return (NULL);
}

void	beginning_phil(t_info *info, int i)
{
	get_time();
	while (++i < info->number_philo)
		pthread_create(&info->philosophers[i].tid, NULL,
			(void *)creat_print, &info->philosophers[i]);
	while (1)
	{
		if (check_dead(info) == -1
			|| amount_of_work(info) == 1)
			break ;
	}
	i = -1;
	while (++i < info->number_philo)
	{
		pthread_join(info->philosophers[i].tid, NULL);
		pthread_mutex_destroy(&info->fork[i]);
		pthread_mutex_destroy(&info->philosophers[i].last_eat_time_mutex);
		pthread_mutex_destroy(&info->philosophers[i].current_meal_mutexm);
	}
	free(info->philosophers);
	free(info->fork);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->is_died_mutex);
}
