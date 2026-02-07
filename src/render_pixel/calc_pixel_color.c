/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:51:41 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/07 21:54:13 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "vec_utils.h"
#include "libft.h"
#include "rt_define.h"
#include "option.h"
#include "rt_utils.h"

t_ray			get_ray_from_camera(
					const t_camera *camera,
					double u,
					double v);
t_color			get_path_tracing_color(
					t_ray ray,
					const t_world *world,
					size_t depth);
static t_color	calc_a_sample_pixel_color(
					int xi,
					int yi,
					const t_world *world,
					int option_flag);
static void		calc_uv(double *u, double *v, int xi, int yi);

t_color	calc_pixel_color(
					int xi,
					int yi,
					const t_world *world,
					int option_flag)
{
	static const double	color_scale = 1.0 / SAMPLES_PER_PIXEL;
	size_t				si;
	t_color				pixel_color;

	ft_bzero(&pixel_color, sizeof(t_color));
	si = 0;
	while (si < SAMPLES_PER_PIXEL)
	{
		pixel_color
			= add_vec3(
				pixel_color,
				calc_a_sample_pixel_color(xi, yi, world, option_flag));
		si++;
	}
	return (scal_mul_vec3(pixel_color, color_scale));
}

static t_color	calc_a_sample_pixel_color(
					int xi,
					int yi,
					const t_world *world,
					int option_flag)
{
	t_ray	ray;
	double	u;
	double	v;

	calc_uv(&u, &v, xi, yi);
	ray = get_ray_from_camera(&world->camera, u, v);
	if (option_flag & OPT_ARTIFICIAL)
		return (get_phong_color());
	return (get_path_tracing_color(ray, world, 0));
}

static void	calc_uv(double *u, double *v, int xi, int yi)
{
	static const double	inv_w = 1.0 / (WINDOW_WIDTH - 1);
	static const double	inv_h = 1.0 / (WINDOW_WIDTH * ASPECT_RATIO - 1);
	
	*u = xi + random_double(0, 1) * inv_w;
	*v = yi + random_double(0, 1) * inv_h;
	return ;
}
