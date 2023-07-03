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
#include <stdio.h>

int	main(void)
{
	t_info	st;

	init_stack(&st);
	push_top(st.a_stack, make_new_node(1));
	push_top(st.a_stack, make_new_node(2));
	push_top(st.a_stack, make_new_node(3));
	push_top(st.a_stack, make_new_node(4));
	push_top(st.a_stack, make_new_node(5));

	while (!is_empty_stack(st.a_stack))
	{
		t_node *del = pop_top(st.a_stack);
		printf("pop %d %d\n", del->data, st.a_stack->len);
	}

}
