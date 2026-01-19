/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:27:21 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 21:36:11 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include "vec.h"

typedef struct s_solution
{
	t_abc	abc;
	double	discriminant;
	double	root;
	double	solution;
}	t_solution;

double	calc_discriminant(t_abc abc);
double	calc_first_solution(t_solution solu);
double	calc_second_solution(t_solution solu);

#endif
