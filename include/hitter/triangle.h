/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:51:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 19:46:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "hitter.h"
# include "material.h"

typedef struct s_triangle
{
	t_hitter	hitter;
	t_vec3		normal;
	t_point3	vertex[3];
	t_vec3		edge[2];
}	t_triangle;

t_hitter	*generate_triangle(t_triangle triangle_param);

#endif
