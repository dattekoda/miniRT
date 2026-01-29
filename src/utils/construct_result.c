/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:02:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/21 15:15:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "libft.h"

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
