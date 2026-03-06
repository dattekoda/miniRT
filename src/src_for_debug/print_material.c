#include "material_define.h"
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
