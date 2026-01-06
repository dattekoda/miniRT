/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:10:50 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 23:29:03 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <math.h>

static double	i_ptr_strtod(char *line, size_t *i_ptr);

/*
@brief return failure if it doesn't have any space
@param f if NULL, no err msg
*/
int	skip_spaces(char *line, size_t *i, void (*err_func)(void))
{
	if (**ptr != ' ' && **ptr != '\t' && err_func)
		return (err_spaces(err_func), FAILURE);
	while (**ptr && (**ptr == ' ' || **ptr == '\t'))
		(*ptr)++;
	return (SUCCESS);
}

int	skip_range(char **ptr, double min, double max)
{
	double	num;

	num = ft_strtod(*ptr, ptr);
	if (num < min || max < num)
		return (FAILURE);
	return (SUCCESS);
}

int	skip_vec(char *line, size_t *i_ptr, t_vectype type)
{
	size_t	i;
	size_t	tmp_i_ptr;
	double	d_tmp;

	i = 0;
	d_tmp = 0;
	while (i++ < 3)
	{
		tmp_i_ptr = (*i_ptr);
		if (type == IS_UNIT)
			d_tmp += pow(i_ptr_strtod(line, i_ptr), 2);
		else
			d_tmp = i_ptr_strtod(line, i_ptr);
		if (tmp_i_ptr == (*i_ptr))
			return (FAILURE);
		if (type == IS_COLOR && (d_tmp < 0 || 255 < d_tmp))
			return (FAILURE);
		if (i != 3 && line[*(i_ptr)++] != ',')
			return (FAILURE);
	}
	if (type == IS_UNIT && __FLT_EPSILON__ < fabs(d_tmp - 1))
		return (FAILURE);
	return (SUCCESS);
}

static double	i_ptr_strtod(char *line, size_t *i_ptr)
{
	double	d_tmp;
	char	*endptr;

	d_tmp = ft_strtod(line, &endptr);
	(*i_ptr) += (endptr - line);
	return (d_tmp);
}
