/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:49:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:54:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_BONUS_H
# define SPLIT_BONUS_H

# include "axis_bonus.h"
# include <stddef.h>

/*
@brief structure to find best split info
*/
typedef struct s_split
{
	t_axis	axis;
	double	cost;
	size_t	left_size;
}	t_split;

t_split	construct_split(
			t_axis axis,
			size_t left_size,
			double cost);

#endif