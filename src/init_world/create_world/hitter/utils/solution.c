/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:30:51 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/30 13:59:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "vec_utils.h"
#include <math.h>
#include <stdbool.h>

/*
@brief discriminant = b * b - a * c
*/
double	calc_discriminant(const t_solution *solu)
{
	return (pow(solu->coeff.e[1], 2) - solu->coeff.e[0] * solu->coeff.e[2]);
}

/*
@brief (-b - sqrt (D) ) / a
*/
double	calc_minus_solution(const t_solution *solu)
{
	return ((-solu->coeff.e[1] - solu->root_discriminant) / solu->coeff.e[0]);
}

/*
@brief (-b + sqrt (D) ) / a
*/
double	calc_plus_solution(const t_solution *solu)
{
	return ((-solu->coeff.e[1] + solu->root_discriminant) / solu->coeff.e[0]);
}

bool	is_solution_in_range(t_solution *solu, t_range *range)
{
	if (solu->discriminant < 0)
		return (false);
	solu->root_discriminant = sqrt(solu->discriminant);
	solu->solution = calc_minus_solution(solu);
	if (is_inside_range(solu->solution, range) == true)
		return (true);
	solu->solution = calc_plus_solution(solu);
	if (is_inside_range(solu->solution, range) == true)
		return (true);
	return (false);
}
