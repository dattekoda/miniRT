/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:22:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 01:13:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_WORLD_DEFINE_H
# define INIT_WORLD_DEFINE_H

# include <stddef.h>

typedef enum e_element_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	DISK,
	CONE,
	TRIANGLE,
	NOTHING
}	t_element_type;

#endif