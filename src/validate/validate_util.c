/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:10:50 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/07 18:29:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <math.h>
#include <float.h>

static double	i_ptr_strtod(const char *line, size_t *i_ptr);

/*
@brief return failure if it doesn't have any space
@param f if NULL, no err msg
*/
int	skip_spaces_with_err_msg(const char *line, size_t *i_ptr)
{
	if (line[*i_ptr] != ' ' && line[*i_ptr] != '\t')
	{
		err_rt();
		err_spaces();
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	while (line[*i_ptr] && (line[*i_ptr] == ' ' || line[*i_ptr] == '\t'))
		(*i_ptr)++;
	return (SUCCESS);
}

int	skip_range(const char *line, size_t *i_ptr, double min, double max)
{
	double	num;

	num = i_ptr_strtod(line, i_ptr);
	if (isnan(num) || isinf(num) || num < min || max < num)
		return (FAILURE);
	return (SUCCESS);
}

int	skip_vec(const char *line, size_t *i_ptr, t_vectype type)
{
	size_t	d_idx;
	double	d3[3];

	d_idx = 0;
	ft_bzero(d3, sizeof(double) * 3);
	while (d_idx < 3)
	{
		d3[d_idx++] = i_ptr_strtod(line, i_ptr);
		if (d_idx != 3 && line[*(i_ptr)++] != ',')
			return (FAILURE);
	}
	return (is_valid_vec(type, d3));
}

static int	is_valid_vec(t_vectype type, const double *d3)
{
	size_t	d_idx;
	double	sum;

	d_idx = 0;
	sum = 0;
	while (d_idx < 3)
	{
		if (isnan(d3[d_idx]) || isinf(d3[d_idx]))
			return (FAILURE);
		if (type == IS_COLOR)
			if (d3[d_idx] < 0.0 || 255.0 < d3[d_idx])
				return (FAILURE);
		sum += pow(d3[d_idx], 2);
		d_idx++;
	}
	if (type == IS_UNIT)
		if (fabs(sum - 1) >= FLT_EPSILON)
			return (FAILURE);
	return (SUCCESS);
}

/*
@brief if not number return NAN
*/
static double	i_ptr_strtod(const char *line, size_t *i_ptr)
{
	double	d_tmp;
	char	*endptr;

	d_tmp = ft_strtod(line, &endptr);
	if (line == endptr)
		return (NAN);
	(*i_ptr) += (endptr - line);
	return (d_tmp);
}
