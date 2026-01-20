/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:27:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/20 21:16:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include "vec.h"

typedef struct s_solution
{
	t_abc	abc;
	double	discriminant;
	double	root_discriminant;
	double	solution;
}	t_solution;

double	calc_discriminant(t_abc abc);
double	calc_minus_solution(t_solution solu);
double	calc_plus_solution(t_solution solu);

#endif
