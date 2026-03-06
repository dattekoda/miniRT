#include "ray.h"
#include "rt_debug.h"
#include <stdio.h>

void	print_ray(const t_ray *ray)
{
	fprintf(stderr, "\n");
	if (!ray)
	{
		fprintf(stderr, "ray: null\n");
		return ;
	}
	fprintf(stderr, "ray: origin\n");
	print_vec3(ray->origin);
	fprintf(stderr, "ray: direct\n");
	print_vec3(ray->direct);
}