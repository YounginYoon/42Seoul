/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:15:22 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 15:36:40 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_swap(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stack);
	tmp2 = pop_top(stack);
	push_top(stack, tmp1);
	push_top(stack, tmp2);
}

void	sa(t_info *stacks)
{
	ps_swap(stacks->a_stack);
	write(1, "sa\n", 3);
}

void	sb(t_info *stacks)
{
	ps_swap(stacks->a_stack);
	write(1, "sb\n", 3);
}

void	ss(t_info *stacks)
{
	ps_swap(stacks->a_stack);
	ps_swap(stacks->b_stack);
	write(1, "ss\n", 3);
}
