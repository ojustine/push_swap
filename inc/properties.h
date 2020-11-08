/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:25:33 by ojustine          #+#    #+#             */
/*   Updated: 2020/08/14 18:27:14 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROPERTIES_H
# define PROPERTIES_H

# define DELIMITER '='
# define COMMENT '#'

typedef struct			s_properties
{
	char				*key;
	char				*value;
	struct s_properties	*next;
}						t_properties;

void					properties_destroy(t_properties *properties);
t_properties			*properties_load(int fd);
char					*properties_get(t_properties *properties, char *key);
void					properties_set(t_properties **properties, char *key,
						char *value);
void					properties_delete(t_properties **properties, char *key);
t_properties			*property_new_resolve_line(char *line);
t_properties			*property_new_key_val(char *key, char *value);
t_properties			*property_new_empty(void);

#endif
