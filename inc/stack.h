/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:26:33 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <string.h>

typedef struct			s_node
{
	int					val;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct			s_header
{
	t_node				*top;
	size_t				size;
	size_t				move_set;
	size_t				sort_index;
}						t_header;

t_header				*stack_new();
void					stack_push(t_header **stack, t_node *elem);
t_node					*stack_pop(t_header **stack);
void					stack_add(t_header **stack, int data);
void					stack_clear(t_header *stack);
#endif
