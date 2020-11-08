/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:52:57 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "operation.h"
#include "printer.h"

void	util_repeat_operation_loud(char *op, t_header **stack_a,
		t_header **stack_b, size_t count)
{
	while (count--)
	{
		operation_exec(op, stack_a, stack_b);
		printer_print(g_pw_output, op, -1);
		printer_print(g_pw_output, "\n", 1);
		if (g_pw_verbose)
			printer_print_stacks(g_pw_output, g_pw_color, *stack_a, *stack_b);
	}
}

void	util_align_stack(t_header **stack_a, t_header **stack_b)
{
	t_node			*node;
	register size_t	i;
	register size_t	min_index;
	size_t			moves_count;
	int				min;

	node = (*stack_a)->top;
	min = INT_MAX;
	i = 0;
	while (i < (*stack_a)->size)
	{
		if (node->val < min)
		{
			min = node->val;
			min_index = i;
		}
		node = node->next;
		i++;
	}
	moves_count = min_index <= (*stack_a)->size / 2 ?
				min_index : (*stack_a)->size - min_index;
	if (min_index <= (*stack_a)->size / 2)
		util_repeat_operation_loud("ra", stack_a, stack_b, moves_count);
	else
		util_repeat_operation_loud("rra", stack_a, stack_b, moves_count);
}
