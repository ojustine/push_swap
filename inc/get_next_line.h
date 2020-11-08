/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:10:12 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:24:38 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 512
# if (BUFF_SIZE < 1)
#  error "BUFF_SIZE must be strictly positive"
# elif (BUFF_SIZE >= INT_MAX)
#  error "BUFF_SIZE current value may cause a stack overflow"
# endif

typedef struct			s_fd_list
{
	int					fd;
	char				*line;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(int fd, char **line);

#endif
