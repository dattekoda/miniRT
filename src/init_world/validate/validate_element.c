/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 18:41:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_utils.h"
#include "rt_utils.h"
#include "element.h"
#include "result.h"

static int	err_invlid_line(char *line, char *format, size_t i, char *err_msg);
t_result	skip_material(const char *line, size_t *line_idx);
t_result	skip_texture(const char *line, size_t *line_idx);

bool	is_valid_element(char *line, const t_element *elem_info, int option_flag)
{
	t_result	result;
	size_t		i;
	size_t		func_idx;

	i = elem_info->id_len;
	func_idx = 0;
	while (elem_info->skip_arr[func_idx])
	{
		result = elem_info->skip_arr[func_idx](line, &i);
		if (result.state == FAILURE)
			return (err_invlid_line(line, elem_info->input_format, i, result.value.err_msg));
		func_idx++;
	}
	if (option_flag & OPT_MATERIAL)
	{
		result = skip_texture(line, i);
		if (result.state == FAILURE)
			return (err_invlid_line(line, elem_info->input_format, i, result.value.err_msg));
		result = skip_texture(line, i);
		if (result.state == FAILURE)
			return (err_invlid_line(line, elem_info->input_format, i, result.value.err_msg));
	}
	return (SUCCESS);
}

static int	err_invlid_line(char *line, char *format, size_t i, char *err_msg)
{
	err_rt(format);
	err_point_out(line, i);
	err_rt(err_msg);
	return (FAILURE);
}
