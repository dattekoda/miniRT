/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder_disk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:12:55 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/27 23:35:19 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "disk.h"
#include "libft.h"
#include "result.h"
#include "vec_utils.h"

static t_disk	cylinder_to_upper_disk(t_cylinder cylinder);
static t_disk	cylinder_to_lower_disk(t_cylinder cylinder);
static int		add_disk(t_list **hitter_list, t_disk disk);

int	add_cylinder_disk(t_list **hitter_list, t_cylinder *cylinder)
{
	t_material	*mat_ptr;
	t_disk		upper_disk;
	t_disk		lower_disk;

	mat_ptr = cylinder->hitter.mat_ptr
	upper_disk = cylinder_to_upper_disk(*cylinder);
	if (add_disk(hitter_list, upper_disk) == FAILURE)
		return (FAILURE);
	lower_disk = cylinder_to_lower_disk(*cylinder);
	if (add_disk(hitter_list, lower_disk) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static t_texture	*dup_texture(t_texture src)
{
	t_texture	*p;
	
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
		return (tmp_disk->hitter.clear(tmp_disk), FAILURE);
	ft_lstadd_back(hitter_list, tmp_list);
	return (SUCCESS);
}

static t_disk	cylinder_to_lower_disk(t_cylinder cylinder)
{
	t_disk		disk_param;
	t_texture	*texture_p;

	ft_bzero(&disk_param, sizeof(t_disk));
	disk_param.center = cylinder.center;
	disk_param.normal = negative_vec3(cylinder.direct);
	disk_param.radius = cylinder.radius;
	disk_param.hitter.mat_ptr = cylinder.hitter.mat_ptr;
	return (disk_param);
}

static t_disk	cylinder_to_upper_disk(t_cylinder cylinder)
{
	t_disk		disk_param;
	t_texture	*texture_p;

	ft_bzero(&disk_param, sizeof(t_disk));
	disk_param.center = add_vec3(cylinder.center, scal_mul_vec3(cylinder.direct,
				cylinder.height));
	disk_param.normal = cylinder.direct;
	disk_param.radius = cylinder.radius;
	disk_param.hitter.mat_ptr = cylinder.hitter.mat_ptr;
	return (disk_param);
}
