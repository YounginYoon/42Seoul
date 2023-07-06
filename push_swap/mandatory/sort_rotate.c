/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:54:58 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/06 15:59:22 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_same(t_info *stacks, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stacks);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0) && (*b < 0))
	{
		rrr(stacks);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	rotate_a(t_info *stacks, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stacks);
			a--;
		}
		else
		{
			rra(stacks);
			a++;
		}
	}
}

void	rotate_b(t_info *stacks, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stacks);
			b--;
		}
		else
		{
			rrb(stacks);
			b++;
		}
	}
}

void	get_min_rotate(t_info *stacks, int *a_min, int *b_min)
{
	int		a_loc;
	int		b_loc;
	int		idx;
	t_node	*b_cur;
	int		num;

	idx = 0;
	b_cur = stacks->b_stack->top->next;
	while (idx < stacks->b_stack->len)
	{
		num = b_cur->data;
		a_loc = find_location_a(num, stacks);
		if (idx >= (stacks->b_stack->len + 1) / 2)
			b_loc = (stacks->b_stack->len - idx) * -1;
		else
			b_loc = idx;
		if (idx == 0 || check_bigger(*a_min, *b_min, a_loc, b_loc))
		{
			*a_min = a_loc;
			*b_min = b_loc;
		}
		b_cur = b_cur->next;
		idx++;
	}
}
