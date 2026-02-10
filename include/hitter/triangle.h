/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:51:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/07 19:52:53 by ikawamuk         ###   ########.fr       */
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
	t_vec3		side[3];
}	t_triangle;

t_hitter	*generate_triangle(t_triangle triangle_param);

#endif

