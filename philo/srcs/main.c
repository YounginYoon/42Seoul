/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:50:43 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/27 17:33:21 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error(char *err_msg)
{
	printf("Error: %s\n", err_msg);
	return (FAIL);
}

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		return (print_error("invalid number of args"));
	}
	memset(&arg, 0, sizeof(t_arg));
	if (init_args(&arg, argc, argv))
		return (print_error("args init fail"));
	if (init_philo(&philo, &arg))
		return (print_error("philo init fail"));
	if (ph_start(&arg, philo))
		return (print_error("philo start fail"));
	return (SUCCESS);
}
