/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:27:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/04 19:59:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "skip.h"
# include "hitter.h"
# include "element_type.h"
# include "material.h"
# include "texture.h"

typedef struct s_element
{
	char			*id;
	size_t			id_len;
	char			*input_format;
	const t_skip	*skip_arr;
	int				(*line_to_hitter)
			(t_hitter **hitter, const char *line);
	t_material_idx	material_idx;
	t_texture_idx	texture_idx;
	bool			has_sub_hitter;
}	t_element;

#endif
