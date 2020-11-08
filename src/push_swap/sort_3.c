/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/11/07 11:46:05 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"
#include "printer.h"

static void	sort_3_cases(t_header **stack_a, t_header **stack_b,
			const int *digits)
{
	if (digits[1] < digits[0] && digits[0] < digits[2])
		util_repeat_operation_loud("sa", stack_a, stack_b, 1);
	else if (digits[0] < digits[2] && digits[2] < digits[1])
	{
		util_repeat_operation_loud("sa", stack_a, stack_b, 1);
		util_repeat_operation_loud("ra", stack_a, stack_b, 1);
	}
	else if (digits[2] < digits[0] && digits[0] < digits[1])
		util_repeat_operation_loud("rra", stack_a, stack_b, 1);
	else if (digits[1] < digits[2] && digits[2] < digits[0])
		util_repeat_operation_loud("ra", stack_a, stack_b, 1);
	else if (digits[2] < digits[1] && digits[1] < digits[0])
	{
		util_repeat_operation_loud("sa", stack_a, stack_b, 1);
		util_repeat_operation_loud("rra", stack_a, stack_b, 1);
	}
}

void		sort_3(t_header **stack_a, t_header **stack_b)
{
	int	triple[3];

	if ((*stack_a)->size != 3)
		return ;
	triple[0] = (*stack_a)->top->val;
	triple[1] = (*stack_a)->top->next->val;
	triple[2] = (*stack_a)->top->next->next->val;
	sort_3_cases(stack_a, stack_b, triple);
}
