#include "material.h"
#include "init_world_utils.h"
#include <stdio.h>

void	print_material(const t_material *material)
{
	if (!material)
	{
		fprintf(stderr, "material null\n");
		return ;
	}
	fprintf(stderr, "material: %s\n", g_material_specifiers[material->idx]);
}
