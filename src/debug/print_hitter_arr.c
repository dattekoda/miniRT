#include "hitter_arr.h"
#include <stdio.h>

void	print_hitter(const t_hitter *hitter);

void	print_hitter_arr(const t_hitter_arr *hit_arr)
{
	fprintf(stderr, "--- hitter_arr ---\n");
	fprintf(stderr, "size:\t%zu\n", hit_arr->size);
	fprintf(stderr, "arr:\n");
	for (size_t i = 0; i < hit_arr->size; i++) {
		print_hitter(hit_arr->arr[i]);
	}
	fprintf(stderr, "left:\t");
	for (size_t i = 0; i < hit_arr->size; i++) {
		fprintf(stderr, "%.2f", hit_arr->left_surface_arr[i]);
		if (i != hit_arr->size - 1)
			fprintf(stderr, ", ");
	}
	fprintf(stderr, "\nright:\t");
	for (size_t i = 0; i < hit_arr->size; i++) {
		fprintf(stderr, "%.2f", hit_arr->right_surface_arr[i]);
		if (i != hit_arr->size - 1)
			fprintf(stderr, ", ");
	}
	fprintf(stderr, "\n");
}