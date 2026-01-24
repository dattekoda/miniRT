/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 16:37:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "rt_utils.h"
#include "element.h"

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
		{
			err_rt(elem_info->input_format);
			err_point_out(line, i);
			err_rt(result.value.err_msg);
			return (FAILURE);
		}
		func_idx++;
	}
	if ()
	return (SUCCESS);
}
