/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:30:51 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/20 21:16:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include <math.h>

/*
@brief discriminant = b * b - a * c
*/
double	calc_discriminant(t_abc abc)
{
	return (pow(abc.e[1], 2) - abc.e[0] * abc.e[2]);
}

/*
@brief (-b - sqrt (D) ) / a
*/
double	calc_minus_solution(t_solution solu)
{
	return ((-solu.abc.e[1] - solu.root_discriminant) / solu.abc.e[0]);
}

/*
@brief (-b + sqrt (D) ) / a
*/
double	calc_plus_solution(t_solution solu)
{
	return ((-solu.abc.e[1] + solu.root_discriminant) / solu.abc.e[0]);
}
