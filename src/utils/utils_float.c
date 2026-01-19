/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:56:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 20:23:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <stdbool.h>

bool	fequal(double a, double b)
{
	return (fabs(a - b) < FLT_EPSILON);
}
