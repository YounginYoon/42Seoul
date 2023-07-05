/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:29:28 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 19:23:18 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacking(t_info *stacks)
{
	t_node	*new_node;
	int		idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		new_node = make_new_node(stacks->list[idx] + 1);
		push_bottom(stacks->a_stack, new_node);
		idx++;
	}
	stacks->a_stack->len = stacks->list_size;
	stacks->max_list_size = stacks->list_size;
}

void	divide_pivot(t_info *stacks)
{
	t_node	*tmp;
	int		times;
	int		p1;
	int		p2;

	p1 = stacks->max_list_size / 3;
	p2 = (stacks->max_list_size / 3) * 2;
	times = 0;
	while (times < stacks->max_list_size)
	{
		tmp = pop_top(stacks->a_stack);
		if (tmp->data < p2)
		{
			push_top(stacks->a_stack, tmp);
			pb(stacks);
			if (tmp->data < p1)
				rb(stacks);
		}
		else
		{
			push_top(stacks->a_stack, tmp);
			ra(stacks);
		}
		times++;
	}
}

int	get_stack_min(t_info *stacks)
{
	int		ret;
	int		times;
	t_node	*cur;

	cur = stacks->a_stack->top->next;
	ret = cur->data;
	times = 0;
	while (times < stacks->a_stack->len - 1)
	{
		if (ret > cur->next->data)
			ret = cur->next->data;
		cur = cur->next;
		times++;
	}
	return (ret);
}

int	get_stack_max(t_info *stacks)
{
	int		ret;
	int		times;
	t_node	*cur;

	cur = stacks->a_stack->top->next;
	ret = cur->data;
	times = 0;
	while (times < stacks->a_stack->len - 1)
	{
		if (ret < cur->next->data)
			ret = cur->next->data;
		cur = cur->next;
		times++;
	}
	return (ret);
}

int	check_bigger(int a_min, int b_min, int a_loc, int b_loc)
{
	if (a_min < 0)
		a_min = a_min * -1;
	if (b_min < 0)
		b_min = b_min * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc - b_loc * -1;
	if (a_min + b_min > a_loc + b_loc)
		return (1);
	return (0);
}
