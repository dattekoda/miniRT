/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:56:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 14:59:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include <math.h>
#include <stdbool.h>

bool	fequal(double a, double b)
{
	return (fabs(a - b) < FLT_EPSILON);
}
