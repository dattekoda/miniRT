/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 11:56:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_H
# define HITTER_H

# include "aabb.h"
# include "element_type.h"
# include "hit_record.h"
# include "rt_utils.h"
# include <stdbool.h>

typedef bool				(*t_hit)(const void *self, const t_ray *ray,
	t_hrec *hrec, t_range *range);

typedef struct s_hitter
{
	t_hit			hit;
	t_clear			clear;
	bool			has_aabb;
	t_aabb			aabb;
	t_material		*mat_ptr;
	t_element_type	type;
}	t_hitter;

#endif
