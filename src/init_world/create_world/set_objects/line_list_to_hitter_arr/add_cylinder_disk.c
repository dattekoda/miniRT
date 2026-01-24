/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder_disk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:12:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 18:19:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "cylinder.h"
#include "disk.h"
#include "vec_utils.h"
#include "libft.h"

static t_disk	cylinder_to_upper_disk(t_cylinder cylinder);
static t_disk	cylinder_to_lower_disk(t_cylinder cylinder);
static int		add_disk(t_list **hitter_list, t_disk disk);

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

static int	add_disk(t_list **hitter_list, t_disk disk_param)
{
	t_list		*tmp_list;
	t_disk		*tmp_disk;

	tmp_disk = generate_disk(disk_param);
	if (!tmp_disk)
		return (FAILURE);
	tmp_list = ft_lstnew(tmp_disk);
	if (!tmp_list)
		return (tmp_disk->hitter.clear(tmp_disk), FAILURE);
	ft_lstadd_back(hitter_list, tmp_list);
	return (SUCCESS);
}

static t_disk	cylinder_to_lower_disk(t_cylinder cylinder)
{
	t_disk	disk_param;

	disk_param.center = cylinder.center;
	disk_param.normal = negative_vec3(cylinder.direct);
	disk_param.radius = cylinder.radius;
	disk_param.hitter.mat_ptr = cylinder.hitter.mat_ptr;
	return (disk_param);
}

static t_disk	cylinder_to_upper_disk(t_cylinder cylinder)
{
	t_disk	disk_param;

	disk_param.center = add_vec3(
		cylinder.center, scal_mul_vec3(cylinder.direct, cylinder.height));
	disk_param.normal = cylinder.direct;
	disk_param.radius = cylinder.radius;
	disk_param.hitter.mat_ptr = cylinder.hitter.mat_ptr;
	return (disk_param);
}
