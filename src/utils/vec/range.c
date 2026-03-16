/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:41:03 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 19:38:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stdbool.h>

bool	is_inside_range(double d, const t_range *range)
{
	return (range->e[E_MIN] <= d && d <= range->e[E_MAX]);
}
