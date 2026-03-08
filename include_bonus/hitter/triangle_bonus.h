/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:51:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:54:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_BONUS_H
# define TRIANGLE_BONUS_H

# include "hitter_bonus.h"
# include "material_bonus.h"

typedef struct s_triangle
{
	t_hitter	hitter;
	t_vec3		normal;
	t_point3	vertex[3];
	t_vec3		edge[2];
}	t_triangle;

t_hitter	*generate_triangle(t_triangle triangle_param);

#endif
