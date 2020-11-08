/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:36:03 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:36:05 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "properties.h"
#include "libft.h"
#include "get_next_line.h"

void				properties_destroy(t_properties *properties)
{
	register t_properties *property;

	while (properties)
	{
		property = properties;
		properties = properties->next;
		free(property->key);
		free(property->value);
		free(property);
	}
}

t_properties		*properties_load(const int fd)
{
	char					*line;
	register t_properties	*head;
	register t_properties	*property;

	if (fd < 0)
		return (NULL);
	head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		property = property_new_resolve_line(line);
		if (property && properties_get(head, property->key))
		{
			ft_log_error("property: duplicate, counts only the first entry",
			property->key, __func__, __FILE__);
			free(property);
		}
		else if (property)
		{
			property->next = head;
			head = property;
		}
		free(line);
	}
	return (head);
}

char				*properties_get(t_properties *properties, char *key)
{
	while (properties)
	{
		if (ft_strequ(properties->key, key))
			return (properties->value);
		properties = properties->next;
	}
	return (NULL);
}

void				properties_set(t_properties **properties, char *key,
					char *value)
{
	register t_properties	*property;
	register t_properties	*prev;

	if (!properties)
		return ;
	if (!*properties)
	{
		*properties = property_new_key_val(key, value);
		return ;
	}
	property = *properties;
	while (property)
	{
		if (ft_strequ(property->key, key))
		{
			free(property->value);
			property->value = ft_strdup(value);
			return ;
		}
		prev = property;
		property = property->next;
	}
	prev->next = property_new_key_val(key, value);
}

void				properties_delete(t_properties **properties, char *key)
{
	register t_properties	*this;
	register t_properties	*prev;

	this = *properties;
	prev = *properties;
	if (ft_strequ(this->key, key))
		*properties = this->next;
	else
		while (1)
		{
			prev = this;
			this = this->next;
			if (ft_strequ(this->key, key))
				break ;
			if (!this->next)
				return ;
		}
	prev->next = this->next;
	free(this->key);
	free(this->value);
	free(this);
}
