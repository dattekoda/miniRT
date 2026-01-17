/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:40:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/17 19:08:15 by ikawamuk         ###   ########.fr       */
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

#endif
