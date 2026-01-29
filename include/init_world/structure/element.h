/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:27:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 15:21:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "skip.h"
# include "hitter.h"

typedef struct s_element
{
	char			*id;
	size_t			id_len;
	char			*input_format;
	const t_skip	*skip_arr;
	int				(*line_to_hitter)(t_hitter **hitter, const char *line);
	int				material_idx;
	int				texture_idx;
}	t_element;

#endif
