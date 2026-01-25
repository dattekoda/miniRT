/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/25 03:24:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "validate_utils.h"
#include "rt_utils.h"
#include "element.h"
#include "result.h"

static bool	is_valid_parameters
	(char *line, size_t *i_ptr, const t_element *elem_info);
static bool	is_valid_material
	(char *line, size_t *i_ptr, char *input_format);
static bool	err_invlid_line(char *line, char *format, size_t i, char *err_msg);
t_result	skip_material(char *line, size_t *line_idx);
t_result	skip_texture(char *line, size_t *line_idx);

bool	is_valid_element
	(char *line, const t_element *elem_info, const int option_flag)
{
	t_result	result;
	size_t		i;

	i = 0;
	if (!is_valid_parameters(line, &i, elem_info))
		return (false);
	if (option_flag & OPT_MATERIAL)
	{
		if (is_valid_material(line, &i, elem_info->input_format) == false)
			return (false);
	}
	result = skip_until_end(line, &i);
	if (result.state == FAILURE)
		return (err_invlid_line
			(line, elem_info->input_format, i, result.value.err_msg));
	return (true);
}

static bool	is_valid_parameters(char *line, size_t *i_ptr, const t_element *elem_info)
{
	t_result	result;
	size_t		func_idx;

	*i_ptr = elem_info->id_len;
	func_idx = 0;
	while (elem_info->skip_arr[func_idx])
	{
		result = elem_info->skip_arr[func_idx](line, i_ptr);
		if (result.state == FAILURE)
			return (err_invlid_line
				(line, elem_info->input_format, *i_ptr, result.value.err_msg));
		func_idx++;
	}
	return (true);
}

static bool	is_valid_material
	(char *line, size_t *i_ptr, char *input_format)
{
	t_result	result;

	result = skip_material(line, i_ptr);
	if (result.state == FAILURE)
		return (err_invlid_line
			(line, input_format, *i_ptr, result.value.err_msg));
	result = skip_texture(line, i_ptr);
	if (result.state == FAILURE)
		return (err_invlid_line
			(line, input_format, *i_ptr, result.value.err_msg));
	return (true);
}

static bool	err_invlid_line(char *line, char *format, size_t i, char *err_msg)
{
	err_rt(format);
	err_point_out(line, i);
	err_rt(err_msg);
	return (false);
}
