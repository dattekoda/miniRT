/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter_record_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:15:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCATTER_RECORDBONUS_H
# define SCATTER_RECORDBONUS_H

# include "ray_bonus.h"

/*
@param attenuation the reduction of the light's force
@param next_ray new ray for next hit()
@param surface_pdf don't know
@param sampling_pdf don't know
*/
typedef struct s_scatter_record
{
	t_color	attenuation;
	t_ray	next_ray;
	double	surface_pdf;
	double	sampling_pdf;
}			t_srec;

#endif