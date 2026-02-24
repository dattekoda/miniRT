#include "hitter.h"
#include <stdio.h>

void	print_vec3(t_vec3 v);

void	print_aabb(t_aabb aabb)
{
	fprintf(stderr, "min:\t");
	print_vec3(aabb.min);
	fprintf(stderr, "max:\t");
	print_vec3(aabb.max);
	fprintf(stderr, "centroid:\t");
	print_vec3(aabb.centroid);
	return ;
}
