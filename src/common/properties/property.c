/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:35:33 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:35:56 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "properties.h"
#include "libft.h"

static void		*property_error(const char *mess, const char *cause,
				const char *func, const char *file)
{
	ft_log_error(mess, cause, func, file);
	return (NULL);
}

t_properties	*property_new_empty(void)
{
	t_properties	*property;

	property = malloc(sizeof(t_properties));
	ft_assert(property != NULL, __FUNCTION__, "malloc error");
	ft_bzero(property, sizeof(t_properties));
	return (property);
}

t_properties	*property_new_resolve_line(char *line)
{
	char			*delimiter_ptr;
	char			*value_ptr;
	t_properties	*property;

	if (!line || !*line || *line == COMMENT)
		return (NULL);
	if (*line == '=')
		return (property_error("property: no key", line, __func__, __FILE__));
	delimiter_ptr = ft_strchr(line, DELIMITER);
	if (!delimiter_ptr)
		return (property_error("property: no delim", line, __func__, __FILE__));
	value_ptr = delimiter_ptr + 1;
	if (!*value_ptr)
		return (property_error("property: no val", line, __func__, __FILE__));
	property = property_new_empty();
	property->key = ft_strndup(line, delimiter_ptr - line);
	property->value = ft_strdup(value_ptr);
	return (property);
}

t_properties	*property_new_key_val(char *key, char *value)
{
	t_properties	*property;

	if (!key || !*key)
		return (property_error("property: no key", NULL, __func__, __FILE__));
	if (!value || !*value)
		return (property_error("property: no val", NULL, __func__, __FILE__));
	property = property_new_empty();
	property->key = ft_strdup(key);
	property->value = ft_strdup(value);
	return (property);
}
