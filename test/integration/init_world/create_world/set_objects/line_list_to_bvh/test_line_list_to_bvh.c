/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_list_to_bvh.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:33:29 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 17:19:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_utils.h"
#include "libft.h"
#include "element.h"
#include "vec_utils.h"
#include "rt_define.h"
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int			test_line_list_to_hit_arr(void);
int			test_hit_arr_to_bvh(void);

int			line_list_to_bvh(t_hitter **node, const t_list *line_list, const t_element *element_table[]);
static int	test_self(void);
static int	set_line_list(t_list **line_list, const char *z_value_arr[]);
static int	test_node_hit(t_hitter *node);

int	test_line_list_to_bvh(void)
{
	test_line_list_to_hit_arr();
	test_hit_arr_to_bvh();
	test_self();
	return (0);
}

static int	test_self(void)
{
	t_hitter	*node;
	t_list		*line_list;
	const char	*z_value_arr[] = {"20", "50", "30", "10", "40", NULL};

	set_line_list(&line_list, z_value_arr);
	line_list_to_bvh(&node, line_list, g_finite_table);
	test_node_hit(node);
	ft_lstclear(&line_list, free);
	return (0);
}

static char	*get_z_value_line(const char *z_value)
{
	static const char	*line_1 = "sp 0,0,";
	static const char	*line_2 = " 1 0,0,0";
	static const size_t	line_1_len = 7;
	static const size_t	line_2_len = 8;
	char				*line;
	size_t				line_len;

	line_len = line_1_len + ft_strlen(z_value) + line_2_len + 1;
	line = ft_calloc(line_len, sizeof(char));
	ft_strlcpy(line, line_1, line_len);
	ft_strlcat(line, z_value, line_len);
	ft_strlcat(line, line_2, line_len);
	return (line);
}

/*
@brief add sphere line that has 1 diameter and (0,0,z_value) center
*/
static void	add_z_value_line(t_list **line_list, const char *z_value)
{
	ft_lstadd_back(line_list, ft_lstnew(get_z_value_line(z_value)));
}

static int	set_line_list(t_list **line_list, const char *z_value_arr[])
{
	size_t	i;

	i = 0;
	*line_list = NULL;
	while (z_value_arr[i])
		add_z_value_line(line_list, z_value_arr[i++]);
	return (0);
}

/*
@brief check i has 
*/
static bool	hit_origin_to_point(t_hitter *node, t_vec3 origin, t_vec3 point)
{
	t_range	range = construct_vec2(HIT_T_MIN, length_vec3(sub_vec3(point, origin)));
	t_hrec	hrec;
	t_ray	ray = construct_ray(origin, normalize(sub_vec3(point, origin)));

	return (node->hit(node, &ray, &hrec, &range));
}

static int	test_node_hit(t_hitter *node)
{
	assert(hit_origin_to_point(node, construct_vec3(0,0,0), construct_vec3(0,0,1)) == false);
	assert(hit_origin_to_point(node, construct_vec3(50,50,35), construct_vec3(0,0,35)) == false);

	assert(hit_origin_to_point(node, construct_vec3(50,50,35), construct_vec3(0,0,30)) == false);
	assert(hit_origin_to_point(node, construct_vec3(50,50,30), construct_vec3(0,0,30)) == true);
	return (0);
}
