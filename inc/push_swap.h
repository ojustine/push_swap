/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 19:00:59 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "properties.h"
# include "stack.h"

# define PUSH_SWAP_PROPERTIES_FILE "push_swap.properties"
# define PUSH_SWAP_DEFAULT_OUTPUT "stdout"
# define PUSH_SWAP_DEFAULT_VERBOSE_MODE "false"
# define PUSH_SWAP_DEFAULT_COLOR_MODE "false"

t_properties	*g_pw_properties;
int				g_pw_output;
int				g_pw_verbose;
int				g_pw_color;

enum			e_move_set
{
	UP_UP,
	DOWN_DOWN,
	UP_DOWN,
	DOWN_UP
};

void		config_configure_push_swap();
void		sort_main_loop(t_header **stack_a, t_header **stack_b);
void		inc_seq_process(t_header **stack_a, t_header **stack_b);
size_t		sort_prep_find_place(t_header **stack_a, t_node *b_node);
size_t		move_set_choose(t_header **stack_a, t_header **stack_b,
			size_t a_index, size_t b_index);
void		sort_do(t_header **stack_a, t_header **stack_b);
void		util_repeat_operation_loud(char *op, t_header **stack_a,
			t_header **stack_b, size_t count);
void		sort_3(t_header **stack_a, t_header **stack_b);
void		util_align_stack(t_header **stack_a, t_header **stack_b);

#endif
