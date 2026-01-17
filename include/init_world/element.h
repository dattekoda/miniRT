/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:27:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 18:52:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "result.h"
# include "skip.h"
# include <stddef.h>

// typedef enum e_element_type
// {
// 	NOTHING,
// 	AMBIENT,
// 	CAMERA,
// 	LIGHT,
// 	SPHERE,
// 	PLANE,
// 	CYLINDER,
// 	CONE,
// 	TRIANGLE
// }	t_element_type;

typedef struct s_element
{
	char			*id;
	size_t			id_len;
	char			*format;
	const t_skip	*skip_arr;
	int				is_infinite;
	int				(*line_to_hitter_node)(void *hitter, const char *line);
	size_t			texture_id;
	size_t			material_id;
}	t_element;

#endif
