/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:41:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:31:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_bonus.h"
#include <stdbool.h>

bool	is_inside_range(double d, const t_range *range)
{
	return (range->e[0] <= d && d <= range->e[1]);
}

bool	is_outside_range(double d, const t_range *range)
{
	return (d < range->e[0] || range->e[1] < d);
}
