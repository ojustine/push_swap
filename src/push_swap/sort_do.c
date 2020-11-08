/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/13 00:21:19 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"
#include "printer.h"

static inline void	sort_do_case_up_up(t_header **stack_a, t_header **stack_b)
{
	size_t	count_comm;
	size_t	count_a;
	size_t	count_b;

	count_comm = (*stack_a)->sort_index <= (*stack_b)->sort_index
				? (*stack_a)->sort_index : (*stack_b)->sort_index;
	count_a = (*stack_a)->sort_index - count_comm;
	count_b = (*stack_b)->sort_index - count_comm;
	util_repeat_operation_loud("rr", stack_a, stack_b, count_comm);
	util_repeat_operation_loud("ra", stack_a, stack_b, count_a);
	util_repeat_operation_loud("rb", stack_a, stack_b, count_b);
}

static inline void	sort_do_case_down_down(t_header **stack_a,
					t_header **stack_b)
{
	const size_t	size_a = (*stack_a)->size;
	const size_t	size_b = (*stack_b)->size;
	size_t			count_comm;
	size_t			count_a;
	size_t			count_b;

	count_comm = size_a - (*stack_a)->sort_index <=
				size_b - (*stack_b)->sort_index ?
				size_a - (*stack_a)->sort_index :
				size_b - (*stack_b)->sort_index;
	count_a = (*stack_a)->sort_index + count_comm;
	count_b = (*stack_b)->sort_index + count_comm;
	util_repeat_operation_loud("rrr", stack_a, stack_b, count_comm);
	util_repeat_operation_loud("rra", stack_a, stack_b, size_a - count_a);
	util_repeat_operation_loud("rrb", stack_a, stack_b, size_b - count_b);
}

static inline void	sort_do_case_up_down(t_header **stack_a, t_header **stack_b)
{
	const size_t	size_b = (*stack_b)->size;
	const size_t	count_a = (*stack_a)->sort_index;
	const size_t	count_b = (*stack_b)->sort_index;

	util_repeat_operation_loud("ra", stack_a, stack_b, count_a);
	util_repeat_operation_loud("rrb", stack_a, stack_b, size_b - count_b);
}

static inline void	sort_do_case_down_up(t_header **stack_a, t_header **stack_b)
{
	const size_t	size_a = (*stack_a)->size;
	const size_t	count_a = (*stack_a)->sort_index;
	const size_t	count_b = (*stack_b)->sort_index;

	util_repeat_operation_loud("rra", stack_a, stack_b, size_a - count_a);
	util_repeat_operation_loud("rb", stack_a, stack_b, count_b);
}

void				sort_do(t_header **stack_a, t_header **stack_b)
{
	if ((*stack_b)->move_set == UP_UP)
		sort_do_case_up_up(stack_a, stack_b);
	else if ((*stack_b)->move_set == DOWN_DOWN)
		sort_do_case_down_down(stack_a, stack_b);
	else if ((*stack_b)->move_set == UP_DOWN)
		sort_do_case_up_down(stack_a, stack_b);
	else if ((*stack_b)->move_set == DOWN_UP)
		sort_do_case_down_up(stack_a, stack_b);
	util_repeat_operation_loud("pa", stack_a, stack_b, 1);
}
