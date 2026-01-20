/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:52:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/20 16:40:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_H
# define LAMBERTIAN_H

#include "material.h"

typedef struct s_lambertian
{
	t_material	material;
}	t_lambertian;

t_lambertian	*generate_lambertian(t_texture *texture_ptr);

#endif
