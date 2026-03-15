/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:27:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_BONUS_H
# define SOLUTION_BONUS_H

# include "vec_bonus.h"
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
	t_point3	point;
	t_vec3		coeff;
	double		discriminant;
	double		root_discriminant;
	double		solution;
}	t_solution;

double	calc_discriminant(const t_solution *solu);
double	calc_minus_solution(const t_solution *solu);
double	calc_plus_solution(const t_solution *solu);
bool	is_solution_inside_range(t_solution *solu, const t_range *range);

typedef struct s_cylinder_solu
{
	t_solution	solu;
	t_vec3		point;
	t_vec3		center_to_point;
	double		tmp_height;
}	t_cy_solu;

typedef struct s_triangle_solu
{
	t_solution	solu;
	t_vec3		cross[2];
	t_vec3		ver0_to_origin;
	double		det;
	double		div_det;
}	t_triangle_solu;

#endif
