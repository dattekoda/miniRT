/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder_disk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:12:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/17 23:45:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "cylinder.h"
#include "disk.h"
#include "libft.h"

static t_disk	cylinder_to_upper_disk(t_cylinder cylinder);
static t_disk	cylinder_to_lower_disk(t_cylinder cylinder)
static t_disk	cylinder_to_disk(t_cylinder cylinder, bool is_upper);

int	add_cylinder_disk(t_list **hitter_list, t_cylinder cylinder)
{
	t_disk	upper_disk;
	t_disk	lower_disk;

	upper_disk = cylinder_to_upper_disk(cylinder);
	lower_disk = cylinder_to_lower_disk(cylinder);
	if (add_disk(hitter_list, upper_disk) == FAILURE)
		return (FAILURE);
	if (add_disk(hitter_list, lower_disk) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	add_disk(t_list **hitter_list, t_disk disk)
{
	t_list		*list_tmp;
	t_hitter	*disk_tmp;

	disk_tmp = cylinder_to_disk(cylinder, is_upper);
	if (!disk_tmp)
		return (FAILURE);
	list_tmp = ft_lstnew(list_tmp);
	if (!list_tmp)
		return (disk_tmp->clear(disk_tmp), FAILURE);
	ft_lstadd_back(hitter_list, list_tmp);
	return (SUCCESS);
}

static t_disk	cylinder_to_lower_disk(t_cylinder cylinder, bool is_upper)
{
	t_disk	disk_param;

	disk_param.center = cylinder.center;
	disk_param.normal = negative_vec3(disk_param.normal);
	disk_param.radius = cylinder.radius;
	return (disk_param);
}

static t_disk	cylinder_to_upper_disk(t_cylinder cylinder)
{
	t_disk	disk_param;

	disk_param.center = add_vec3(
		cylinder.center, scal_mul_vec3(cylinder.height, cylinder.normal));
	disk_param.normal = cylinder.direct;
	disk_param.radius = cylinder.radius;
	return (disk_param);
}