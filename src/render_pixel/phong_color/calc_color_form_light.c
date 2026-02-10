/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color_form_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:05:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/10 20:27:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_config.h"
#include "hitter.h"
#include "vec_utils.h"
#include "libft.h"

t_color	calc_color_from_light(const t_list *light_list,
			const t_color *reflectance, const t_hrec *hrec)
{
	t_color	diffuse;
	t_color	specular;

	ft_bzero(&diffuse, sizeof(t_color));
	ft_bzero(&specular, sizeof(t_color));
	while (light_list)
	{
		if (hits_light())
		{
			diffuse = add_vec3(diffuse, calc_diffuse(reflectance, hrec));
			specular = add_vec3(specular, calc_specular(hrec));
		}
		light_list = light_list->next;
	}
	return (add_vec3(diffuse, specular));
}

static t_color	calc_specular(const t_hrec *hrec)
{
	const t_color	ks = constant_vec3(PHONG_SPECULAR_COEFF);
	// ks * pow(max((R dot V), 0), alpha) * light_in_color
}

static t_color	calc_diffuse(const t_color *reflectance, const t_hrec *hrec)
{
	const t_color	kd = scal_mul_vec3(*reflectance, PHONG_DIFFUSE_COEFF);

	// kd * max((L dot N), 0) * light_in_color
}
