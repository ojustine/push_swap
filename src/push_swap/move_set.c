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

#include <limits.h>
#include "push_swap.h"

static inline size_t	case_up_up(size_t a_index, size_t b_index)
{
	size_t			moves;

	moves = a_index <= b_index ? a_index : b_index;
	moves += a_index - moves + b_index - moves;
	return (moves + 1);
}

static inline size_t	case_down_down(t_header **stack_a, t_header **stack_b,
						size_t a_index, size_t b_index)
{
	size_t			moves;
	const size_t	size_a = (*stack_a)->size;
	const size_t	size_b = (*stack_b)->size;

	moves = size_a - a_index <= size_b - b_index
			? size_a - a_index : size_b - b_index;
	moves += size_a - (a_index + moves) + size_b - (b_index + moves);
	return (moves + 1);
}

static inline size_t	case_up_down(t_header **stack_b, size_t a_index,
						size_t b_index)
{
	return (a_index + (*stack_b)->size - b_index + 1);
}

static inline size_t	case_down_up(t_header **stack_a, size_t a_index,
						size_t b_index)
{
	return ((*stack_a)->size - a_index + b_index + 1);
}

size_t					move_set_choose(t_header **stack_a, t_header **stack_b,
						size_t a_index, size_t b_index)
{
	register size_t	index;
	size_t			cases[4];
	size_t			moves;

	cases[UP_UP] = case_up_up(a_index, b_index);
	cases[DOWN_DOWN] = case_down_down(stack_a, stack_b, a_index, b_index);
	cases[UP_DOWN] = case_up_down(stack_b, a_index, b_index);
	cases[DOWN_UP] = case_down_up(stack_a, a_index, b_index);
	index = 0;
	moves = INT_MAX;
	while (index < 4)
	{
		if (cases[index] < moves)
		{
			moves = cases[index];
			(*stack_a)->move_set = index;
		}
		index++;
	}
	return (moves);
}
