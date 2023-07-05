/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_find_location.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:00:10 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 19:19:22 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_a(t_info *stacks)
{
	int		ret;
	int		min_idx;
	int		tmp;
	t_node	*cur;

	ret = 0;
	tmp = 0;
	cur = stacks->a_stack->top->next;
	min_idx = get_stack_min(stacks);
	while (ret < stacks->a_stack->len)
	{
		tmp = cur->data;
		if (tmp == min_idx)
			break ;
		ret++;
		cur = cur->next;
	}
	if (ret >= (stacks->a_stack->len + 1) / 2)
		ret = (stacks->a_stack->len - ret) * -1;
	return (ret);
}

int	find_max_a(t_info *stacks)
{
	int		ret;
	int		max_idx;
	int		tmp;
	t_node	*cur;

	ret = 0;
	tmp = 0;
	cur = stacks->a_stack->top->next;
	max_idx = get_stack_max(stacks);
	while (ret < stacks->a_stack->len)
	{
		tmp = cur->data;
		if (tmp == max_idx)
			break ;
		ret++;
		cur = cur->next;
	}
	ret++;
	if (ret >= (stacks->a_stack->len + 1) / 2)
		ret = (stacks->a_stack->len - ret) * -1;
	return (ret);
}

int	find_mid_a(int num, t_info *stacks)
{
	t_node	*cur;
	int		ret;
	int		idx;

	cur = stacks->a_stack->top->next;
	ret = 1;
	idx = 0;
	while (idx < stacks->a_stack->len)
	{
		if (cur->next->data == 0)
			return (0);
		if (cur->data < num && num < cur->next->data)
			break ;
		ret++;
		cur = cur->next;
		idx++;
	}
	if (ret >= (stacks->a_stack->len + 1) / 2)
		ret = (stacks->a_stack->len - ret) * -1;
	return (ret);
}

int	find_location_a(int num, t_info *stacks)
{
	int	ret;

	if (num < get_stack_min(stacks))
		ret = find_min_a(stacks);
	else if (num > get_stack_max(stacks))
		ret = find_max_a(stacks);
	else
		ret = find_mid_a(num, stacks);
	return (ret);
}
