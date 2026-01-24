/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:41:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/23 15:52:25 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stdbool.h>

bool	is_inside_range(double d, const t_range *range)
{
	return (range->e[0] <= d && d <= range->e[1]);
}
