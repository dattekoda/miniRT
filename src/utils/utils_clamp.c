/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:20:49 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/08 21:23:58 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (min);
	return (x);
}
