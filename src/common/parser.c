/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/11/07 11:07:18 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	parser_check_num(char *num)
{
	const long	nb = ft_atol(num);

	if (*num == '-' || *num == '+')
		num++;
	if (*num == '\0' || (*num == '0' && *(num + 1) != '\0'))
		return (0);
	if (ft_strlen(num) > 10)
		return (0);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	if (nb < -2147483648L || nb > 2147483647L)
		return (0);
	return (1);
}

static int	parser_parse_string(t_header **stack, char *str)
{
	char			**tab;
	int				success;
	register size_t i;

	tab = ft_strsplit(str, ' ');
	if (!tab)
		return (0);
	success = 1;
	i = 0;
	while (tab[i])
		i++;
	while (i--)
	{
		if (success && parser_check_num(tab[i]))
			stack_add(stack, ft_atoi(tab[i]));
		else if (success)
			success = 0;
		free(tab[i]);
	}
	free(tab);
	return (success);
}

int			parser_check_duplicates(t_header *stack)
{
	register t_node	*outer;
	register t_node	*inner;
	register size_t	i;
	register size_t	j;

	if (!stack)
		return (0);
	outer = stack->top;
	i = stack->size;
	while (i--)
	{
		j = i;
		inner = outer;
		while (j--)
		{
			inner = inner->next;
			if (outer->val == inner->val)
				return (0);
		}
		outer = outer->next;
	}
	return (1);
}

int			parser_parse_numbers(t_header **stack, char **argv, int argc)
{
	register	size_t	i;

	if (!stack)
		return (0);
	i = argc;
	if (i == 2)
		return (parser_parse_string(stack, argv[1]));
	else
		while (--i)
		{
			if (!parser_check_num(argv[i]))
				return (0);
			stack_add(stack, ft_atoi(argv[i]));
		}
	return (1);
}
