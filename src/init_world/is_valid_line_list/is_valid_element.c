/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/14 17:26:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "option.h"
#include "result.h"
#include "rt_utils.h"
#include "validate_utils.h"

static bool	is_valid_parameters(char *line, size_t *line_idx,
				const t_element *elem_info);
static bool	is_valid_material(char *line, size_t *line_idx, char *input_format);
static bool	err_invlid_line(char *line, size_t line_idx, char *format, char *err_msg);
t_result	skip_material(char *line, size_t *line_idx);
t_result	skip_texture(char *line, size_t *line_idx);

// TODO: arg, const int option_flag should bool is_phong
bool	is_valid_element(char *line, const t_element *elem_info,
		const int option_flag)
{
	t_result	result;
	size_t		line_idx;

	line_idx = 0;
	if (!is_valid_parameters(line, &line_idx, elem_info))
		return (false);
	if (option_flag & OPT_MATERIAL
		&& elem_info != &elem_info[AMBIENT]
		&& elem_info != &elem_info[CAMERA])
	{
		if (is_valid_material(line, &line_idx, elem_info->input_format) == false)
			return (false);
	}
	result = skip_until_end(line, &line_idx);
	if (result.state == FAILURE)
		return (err_invlid_line(line, elem_info->input_format, line_idx,
				result.value.err_msg));
	return (true);
}

static bool	is_valid_parameters(char *line, size_t *line_idx,
		const t_element *elem_info)
{
	t_result	result;
	size_t		func_idx;

	*line_idx = elem_info->id_len;
	func_idx = 0;
	while (elem_info->skip_arr[func_idx])
	{
		result = elem_info->skip_arr[func_idx](line, line_idx);
		if (result.state == FAILURE)
			return (err_invlid_line(line, elem_info->input_format, *line_idx,
					result.value.err_msg));
		func_idx++;
	}
	return (true);
}

static bool	is_valid_material(char *line, size_t *line_idx, char *input_format)
{
	t_result	result;

	result = skip_material(line, line_idx);
	if (result.state == FAILURE)
		return (err_invlid_line(line, *line_idx, input_format,
				result.value.err_msg));
	result = skip_texture(line, line_idx);
	if (result.state == FAILURE)
		return (err_invlid_line(line, *line_idx, input_format,
				result.value.err_msg));
	return (true);
}

static bool	err_invlid_line(char *line, size_t line_idx, char *format, char *err_msg)
{
	err_rt(format);
	err_point_out(line, line_idx);
	err_rt(err_msg);
	return (false);
}
