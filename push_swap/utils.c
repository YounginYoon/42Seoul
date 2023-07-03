/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:42:02 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/03 14:45:10 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str)
{
	int 		sign;
	long long 	ret;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!('0' <= *str && *str <= '9'))
		print_error();
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (ret * sign > 2147483647 || ret * sign < -2147483648)
		print_error();
	return (sign * ret);
}

int	check_valid_atoi(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("+-0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}