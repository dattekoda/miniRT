/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:05:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 01:20:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"
#include <unistd.h>

void	err_point_out(char *line, size_t err_idx);

int	validate_element(char *line, const t_element_info elem_info)
{
	t_result	result;
	size_t		i;
	size_t		func_idx;

	i = elem_info.id_len;
	func_idx = 0;
	while (elem_info.skip_arr[func_idx])
	{
		result = elem_info.skip_arr[func_idx](line, &i);
		if (result.state == FAILURE)
		{
			ft_putendl_fd(elem_info.format, STDERR_FILENO);
			err_point_out(line, i);
			ft_putendl_fd(result.value.err_msg, STDERR_FILENO);
			return (1);
		}
		func_idx++;
	}
	return (0);
}
