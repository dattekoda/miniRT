/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:40:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 18:18:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "hitter.h"
# include "material.h"

typedef struct s_disk
{
	t_hitter	hitter;
	t_point3	center;
	t_vec3		normal;
	double		radius;
}	t_disk;

t_hitter	*generate_disk(t_disk disk_param);

#endif
