/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:20:15 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:39:10 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"
#include "libft.h"
#include <fcntl.h>

static void	config_checker_init_props(void)
{
	const char *input = properties_get(g_ch_properties, "input");
	const char *output = properties_get(g_ch_properties, "output");
	const char *verbose = properties_get(g_ch_properties, "verbose");
	const char *color = properties_get(g_ch_properties, "color");

	g_ch_input = ft_strequ_ignore_case(input, "stdin") ? 0
		: open(input, O_RDONLY);
	if (g_ch_input < 0)
	{
		ft_log_error("cannot open file", input, __func__, __FILE__);
		g_ch_input = 0;
	}
	g_ch_output = ft_strequ_ignore_case(output, "stdout") ? 1
		: open(output, O_RDWR | O_CREAT, 0006);
	if (g_ch_output < 0)
	{
		ft_log_error("cannot open file", output, __func__, __FILE__);
		g_ch_output = 1;
	}
	g_ch_verbose = ft_strequ_ignore_case(verbose, "true");
	g_ch_color = ft_strequ_ignore_case(color, "true");
}

void		config_configure_checker(void)
{
	t_properties	*properties;
	int				fd;

	fd = open(CHECKER_PROPERTIES_FILE, O_RDONLY);
	properties = properties_load(fd);
	if (!properties)
		properties = property_new_empty();
	if (!properties_get(properties, "input"))
		properties_set(&properties, "input", CHECKER_DEFAULT_INPUT);
	if (!properties_get(properties, "output"))
		properties_set(&properties, "output", CHECKER_DEFAULT_OUTPUT);
	if (!properties_get(properties, "verbose"))
		properties_set(&properties, "verbose", CHECKER_DEFAULT_VERBOSE_MODE);
	if (!properties_get(properties, "color"))
		properties_set(&properties, "color", CHECKER_DEFAULT_COLOR_MODE);
	g_ch_properties = properties;
	config_checker_init_props();
}

static void	config_push_swap_init_props(void)
{
	const char *output = properties_get(g_pw_properties, "output");
	const char *verbose = properties_get(g_pw_properties, "verbose");
	const char *color = properties_get(g_pw_properties, "color");

	g_pw_output = ft_strequ_ignore_case(output, "stdout") ? 1
		: open(output, O_RDWR | O_CREAT, 0666);
	if (g_pw_output < 0)
	{
		ft_log_error("cannot open file", output, __func__, __FILE__);
		g_pw_output = 1;
	}
	g_pw_verbose = ft_strequ_ignore_case(verbose, "true");
	g_pw_color = ft_strequ_ignore_case(color, "true");
}

void		config_configure_push_swap(void)
{
	t_properties	*properties;
	int				fd;

	fd = open(PUSH_SWAP_PROPERTIES_FILE, O_RDONLY);
	properties = properties_load(fd);
	if (!properties_get(properties, "output"))
		properties_set(&properties, "output", PUSH_SWAP_DEFAULT_OUTPUT);
	if (!properties_get(properties, "verbose"))
		properties_set(&properties, "verbose", PUSH_SWAP_DEFAULT_VERBOSE_MODE);
	if (!properties_get(properties, "color"))
		properties_set(&properties, "color", PUSH_SWAP_DEFAULT_COLOR_MODE);
	g_pw_properties = properties;
	config_push_swap_init_props();
}
