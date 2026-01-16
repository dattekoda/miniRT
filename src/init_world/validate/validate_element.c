/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/16 16:47:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "rt_utils.h"
#include "element.h"

int	validate_element(char *line, const t_element *elem_info)
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
			err_rt(elem_info->format);
			err_point_out(line, i);
			err_rt(result.value.err_msg);
			return (FAILURE);
		}
		func_idx++;
	}
	return (SUCCESS);
}
