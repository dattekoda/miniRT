/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:24:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 15:16:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "libft.h"

int	skip_spaces(char **ptr)
{
	if (**ptr != ' ' && **ptr != '\t')
		return (MINIRT_FAILURE);
	while (**ptr == ' ' || **ptr == '\t')
		(*ptr)++;
	return (MINIRT_SUCCESS);
}

int	skip_digit(char **ptr)
{
	if (**ptr == '-' || **ptr == '+')
		(*ptr)++;
	if (!ft_isdigit(**ptr))
		return (MINIRT_FAILURE);
	while (ft_isdigit(**ptr))
		(*ptr)++;
	return (MINIRT_SUCCESS);
}