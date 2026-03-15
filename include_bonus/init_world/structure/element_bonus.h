/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:27:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_BONUS_H
# define ELEMENT_BONUS_H

# include "skip_bonus.h"
# include "hitter_bonus.h"
# include "element_type_bonus.h"
# include "material_bonus.h"
# include "texture_bonus.h"

typedef struct s_element
{
	char			*id;
	size_t			id_len;
	char			*input_format;
	const t_skip	*skip_arr;
	int				(*line_to_hitter)(
			t_hitter **hitter, const char *line);
	t_material_idx	material_idx;
	t_texture_idx	texture_idx;
	bool			has_sub_hitter;
}	t_element;

#endif
