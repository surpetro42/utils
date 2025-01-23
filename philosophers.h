/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:55:33 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/22 05:50:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct timeval	t_timeval;

typedef struct s_philosophers
{
	long long		last_eat_time;
	int				id;
	int				current_meal;
	int				philo_eats;
	int				philo_dead;
	pthread_t		tid;
	pthread_mutex_t	is_died_mutex;
	pthread_mutex_t	last_eat_time_mutex;
	pthread_mutex_t	current_meal_mutexm;
	struct s_info	*info;
}	t_philosophers;

typedef struct s_info
{
	long long		number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_must_eat;
	int				id;
	int				deat;
	int				amount_work;
	pthread_mutex_t	is_died_mutex;
	pthread_t		esim;
	t_philosophers	*philosophers;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork;
}	t_info;

int		beginning(int argc, char **argv, t_info *info);
int		ft_atoi(const char *str);
int		init_philo(t_info *info, int i);
void	initializ_philos(t_info *info, int i);
void	beginning_phil(t_info *info, int i);















// long		ft_atoi(char *str);
// long long	get_time(void);
// int			validation(int argc, char **s, t_info *info);
// int			inspect(char **s);
// void		usleep_philo(t_philosophers *philo, long long time);
// int			initializations_philo(t_info *info);
// int			check_dead(t_info *info);
// int			amount_of_work(t_info *info);
// void		start_philo(t_info *info);
// void		get_last_eat_time_mutex(t_philosophers *philo);
// int			is_died(t_philosophers *philo);
// void		print_mutex(t_philosophers *philo, char *str);
// int			take_forks(t_philosophers *philo,
// 				pthread_mutex_t *left_fork, pthread_mutex_t *right_fork);

#endif