/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:49:39 by kali              #+#    #+#             */
/*   Updated: 2025/01/22 05:51:00 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		if (info_start(argc, argv, &info) == 0)
		{
			printf("invalid input\n");
			return (1);
		}
	}
	else
	{
		printf("ERROR!\nEntering the wrong amount\n");
		return (1);
	}
	beginning_phil(&info, -1);
	return (0);
}
