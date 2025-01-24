/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:06 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:42:27 by surpetro         ###   ########.fr       */
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

typedef struct s_philo
{
	long long		last_eat;
	int				id;
	int				current_eats;
	int				eats;
	int				dead;
	pthread_t		tid;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	current_eats_mutexm;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long long		nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
	int				id;
	int				deat_i;
	int				count_work;
	pthread_mutex_t	died_mutex;
	pthread_t		esim_e;
	t_philo			*philo;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork;
}	t_data;

// ------ beginning_part/begin_information ------
int			begin_information(int argc, char **argv, t_data *info);
void		process_philo(t_data *data);

// ------ beginning_part/process_philo.c ------
void		philo_initialization(t_data *info, int i);
int			count_work(t_data *data, int amount_food);
void		*creat_print(t_philo *philo);
int			dead(t_data *data, int i);

// ------ utils/ ------
int			ft_atoi(const char *str);
long long	get_time(void);
int			inspect_input(char **s, int i, int l);
int			data_arg_assigns_atoi(t_data *data, char **s);
int			inspect(char **s, int i);
void		finalize_and_cleanup(t_data *data, int i);
void		init_and_start_philos(t_data *data, int i);
void		usleep_philo(t_philo *philo, long long time);
void		last_eat_time(t_philo *philo);
int			died_phiilo(t_philo *philo);
void		printf_mutex(t_philo *philo, char *str);
int			check_philo_dead(t_philo *philo);
int			count_philosophers_with_enough_work(t_data *data,
				int i, int amount_food);
int			grab_forks_and_eat(t_philo *philo,
				pthread_mutex_t *left_fork, pthread_mutex_t *right_fork);

#endif