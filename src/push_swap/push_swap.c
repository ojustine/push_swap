/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/11/07 12:02:14 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "printer.h"
#include "parser.h"
#include "libft.h"

static void	push_swap_close(t_header *stack_a, t_header *stack_b, int err_code)
{
	stack_clear(stack_a);
	stack_clear(stack_b);
	printer_flush(g_pw_output);
	properties_destroy(g_pw_properties);
	if (g_pw_output > 2)
		close(g_pw_output);
	if (err_code)
	{
		write(2, "Error\n", 6);
		exit(err_code);
	}
}

static void	push_swap_init(int argc, char **argv, t_header **stack_a,
			t_header **stack_b)
{
	config_configure_push_swap();
	*stack_a = stack_new();
	*stack_b = stack_new();
	if (!parser_parse_numbers(stack_a, argv, argc))
		push_swap_close(*stack_a, *stack_b, 1);
	if (!parser_check_duplicates(*stack_a))
		push_swap_close(*stack_a, *stack_b, 1);
}

int			main(int argc, char **argv)
{
	t_header	*stack_a;
	t_header	*stack_b;

	if (argc == 1)
		return (0);
	push_swap_init(argc, argv, &stack_a, &stack_b);
	ft_assert(stack_a && stack_b, __func__, "null pointer");
	if (g_pw_verbose)
		printer_print_stacks(g_pw_output, g_pw_color, stack_a, stack_b);
	sort_main_loop(&stack_a, &stack_b);
	push_swap_close(stack_a, stack_b, 0);
	return (0);
}
