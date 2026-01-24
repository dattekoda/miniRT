/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 22:33:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include <stdint.h>

static uint64_t	random_uint64(void);

/*
@brief ランダムな53bitを取り出し仮数部とする。
*/
double	random_double(double min, double max)
{
	uint64_t	u;
	double		v;

	u = random_uint64() >> 11;
	v = (double)u / (double)DOUBLE_MANTISSA_SCALE;
	return (min + (max - min) * v);
}

static uint64_t	random_uint64(void)
{
	static uint64_t	x = RANDOM_SEED_UINT64;

	x ^= x << 12;
	x ^= x >> 25;
	x ^= x << 27;
	return (x);
}

int	random_int(int min, int max)
{
	if (min > max)
		return (min);
	int	range = max - min + 1;
	return (min + (int)(random_double(0.0, 1.0) * range));
}
