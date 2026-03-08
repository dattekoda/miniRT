/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:40:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKBONUS_H
# define DISKBONUS_H

# include "hitter_bonus.h"
# include "material_bonus.h"

typedef struct s_disk
{
	t_hitter	hitter;
	t_point3	center;
	t_vec3		normal;
	double		radius;
}	t_disk;

t_hitter	*generate_disk(t_disk disk_param);

#endif
