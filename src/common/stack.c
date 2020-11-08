/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:38:06 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

t_header	*stack_new(void)
{
	t_header	*stack;

	stack = malloc(sizeof(t_header));
	ft_assert(stack != NULL, __FUNCTION__, "malloc error");
	ft_bzero(stack, sizeof(t_header));
	return (stack);
}

void		stack_push(t_header **stack, t_node *elem)
{
	if (stack == NULL || *stack == NULL || elem == NULL)
		return ;
	if ((*stack)->size == 0)
		(*stack)->top = elem;
	elem->next = (*stack)->top;
	elem->prev = (*stack)->top->prev;
	elem->prev->next = elem;
	elem->next->prev = elem;
	(*stack)->top = elem;
	(*stack)->size++;
}

t_node		*stack_pop(t_header **stack)
{
	t_node *elem;

	if (stack == NULL || *stack == NULL)
	{
		ft_log_error("Null pointer", "(*)stack is NULL", __func__, __FILE__);
		return (NULL);
	}
	if ((*stack)->size == 0)
		return (NULL);
	elem = (*stack)->top;
	(*stack)->top = ((*stack)->size > 1) ? elem->next : NULL;
	(*stack)->size--;
	elem->next->prev = elem->prev;
	elem->prev->next = elem->next;
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

void		stack_add(t_header **stack, int data)
{
	t_node	*elem;

	if (stack == NULL || *stack == NULL)
	{
		ft_log_error("Null pointer", "(*)stack is NULL", __func__, __FILE__);
		return ;
	}
	elem = malloc(sizeof(t_node));
	ft_assert(elem != NULL, __FUNCTION__, "malloc error");
	ft_bzero(elem, sizeof(t_node));
	elem->val = data;
	if ((*stack)->size == 0)
	{
		elem->next = elem;
		elem->prev = elem;
		(*stack)->top = elem;
	}
	stack_push(stack, elem);
}

void		stack_clear(t_header *stack)
{
	t_node *elem;

	if (!stack)
		return ;
	while (stack->size--)
	{
		elem = stack->top;
		stack->top = stack->top->next;
		free(elem);
	}
	free(stack);
}
