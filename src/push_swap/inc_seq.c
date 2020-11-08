/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/11/07 11:34:48 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "operation.h"
#include "printer.h"

static void		inc_seq_find(t_header *stack, int *seq_lens, int *ancients)
{
	const ssize_t		stack_size = stack->size;
	register ssize_t	left_i;
	register ssize_t	right_i;
	register t_node		*left;
	register t_node		*right;

	right_i = -1;
	right = stack->top;
	while (++right_i < stack_size)
	{
		seq_lens[right_i] = 1;
		ancients[right_i] = -1;
		left_i = -1;
		left = stack->top;
		while (++left_i < right_i)
		{
			if (left->val < right->val && seq_lens[left_i] >= seq_lens[right_i])
			{
				seq_lens[right_i] = seq_lens[left_i] + 1;
				ancients[right_i] = left_i;
			}
			left = left->next;
		}
		right = right->next;
	}
}

static size_t	inc_seq_mark(t_header *stack, int *seq_lens, const int *ancs)
{
	register size_t	i;
	register size_t	sorted;
	register int	*marks;
	register int	seq_len;
	int				end_of_seq_i;

	i = 0;
	end_of_seq_i = -1;
	seq_len = seq_lens[0];
	while (++i < stack->size)
		if (seq_lens[i] > seq_len)
		{
			seq_len = seq_lens[i];
			end_of_seq_i = i;
		}
	sorted = 0;
	marks = seq_lens;
	ft_bzero(marks, sizeof(int) * stack->size);
	while (end_of_seq_i != -1)
	{
		marks[end_of_seq_i] = 1;
		end_of_seq_i = ancs[end_of_seq_i];
		sorted++;
	}
	return (sorted);
}

static void		inc_seq_drop_unsorted(t_header **stack_a, t_header **stack_b,
				const int *marks, size_t sorted)
{
	register size_t	index;
	register size_t	unsorted;
	const size_t	stack_start_size = (*stack_a)->size;

	index = 0;
	unsorted = stack_start_size - sorted;
	while (index < stack_start_size && unsorted > 0 && (*stack_a)->size > 3)
	{
		if (marks[index] == 1)
			util_repeat_operation_loud("ra", stack_a, stack_b, 1);
		else
		{
			util_repeat_operation_loud("pb", stack_a, stack_b, 1);
			unsorted--;
		}
		index++;
	}
	if (unsorted > 0)
		sort_3(stack_a, stack_b);
}

void			inc_seq_process(t_header **stack_a, t_header **stack_b)
{
	const size_t	size_a = (stack_a && *stack_a) ? (*stack_a)->size : 0;
	int				tab[size_a];
	int				ancients[size_a];
	size_t			sorted;

	ft_assert(stack_a && *stack_a && stack_b && *stack_b, __func__, "null ptr");
	inc_seq_find(*stack_a, tab, ancients);
	sorted = inc_seq_mark(*stack_a, tab, ancients);
	inc_seq_drop_unsorted(stack_a, stack_b, tab, sorted);
}
