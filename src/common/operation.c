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

#include "operation.h"
#include "libft.h"

void	operation_swap(t_header **stack_1, t_header **stack_2)
{
	int	tmp;

	if (stack_1 && (*stack_1)->size > 1)
	{
		tmp = (*stack_1)->top->val;
		(*stack_1)->top->val = (*stack_1)->top->next->val;
		(*stack_1)->top->next->val = tmp;
	}
	if (stack_2 && (*stack_2)->size > 1)
	{
		tmp = (*stack_2)->top->val;
		(*stack_2)->top->val = (*stack_2)->top->next->val;
		(*stack_2)->top->next->val = tmp;
	}
}

void	operation_push(t_header **stack_src, t_header **stack_dst)
{
	stack_push(stack_dst, stack_pop(stack_src));
}

void	operation_rotate(t_header **stack_1, t_header **stack_2, int reversed)
{
	if (stack_1 && (*stack_1)->size > 1)
		(*stack_1)->top = reversed ? (*stack_1)->top->prev
									: (*stack_1)->top->next;
	if (stack_2 && (*stack_2)->size > 1)
		(*stack_2)->top = reversed ? (*stack_2)->top->prev
									: (*stack_2)->top->next;
}

int		operation_exec(char *op, t_header **stack_a, t_header **stack_b)
{
	if (ft_strequ("sa", op))
		operation_swap(stack_a, NULL);
	else if (ft_strequ("sb", op))
		operation_swap(stack_b, NULL);
	else if (ft_strequ("ss", op))
		operation_swap(stack_a, stack_b);
	else if (ft_strequ("pa", op))
		operation_push(stack_b, stack_a);
	else if (ft_strequ("pb", op))
		operation_push(stack_a, stack_b);
	else if (ft_strequ("ra", op))
		operation_rotate(stack_a, NULL, 0);
	else if (ft_strequ("rb", op))
		operation_rotate(stack_b, NULL, 0);
	else if (ft_strequ("rr", op))
		operation_rotate(stack_a, stack_b, 0);
	else if (ft_strequ("rra", op))
		operation_rotate(stack_a, NULL, 1);
	else if (ft_strequ("rrb", op))
		operation_rotate(stack_b, NULL, 1);
	else if (ft_strequ("rrr", op))
		operation_rotate(stack_a, stack_b, 1);
	else
		return (0);
	return (1);
}
