/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning_inf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:58:19 by kali              #+#    #+#             */
/*   Updated: 2025/01/22 05:46:51 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initializ_philos(t_info *info, int i)
{
	while (i < info->number_philo)
	{
		info->philosophers[i].id = i;
		info->philosophers[i].current_meal = 0;
		info->philosophers[i].philo_dead = info->deat;
		info->philosophers[i].last_eat_time = LLONG_MAX;
		pthread_mutex_init(&info->fork[i], NULL);
		pthread_mutex_init(&info->philosophers[i].last_eat_time_mutex, NULL);
		pthread_mutex_init(&info->philosophers[i].current_meal_mutexm, NULL);
		info->philosophers[i].info = info;
		i++;
	}
}

int	init_philo(t_info *info, int i)
{
	info->philosophers = malloc(sizeof(t_philosophers)
			* (info->number_philo));
	if (!info->philosophers)
		return (0);
	info->fork = malloc(sizeof(pthread_mutex_t)
			* (info->number_philo));
	if (!info->fork)
	{
		free(info->philosophers);
		return (0);
	}
	initializ_philo(info, i);
	return (1);
}

int	inspect(char **s, int i, int l)
{
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (!(s[i][l] >= '0' && s[i][l] <= '9'))
			{
				printf("ERROR!\nIncorrect input\n");
				return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}

int	valid_phil(int argc, char **s, t_info *info)
{
	if (inspect(s, 1, 0) == 0)
		return (0);
	info->number_philo = ft_atoi(s[1]);
	if (info->number_philo < 1 || info->number_philo > 200)
		return (0);
	info->time_die = ft_atoi(s[2]);
	info->time_eat = ft_atoi(s[3]);
	info->time_sleep = ft_atoi(s[4]);
	if (info->time_die < 0 || info->time_eat < 0
		|| info->time_sleep < 0)
		return (0);
	info->deat = 0;
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->is_died_mutex, NULL);
	if (argc == 6)
		info->amount_work = ft_atoi(s[5]);
	else
		info->amount_work = -1;
	if (argc == 6 && info->amount_work == -1) // karoxa chashxati
		return (0);
	return (1);
}

int	beginning(int argc, char **argv, t_info *info)
{
	if (valid_phil(argc, argv, info) == 0)
		return (0);
	if (init_philo(info, 0) == 0)
		return (0);
	return (1);
}
