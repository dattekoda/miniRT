/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bump_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:03:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 17:56:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bump_texture.h"
#include "rt_utils.h"
#include "libft.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>

extern t_color ((*const	g_local_normal[])(t_vec2 map));

static t_bump_texture	construct_bump_texture(t_color color);
static t_color			calc_bump_texture_value(const void *s, t_hrec *hrec);

t_texture	*generate_bump_texture(t_color color)
{
	t_bump_texture	*p;

	p = ft_calloc(1, sizeof(t_bump_texture));
	if (!p)
		return (NULL);
	*p = construct_bump_texture(color);
	return ((t_texture *)p);
}

static t_bump_texture	construct_bump_texture(t_color color)
{
	t_bump_texture	bump;

	bump.texture.calc_texture_value = calc_bump_texture_value;
	bump.texture.size = sizeof(t_bump_texture);
	bump.local_normal = g_local_normal[BUMP_TYPE];
	bump.color = color;
	return (bump);
}

static t_color	calc_bump_texture_value(const void *s, t_hrec *hrec)
{
	const t_bump_texture	*self = s;
	const t_onb				onb = construct_onb(hrec->normal);
	const t_vec3			normalized_local_normal
		= normalize_vec3(self->local_normal(hrec->map));

	hrec->normal = local_onb(onb, normalized_local_normal);
	return (self->color);
}
