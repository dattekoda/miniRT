/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:30:07 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/15 21:33:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIELECTRIC_H
# define DIELECTRIC_H

# include "material.h"

/*
@param refract_idx 
*/
typedef struct s_dielectric
{
	t_material	material;
	double		refract_idx;
}	t_dielectric;

#endif