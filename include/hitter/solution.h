/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:27:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/23 16:57:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include "vec.h"

typedef struct s_solution
{
	t_vec3		center_to_origin;
	t_point3	point;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		root_discriminant;
	double		solution;
}	t_solution;

double	calc_discriminant(const t_solution *solu);
double	calc_minus_solution(const t_solution *solu);
double	calc_plus_solution(const t_solution *solu);

#endif
