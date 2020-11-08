/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:40:47 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "libft.h"

static void	printer_print_elem(int fd, t_header *stack, int only_spaces)
{
	char		buff[14];
	long long	num;
	size_t		i;

	i = 0;
	buff[i++] = '|';
	buff[i++] = ' ';
	if (!only_spaces && stack->size)
	{
		num = stack->top->val;
		if (num < 0)
		{
			buff[i++] = '-';
			num = -num;
		}
		i += ft_ultoa_base(num, &buff[i], 10, 0);
	}
	while (i < 14)
		buff[i++] = ' ';
	printer_print(fd, buff, 14);
}

void		printer_print_stacks(int fd, int color, t_header *stack_a,
			t_header *stack_b)
{
	register size_t	i;

	i = 0;
	printer_print(fd, "+------A------+------B------+\n", 30);
	while (i < stack_a->size || i < stack_b->size)
	{
		if (!(i & 1U) && color)
			printer_print(fd, REV_COLOR, -1);
		printer_print_elem(fd, stack_a, i >= stack_a->size);
		printer_print_elem(fd, stack_b, i >= stack_b->size);
		printer_print(fd, "|", 1);
		if (!(i & 1U) && color)
			printer_print(fd, RESET_REV_COLOR, -1);
		printer_print(fd, "\n", 1);
		if (stack_a->size)
			stack_a->top = stack_a->top->next;
		if (stack_b->size)
			stack_b->top = stack_b->top->next;
		i++;
	}
	printer_print(fd, "+-------------+-------------+\n", 30);
	printer_flush(fd);
}

void		printer_flush(int fd)
{
	printer_print(fd, NULL, 0);
}

void		printer_print(int fd, char *data, ssize_t data_size)
{
	static char			buff[BUFF_SIZE + 1];
	static size_t		buff_index;
	register size_t		data_index;
	register size_t		free_space;
	register size_t		size;

	if (data == NULL)
	{
		write(fd, buff, buff_index);
		buff_index = 0;
		return ;
	}
	data_index = 0;
	size = (data_size < 0) ? ft_strlen(data) : data_size;
	while ((free_space = BUFF_SIZE - buff_index) < size)
	{
		ft_memcpy(&(buff[buff_index]), &(data[data_index]), free_space);
		size -= free_space;
		data_index += free_space;
		buff_index += free_space;
		write(fd, buff, buff_index);
		buff_index = 0;
	}
	ft_memcpy(&(buff[buff_index]), &(data[data_index]), size);
	buff_index += size;
}
