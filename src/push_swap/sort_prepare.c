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

static int	sort_prep_check_insert(t_header **stack_a, t_node *a_node,
			t_node *b_node)
{
	const t_node *a = a_node;
	const t_node *b = b_node;

	if (a == (*stack_a)->top)
	{
		if (b->val < a->val)
			return (1);
	}
	else if ((b->val > a->prev->val && b->val < a->val)
		|| (b->val > a->prev->val && b->val > a->val && a->val < a->prev->val)
		|| (b->val < a->prev->val && b->val < a->val && a->val < a->prev->val))
		return (1);
	return (0);
}

size_t		sort_prep_find_place(t_header **stack_a, t_node *b_node)
{
	register t_node *a_node;
	register size_t	i;
	register size_t	a_node_pos;

	a_node = (*stack_a)->top;
	a_node_pos = 0;
	i = 0;
	while (i < (*stack_a)->size)
	{
		if (sort_prep_check_insert(stack_a, a_node, b_node))
			a_node_pos = i;
		a_node = a_node->next;
		i++;
	}
	return (a_node_pos);
}
