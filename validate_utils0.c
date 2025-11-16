/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:24:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 14:25:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "libft.h"

int	skip_spaces(char **line)
{
	if (**line != ' ' && **line != '\t')
		return (MINIRT_FAILURE);
	while (**line == ' ' || **line == '\t')
		(*line)++;
	return (MINIRT_SUCCESS);
}

int	skip_digit(char **line)
{
	if (**line == '-' || **line == '+')
		(*line)++;
	if (!ft_isdigit(**line))
		return (MINIRT_FAILURE);
	while (ft_isdigit(**line))
		(*line)++;
	return (MINIRT_SUCCESS);
}