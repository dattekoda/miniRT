/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:27:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/30 13:55:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include "vec.h"
# include <stdbool.h>

/*
@param center_to_origin the vector 
	from the point of the object to Incident ray origin
@param point the point of intersection (hit point)
@param a,b,c the coefficients of equation
@param coeff coefficient of equation
@param discriminant of equation: the D
@param root_discriminant ;for avoiding redundant calculations
@param solution the solution of equation: hit ray parameter
*/
typedef struct s_solution
{
	// t_vec3		center_to_origin;
	// t_point3	point;
	// double		a;
	// double		b;
	// double		c;
	t_vec3		coeff;
	double		discriminant;
	double		root_discriminant;
	double		solution;
}	t_solution;

double	calc_discriminant(const t_solution *solu);
double	calc_minus_solution(const t_solution *solu);
double	calc_plus_solution(const t_solution *solu);
bool	is_solution_in_range(t_solution *solu, t_range *range);

#endif
