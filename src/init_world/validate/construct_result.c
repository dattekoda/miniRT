/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:02:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:58:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"

void	err_point_out(char *line, size_t err_idx);

t_result	construct_result(char *_err_msg)
{
	t_result	result;

	ft_bzero(&result, sizeof(t_result));
	if (_err_msg == NULL)
	{
		result.state = SUCCESS;
		result.value.ok = 0;
		return (result);
	}
	result.state = FAILURE;
	result.value.err_msg = _err_msg;
	return (result);
}
