/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:08:25 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 19:31:34 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operating(t_info *stacks)
{
	if (stacks->list_size == 2)
		sa(stacks);
	else if (stacks->list_size == 3)
		sort_three_args(stacks);
	else
		sort_args(stacks);
}

void	sort_three_args(t_info *stacks)
{
	int	top;
	int	mid;
	int	bot;

	top = stacks->a_stack->top->next->data;
	mid = stacks->a_stack->top->next->next->data;
	bot = stacks->a_stack->top->next->next->next->data;
	if (top > mid && mid > bot && top > bot)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(stacks);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(stacks);
	else if (mid > top && mid > bot && top > bot)
		rra(stacks);
}

void	sort_args(t_info *stacks)
{
	int	a;
	int	b;

	divide_pivot(stacks);
	while (stacks->a_stack->len > 3)
		pb(stacks);
	if (stacks->a_stack->len == 2)
	{
		if (stacks->a_stack->top->next->data > \
			stacks->a_stack->top->next->next->data)
			sa(stacks);
	}
	if (stacks->a_stack->len == 3)
		sort_three_args(stacks);
	while (stacks->b_stack->len)
	{
		a = 0;
		b = 0;
		get_min_rotate(stacks, &a, &b);
		rotate_same(stacks, &a, &b);
		rotate_a(stacks, a);
		rotate_b(stacks, b);
		pa(stacks);
	}
	sort_big_last(stacks);
}

void	sort_big_last(t_info *stacks)
{
	int min_loc = find_mid_a(stacks);
	while (min_loc)
	{
		if (min_loc > 0)
		{
			ra(stacks);
			min_loc--;
		}
		else
		{
			rra(stacks);
			min_loc++;
		}
	}
}
