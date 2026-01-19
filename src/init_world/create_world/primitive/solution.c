/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:30:51 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 21:40:11 by khanadat         ###   ########.fr       */
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
@brief (-b - root(discriminant)) / a
*/
double	calc_first_solution(t_solution solu)
{
	return ((-solu.abc.e[1] - solu.root) / solu.abc.e[0]);
}

/*
@brief (-b + root(discriminant)) / a
*/
double	calc_second_solution(t_solution solu)
{
	return ((-solu.abc.e[1] + solu.root) / solu.abc.e[0]);
}
