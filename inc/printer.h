/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:26:19 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <string.h>
# include "stack.h"

# define BUFF_SIZE 512
# if defined(__MACH__)
#  define REV_COLOR			"\e[7m"
#  define RESET_REV_COLOR	"\e[27m"
# else
#  define REV_COLOR			""
#  define RESET_REV_COLOR	""
# endif

void	printer_print(int fd, char *data, ssize_t data_size);
void	printer_flush(int fd);
void	printer_print_stacks(int fd, int color, t_header *stack_a,
		t_header *stack_b);

#endif
