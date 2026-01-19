/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:31:35 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 20:23:57 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vec.h"

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		direct;
	double		radius;
	double		height;
}	t_cylinder;

#endif
