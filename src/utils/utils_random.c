/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 16:30:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

static uint64_t	random_uint64(void);
static uint64_t	get_random_seed_from_time(void);

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

int	random_int(int min, int max)
{
	int	range;

	if (min > max)
		return (min);
	range = max - min + 1;
	return (min + (int)(random_double(0.0, 1.0) * range));
}

size_t	random_size_t(size_t min, size_t max)
{
	if (min > max)
		return (min);
	return (min + (size_t)(random_double(0.0, 1.0) * (max - min + 1)));
}

static uint64_t	random_uint64(void)
{
	static uint64_t	x = 0;

	if (x == 0)
		x = get_random_seed_from_time();
	x ^= x << 12;
	x ^= x >> 25;
	x ^= x << 27;
	return (x);
}

static uint64_t	get_random_seed_from_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (RANDOM_SEED_UINT64);
	return ((uint64_t)((tv.tv_sec ^ tv.tv_usec) * RANDOM_SEED_UINT64));
}
