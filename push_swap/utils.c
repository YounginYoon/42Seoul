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

t_node	*make_new_node(int data)
{
	t_node	*ret;

	ret = (t_node *) malloc(sizeof(t_node));
	if (!ret)
		return (0);
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
