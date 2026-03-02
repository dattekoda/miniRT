/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder_disk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:12:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/02 18:49:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "disk.h"
#include "libft.h"
#include "result.h"
#include "vec_utils.h"
#include <stdlib.h>

static int		cylinder_to_lower_disk(t_cylinder cylinder, t_disk *lower_disk);
static int		cylinder_to_upper_disk(t_cylinder cylinder, t_disk *upper_disk);
static int		add_disk(t_list **hitter_list, t_disk disk);

int	add_cylinder_disk(t_list **hitter_list, t_cylinder *cylinder)
{
	t_disk		upper_disk;
	t_disk		lower_disk;

	if (cylinder_to_upper_disk(*cylinder, &upper_disk) == FAILURE)
		return (FAILURE);
	if (add_disk(hitter_list, upper_disk) == FAILURE)
		return (FAILURE);
	if (cylinder_to_lower_disk(*cylinder, &lower_disk) == FAILURE)
		return (FAILURE);
	if (add_disk(hitter_list, lower_disk) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	add_disk(t_list **hitter_list, t_disk disk_param)
{
	t_list	*tmp_list;
	t_disk	*tmp_disk;

	tmp_disk = (t_disk *)generate_disk(disk_param);
	if (!tmp_disk)
		return (FAILURE);
	tmp_list = ft_lstnew(tmp_disk);
	if (!tmp_list)
	{
		tmp_disk->hitter.clear(tmp_disk);
		free(tmp_disk);
		return (FAILURE);
	}
	ft_lstadd_back(hitter_list, tmp_list);
	return (SUCCESS);
}

static int	cylinder_to_upper_disk(t_cylinder cylinder, t_disk *upper_disk)
{
	ft_bzero(upper_disk, sizeof(t_disk));
	upper_disk->center
		= add_vec3(
			cylinder.center,
			scal_mul_vec3(
				cylinder.direct,
				cylinder.height));
	upper_disk->normal = cylinder.direct;
	upper_disk->radius = cylinder.radius;
	upper_disk->hitter.mat_ptr
		= clone_material(cylinder.hitter.mat_ptr);
	if (!upper_disk->hitter.mat_ptr)
		return (FAILURE);
	return (SUCCESS);
}

static int	cylinder_to_lower_disk(t_cylinder cylinder, t_disk *lower_disk)
{
	ft_bzero(lower_disk, sizeof(t_disk));
	lower_disk->center = cylinder.center;
	lower_disk->normal = negative_vec3(cylinder.direct);
	lower_disk->radius = cylinder.radius;
	lower_disk->hitter.mat_ptr
		= clone_material(cylinder.hitter.mat_ptr);
	if (!lower_disk->hitter.mat_ptr)
		return (FAILURE);
	return (SUCCESS);
}
