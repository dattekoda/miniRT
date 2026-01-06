/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:10:50 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 19:06:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <math.h>

/*
@brief return failure if it doesn't have any space
*/
int	skip_spaces(char **ptr)
{
	if (**ptr != ' ' && **ptr != '\t')
		return (FAILURE);
	while (**ptr && (**ptr == ' ' || **ptr == '\t'))
		(*ptr)++;
	return (SUCCESS);
}

int	skip_range(char **ptr, int min, int max)
{
	double	num;

	num = ft_strtod(*ptr, ptr);
	if (num < min || max < num)
		return (FAILURE);
	return (SUCCESS);
}

int	skip_vec(char **ptr, t_vectype type)
{
	size_t	i;
	double	d_tmp;
	char	*tmp_ptr;

	i = 0;
	while (i++ < 3)
	{
		tmp_ptr = *ptr;
		if (type == IS_UNIT)
			d_tmp += pow(ft_strtod(*ptr, ptr), 2);
		else
			d_tmp = ft_strtod(*ptr, ptr);
		if (tmp_ptr == *ptr)
			return (FAILURE);
		if (type == IS_COLOR && (d_tmp < 0 || 255 < d_tmp))
			return (FAILURE);
		if (i != 3 && *((*ptr)++) != ',')
			return (FAILURE);
	}
	if (type == IS_UNIT && __FLT_EPSILON__ < fabs(d_tmp - 1))
		return (FAILURE);
	return (SUCCESS);
}
