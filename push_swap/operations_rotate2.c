/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:28:37 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 15:42:26 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rr(t_stack *stack)
{
	t_node	*tmp;

	tmp = pop_bottom(stack);
	push_top(stack, tmp);
}

void	rra(t_info *stacks)
{
	ps_rr(stacks->a_stack);
	write(1, "rra\n", 4);
}

void	rrb(t_info *stacks)
{
	ps_rr(stacks->b_stack);
	writ(1, "rrb\n", 4);
}

void	rrr(t_info *stacks)
{
	ps_rr(stacks->a_stack);
	ps_rr(stacks->b_stack);
	write(1, "rrr\n", 4);
}
