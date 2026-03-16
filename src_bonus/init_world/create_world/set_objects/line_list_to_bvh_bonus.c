/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list_to_bvh_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:13:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define_bonus.h"
#include "element_bonus.h"
#include "hitter_arr_bonus.h"
#include "libft.h"
#include <stdlib.h>

bool			has_object_in_line_list(
					const t_list *line_list,
					const t_element *object_table[]);
t_hitter		*generate_hitter_list(
					const t_list *line_list,
					const t_element *object_table[]);
int				line_list_to_hit_arr(
					t_hitter_arr *hit_arr,
					const t_list *line_list,
					const t_element *object_table[]);
int				hit_arr_to_bvh(t_hitter **root, t_hitter_arr hit_arr);
static int		line_list_to_bvh(
					t_hitter **node,
					const t_list *line_list,
					const t_element *object_table[]);
static int		alloc_surface_arr(t_hitter_arr *hit_arr);
static void		clear_hitter_arr(t_hitter_arr *hit_arr);

int	finite_line_list_to_bvh(t_hitter **node, const t_list *line_list)
{
	*node = NULL;
	if (!has_object_in_line_list(line_list, g_finite_table))
		return (SUCCESS);
	return (line_list_to_bvh(node, line_list, g_finite_table));
}

int	infinite_line_list_to_hitter_list(t_hitter **node, const t_list *line_list)
{
	*node = NULL;
	if (!has_object_in_line_list(line_list, g_infinite_table))
		return (SUCCESS);
	*node = generate_hitter_list(line_list, g_infinite_table);
	if (!*node)
		return (FAILURE);
	return (SUCCESS);
}

static int	line_list_to_bvh(
		t_hitter **node,
		const t_list *line_list,
		const t_element *object_table[])
{
	t_hitter_arr	hit_arr;

	ft_bzero(&hit_arr, sizeof(t_hitter_arr));
	if (line_list_to_hit_arr(&hit_arr, line_list, object_table) == FAILURE)
		return (FAILURE);
	if (alloc_surface_arr(&hit_arr) == FAILURE)
	{
		clear_hitter_arr(&hit_arr);
		return (FAILURE);
	}
	if (hit_arr_to_bvh(node, hit_arr) == FAILURE)
	{
		clear_hitter_arr(&hit_arr);
		return (FAILURE);
	}
	free(hit_arr.arr);
	free(hit_arr.left_surface_arr);
	free(hit_arr.right_surface_arr);
	return (SUCCESS);
}

static int	alloc_surface_arr(t_hitter_arr *hit_arr)
{
	if (hit_arr->size == 0)
		return (SUCCESS);
	hit_arr->left_surface_arr = ft_calloc(hit_arr->size, sizeof(double));
	if (!hit_arr->left_surface_arr)
		return (FAILURE);
	hit_arr->right_surface_arr = ft_calloc(hit_arr->size, sizeof(double));
	if (!hit_arr->right_surface_arr)
		return (FAILURE);
	return (SUCCESS);
}

static void	clear_hitter_arr(t_hitter_arr *hit_arr)
{
	size_t	i;

	i = 0;
	while (i < hit_arr->size)
	{
		hit_arr->arr[i]->clear(hit_arr->arr[i]);
		free(hit_arr->arr[i]);
		i++;
	}
	free(hit_arr->arr);
	free(hit_arr->left_surface_arr);
	free(hit_arr->right_surface_arr);
}
