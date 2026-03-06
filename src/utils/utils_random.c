/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/06 18:43:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <stdint.h>
#include <stddef.h>
#include <sys/time.h>

static uint64_t	random_uint64(void);
static uint64_t	g_x;

/*
@brief let randomized 53 bits as a mantissa
*/
double	random_double(double min, double max)
{
	const uint64_t	u = (random_uint64() >> 11);
	const double	d = (double)u * DOUBLE_INV_SCALE;

	return (min + (max - min) * d);
}

double	random_01(void)
{
	const union u_rand_double	rand_d = {
		.u = random_uint64() >> 12 | 0x3FF0000000000000ULL
	};

	return (rand_d.d - 1.0);
}

double	random_minus1_to_1(void)
{
	const union u_rand_double	rand_d = {
		.u = random_uint64() >> 12 | 0x4000000000000000ULL
	};

	return (rand_d.d - 3.0);
}

static uint64_t	random_uint64(void)
{
	g_x ^= g_x << 12;
	g_x ^= g_x >> 25;
	g_x ^= g_x << 27;
	return (g_x);
}

void	set_random_seed_from_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		g_x = RANDOM_SEED_UINT64;
		perror_rt("gettimeofday");
	}
	else
		g_x = (uint64_t)((tv.tv_sec ^ tv.tv_usec) ^ RANDOM_SEED_UINT64);
	return ;
}
