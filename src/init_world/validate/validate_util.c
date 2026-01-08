/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:10:50 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 18:54:20 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <math.h>
#include <float.h>
#include <stdbool.h>

static int		skip_value(char *line, size_t *i_ptr, t_vectype type, double *d);
static double	i_ptr_strtod(const char *line, size_t *i_ptr);
static int		validate_value(t_vectype type, const double d);
static int		validate_unit_vec(const double *d3);

void	skip_spaces(char *line, size_t *i_ptr)
{
	while (line[*i_ptr] && (line[*i_ptr] == ' ' || line[*i_ptr] == '\t'))
		(*i_ptr)++;
	return ;
}
/*
@brief return failure if it doesn't have any space
@param f if NULL, no err msg
*/
int	skip_spaces_with_err_msg(char *line, size_t *i_ptr)
{
	if (line[*i_ptr] != ' ' && line[*i_ptr] != '\t')
	{
		err_rt();
		err_spaces();
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	skip_spaces(line, i_ptr);
	return (SUCCESS);
}

int	skip_range(const char *line, size_t *i_ptr, double min, double max)
{
	size_t	head_i;
	double	num;

	head_i = *i_ptr;
	num = i_ptr_strtod(line, i_ptr);
	if (isnan(num) || isinf(num) || num < min || max < num)
	{
		*i_ptr = head_i;
		return (FAILURE);
	}
	return (SUCCESS);
}

int	skip_vec(char *line, size_t *i_ptr, t_vectype type)
{
	size_t	head_idx;
	size_t	d_idx;
	double	d3[3];

	head_idx = *i_ptr;
	d_idx = 0;
	ft_bzero(d3, sizeof(double) * 3);
	while (d_idx < 3)
	{
		if (skip_value(line, i_ptr, type, d3 + d_idx) == FAILURE)
			return (FAILURE);
		if (d_idx != 2)
			skip_spaces(line, i_ptr);
		if (d_idx != 2 && line[(*i_ptr)++] != ',')
			return (FAILURE);
		d_idx++;
	}
	if (type == IS_UNIT && validate_unit_vec(d3) == FAILURE)
	{
		*i_ptr = head_idx;
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_value(char *line, size_t *i_ptr, t_vectype type, double *d)
{
	size_t	head_idx;

	head_idx = *i_ptr;
	*d = i_ptr_strtod(line, i_ptr);
	if (validate_value(type, *d) == FAILURE)
	{
		*i_ptr = head_idx;
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	validate_value(t_vectype type, const double d)
{
	if (isnan(d) || isinf(d))
		return (FAILURE);
	if (type == IS_COLOR && (d < 0.0 || 255.0 < d))
		return (FAILURE);
	return (SUCCESS);
}

static int	validate_unit_vec(const double *d3)
{
	double	sum;
	size_t	i;

	sum = 0;
	i = 0;
	while (i < 3)
		sum += pow(d3[i++], 2);
	if (fabs(sum - 1) >= NORMALIZE_EPSILON)
		return (FAILURE);
	return (SUCCESS);
}

/*
@brief if not number return NAN
*/
static double	i_ptr_strtod(const char *line, size_t *i_ptr)
{
	double		d_tmp;
	char		*endptr;
	const char	*read_head;

	read_head = line + *i_ptr;
	d_tmp = ft_strtod(read_head, &endptr);
	if (read_head == endptr)
		return (NAN);
	(*i_ptr) += (endptr - read_head);
	return (d_tmp);
}