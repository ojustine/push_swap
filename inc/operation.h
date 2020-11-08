/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:25:57 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPERATION_H
# define PUSH_SWAP_OPERATION_H

# include "stack.h"

void	operation_swap(t_header **stack_1, t_header **stack_2);
void	operation_push(t_header **stack_src, t_header **stack_dst);
void	operation_rotate(t_header **stack_1, t_header **stack_2, int reversed);
int		operation_exec(char *op, t_header **stack_a, t_header **stack_b);

#endif
