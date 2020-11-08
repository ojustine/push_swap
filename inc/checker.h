/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 19:00:50 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "properties.h"

# define CHECKER_PROPERTIES_FILE "checker.properties"
# define CHECKER_DEFAULT_INPUT "stdin"
# define CHECKER_DEFAULT_OUTPUT "stdout"
# define CHECKER_DEFAULT_VERBOSE_MODE "false"
# define CHECKER_DEFAULT_COLOR_MODE "false"

t_properties	*g_ch_properties;
int				g_ch_output;
int				g_ch_input;
int				g_ch_verbose;
int				g_ch_color;

void			config_configure_checker();

#endif
