/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:40:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/17 23:45:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "hitter.h"

typedef struct s_disk
{
	t_hitter	hitter;
	t_point3	center;
	t_vec3		normal;
	double		radius;
}

t_disk	*gen_disk(t_disk disk_param, t_material *mat_ptr);

#endif
