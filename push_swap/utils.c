/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:42:02 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 16:31:17 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str)
{
	int			sign;
	long long	ret;

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
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("+-0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_sorted(t_info *stacks)
{
	int	i;
	int	check;

	i = stacks->list_size;
	check = 0;
	while (i > 1)
	{
		if (stacks->list[i - 1] - stacks->list[i - 2] > 0)
			check++;
		i--;
	}
	if (check == stacks->list_size - 1)
		exit(0);
}

static int	find_max_index(t_info *stacks)
{
	int	max;
	int	idx;

	max = -2147483648;
	idx = 0;
	while (idx < stacks->list_size)
	{
		if (max < stacks->list[idx])
			max = stacks->list[idx];
		idx++;
	}
	idx = 0;
	while (idx < stacks->list_size)
	{
		if (max == stacks->list[idx])
		{
			stacks->list[idx] = -2147483648;
			return (idx);
		}
		idx++;
	}
	return (-1);
}

void	indexing(t_info *stacks)
{
	int	*idx_list;
	int	idx;
	int	max_idx;

	idx_list = (int *) malloc(sizeof(int) * stacks->list_size);
	if (!idx_list)
		print_error();
	idx = stacks->list_size - 1;
	while (idx >= 0)
	{
		max_idx = find_max_index(stacks);
		idx_list[max_idx] = idx;
		idx--;
	}
	free(stacks->list);
	stacks->list = idx_list;
}
