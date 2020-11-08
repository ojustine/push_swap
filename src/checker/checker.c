/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:34:06 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "stack.h"
#include "printer.h"
#include "parser.h"
#include "get_next_line.h"
#include "operation.h"

static int	checker_is_sort(t_header *stack)
{
	t_node			*elem;
	register int	prev_val;
	register size_t	i;

	if (!stack || stack->size == 0)
		return (0);
	if (stack->size == 1)
		return (1);
	i = stack->size;
	elem = stack->top;
	while (--i)
	{
		prev_val = elem->val;
		elem = elem->next;
		if (prev_val > elem->val)
			return (0);
	}
	return (1);
}

static void	checker_close(t_header *stack_a, t_header *stack_b, int err_code)
{
	stack_clear(stack_a);
	stack_clear(stack_b);
	printer_flush(g_ch_output);
	properties_destroy(g_ch_properties);
	if (g_ch_output > 2)
		close(g_ch_output);
	if (g_ch_input > 2)
		close(g_ch_input);
	if (err_code)
	{
		write(2, "Error\n", 6);
		exit(err_code);
	}
}

static void	checker_init(int argc, char **argv, t_header **stack_a,
			t_header **stack_b)
{
	config_configure_checker();
	*stack_a = stack_new();
	*stack_b = stack_new();
	if (!parser_parse_numbers(stack_a, argv, argc))
		checker_close(*stack_a, *stack_b, 1);
	if (!parser_check_duplicates(*stack_a))
		checker_close(*stack_a, *stack_b, 1);
}

void		checker_loop(t_header *stack_a, t_header *stack_b)
{
	int		reads_result;
	char	*instruction;

	while ((reads_result = get_next_line(g_ch_input, &instruction)) > 0)
	{
		if (*instruction == '\0')
			break ;
		if (!operation_exec(instruction, &stack_a, &stack_b))
			checker_close(stack_a, stack_b, 1);
		if (g_ch_verbose)
			printer_print_stacks(g_ch_output, g_ch_color, stack_a, stack_b);
		free(instruction);
	}
	if (reads_result == -1)
		checker_close(stack_a, stack_b, 1);
}

int			main(int argc, char **argv)
{
	t_header	*stack_a;
	t_header	*stack_b;

	if (argc == 1)
		return (0);
	checker_init(argc, argv, &stack_a, &stack_b);
	if (g_ch_verbose)
		printer_print_stacks(g_ch_output, g_ch_color, stack_a, stack_b);
	checker_loop(stack_a, stack_b);
	if (stack_b->size == 0 && checker_is_sort(stack_a))
		printer_print(g_ch_output, "OK\n", 3);
	else
		printer_print(g_ch_output, "KO\n", 3);
	checker_close(stack_a, stack_b, 0);
	return (0);
}
