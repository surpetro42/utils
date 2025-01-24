/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_begin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:04:14 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 22:53:00 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	printf_err(char *s, int i)
{
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			printf("ERROR!\nSxal mutqagrum\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	inspect(char **s, int i)
{
	while (s[i])
	{
		if (printf_err(s[i], 0) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	data_arg_assigns_atoi(t_data *data, char **s)
{
	data->time_die = ft_atoi(s[2]);
	data->time_eat = ft_atoi(s[3]);
	data->time_sleep = ft_atoi(s[4]);
	if (data->time_die < 0 || data->time_eat < 0
		|| data->time_sleep < 0)
		return (0);
	return (1);
}
