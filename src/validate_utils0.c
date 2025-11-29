/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:24:18 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/29 18:19:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "libft.h"

int	skip_spaces(char **ptr)
{
	if (**ptr != ' ' && **ptr != '\t')
		return (EXIT_FAILURE);
	while (**ptr == ' ' || **ptr == '\t')
		(*ptr)++;
	return (EXIT_SUCCESS);
}

int	skip_digit(char **ptr)
{
	if (**ptr == '-' || **ptr == '+')
		(*ptr)++;
	if (!ft_isdigit(**ptr))
		return (EXIT_FAILURE);
	while (ft_isdigit(**ptr))
		(*ptr)++;
	return (EXIT_SUCCESS);
}
