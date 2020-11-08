/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:52:27 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

static inline void		sort_save_best(t_header **stack_a, t_header **stack_b,
						size_t a_index, size_t b_index)
{
	(*stack_a)->sort_index = a_index;
	(*stack_b)->sort_index = b_index;
	(*stack_b)->move_set = (*stack_a)->move_set;
}

void					sort_main_loop(t_header **stack_a, t_header **stack_b)
{
	register size_t	b_index;
	register size_t	a_index;
	register size_t	moves;
	register size_t	moves_min;
	register t_node	*b_node;

	inc_seq_process(stack_a, stack_b);
	while ((*stack_b)->size > 0)
	{
		moves_min = INT_MAX;
		b_node = (*stack_b)->top;
		b_index = 0;
		while (b_index < (*stack_b)->size)
		{
			a_index = sort_prep_find_place(stack_a, b_node);
			moves = move_set_choose(stack_a, stack_b, a_index, b_index);
			if (moves < moves_min && (moves_min = moves) != 0)
				sort_save_best(stack_a, stack_b, a_index, b_index);
			b_node = b_node->next;
			b_index++;
		}
		sort_do(stack_a, stack_b);
	}
	util_align_stack(stack_a, stack_b);
}
