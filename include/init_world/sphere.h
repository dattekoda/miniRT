/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:33:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 19:36:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "hitter.h"

typedef struct s_sphere
{
	t_hitter	hitter;
	t_point3	center;
	double		radius;
}	t_sphere;

t_sphere	*gen_sphere(t_sphere_param *param);

#endif
