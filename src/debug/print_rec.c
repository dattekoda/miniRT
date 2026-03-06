/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:11:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/20 22:12:10 by ikawamuk         ###   ########.fr       */
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
	fprintf(stderr, "ray in: ");
	print_ray(&hrec->ray_in);
	fprintf(stderr, "point: ");
	print_vec3(hrec->point);
	fprintf(stderr, "param_t: %f\n", hrec->param_t);
	fprintf(stderr, "normal: ");
	print_vec3(hrec->normal);
	fprintf(stderr, "map: ");
	print_vec2(hrec->map);
	print_material(hrec->mat_ptr);
}

void	print_srec(const t_srec *srec)
{
	fprintf(stderr, "attenuation: ");
	print_vec3(srec->attenuation);
	fprintf(stderr, "next ray: ");
	print_ray(&srec->next_ray);
}
