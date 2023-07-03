/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:37:30 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/03 15:59:37 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_info	st;

	if (argc >=2)
	{
		init_stack(&st);
		validate_arg(argc, argv, &st);
	}
}
