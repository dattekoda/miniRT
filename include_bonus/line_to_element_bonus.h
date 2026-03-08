/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_element_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:58:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_TO_ELEMENTBONUS_H
# define LINE_TO_ELEMENTBONUS_H

# include "hitter_bonus.h"
# include "element_bonus.h"

int	line_to_light(t_hitter **light, const char *line);
int	line_to_sphere(t_hitter **sphere, const char *line);
int	line_to_plane(t_hitter **plane, const char *line);
int	line_to_material(
		const char *line,
		size_t *line_idx,
		t_material **mat_pp,
		const t_element *element);

#endif
