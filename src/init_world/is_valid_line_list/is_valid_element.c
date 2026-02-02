/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/02 18:08:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"
#include "option.h"
#include "result.h"
#include "rt_utils.h"
#include "validate_utils.h"
#include "line_reader.h"

static bool	is_valid_parameters(t_line_reader *line_reader,
									const t_element *elem_info);
static bool	is_valid_material(t_line_reader *line_reader, char *input_format);
static bool	err_invlid_line(t_line_reader *line_reader, char *format, char *err_msg);
t_result	skip_material(t_line_reader *line_reader);
t_result	skip_texture(t_line_reader *line_reader);

bool	is_valid_element(char *line, const t_element *elem_info,
		const int option_flag)
{
	t_result		result;
	t_line_reader	line_reader;

	line_reader = construct_line_reader(line);
	if (!is_valid_parameters(&line_reader, elem_info))
		return (false);
	if (option_flag & OPT_MATERIAL)
	{
		if (is_valid_material(&line_reader, elem_info->input_format) == false)
			return (false);
	}
	result = skip_until_end(&line_reader);
	if (result.state == FAILURE)
		return (err_invlid_line(&line_reader, elem_info->input_format, 
				result.value.err_msg));
	return (true);
}

static bool	is_valid_parameters(t_line_reader *line_reader,
		const t_element *elem_info)
{
	t_result	result;
	size_t		func_idx;

	line_reader->idx = elem_info->id_len;
	func_idx = 0;
	while (elem_info->skip_arr[func_idx])
	{
		result = elem_info->skip_arr[func_idx](line_reader);
		if (result.state == FAILURE)
			return (err_invlid_line(line_reader, elem_info->input_format,
					result.value.err_msg));
		func_idx++;
	}
	return (true);
}

static bool	is_valid_material(t_line_reader *line_reader, char *input_format)
{
	t_result	result;

	result = skip_material(line_reader);
	if (result.state == FAILURE)
		return (err_invlid_line(line_reader, input_format,
				result.value.err_msg));
	result = skip_texture(line_reader);
	if (result.state == FAILURE)
		return (err_invlid_line(line_reader, input_format,
				result.value.err_msg));
	return (true);
}

static bool	err_invlid_line(t_line_reader *line_reader, char *format, char *err_msg)
{
	err_rt(format);
	err_point_out(line_reader);
	err_rt(err_msg);
	return (false);
}
