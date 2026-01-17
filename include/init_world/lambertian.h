/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:52:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 16:59:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_H
# define LAMBERTIAN_H

#include "material.h"

typedef struct s_lambertian
{
	t_material	material;
}	t_lambertian;

t_lambertian	*gen_lambertian(t_texture *texture_p);

#endif
