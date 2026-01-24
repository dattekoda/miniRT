/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:30:51 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/23 16:56:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include <math.h>

/*
@brief discriminant = b * b - a * c
*/
double	calc_discriminant(const t_solution *solu)
{
	return (pow(solu->b, 2) - solu->a * solu->c);
}

/*
@brief (-b - sqrt (D) ) / a
*/
double	calc_minus_solution(const t_solution *solu)
{
	return ((-solu->b - solu->root_discriminant) / solu->a);
}

/*
@brief (-b + sqrt (D) ) / a
*/
double	calc_plus_solution(const t_solution *solu)
{
	return ((-solu->b + solu->root_discriminant) / solu->a);
}
