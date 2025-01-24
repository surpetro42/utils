/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:42:39 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/24 23:01:25 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (begin_information(argc, argv, &data) == 0)
		{
			printf("invalid input\n");
			return (1);
		}
	}
	else
	{
		printf("ERROR!\nSxal qanaki mutqagrum\n");
		return (1);
	}
	process_philo(&data);
	system("leaks philo");
	return (0);
}
