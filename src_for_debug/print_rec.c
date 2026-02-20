/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:11:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 20:20:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include <stdio.h>

void	print_ray(const t_ray *ray);
void	print_vec3(t_vec3 v);
void	print_vec2(t_vec2 m);
void	print_material(const t_material *material);

void	print_hrec(const t_hrec *hrec)
{
	printf("ray in: ");
	print_ray(&hrec->ray_in);
	printf("point: ");
	print_vec3(hrec->point);
	printf("param_t: %f\n", hrec->param_t);
	printf("normal: ");
	print_vec3(hrec->normal);
	printf("map: ");
	print_vec2(hrec->map);
	print_material(hrec->mat_ptr);
}

void	print_srec(const t_srec *srec)
{
	printf("attenuation: ");
	print_vec3(srec->attenuation);
	printf("next ray: ");
	print_ray(&srec->next_ray);
}
