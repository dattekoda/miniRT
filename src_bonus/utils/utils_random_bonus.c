/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 23:19:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_bonus.h"
#include "rt_define_bonus.h"
#include "libft.h"
#include <stdint.h>
#include <stddef.h>
#include <sys/time.h>

static uint64_t	random_uint64(uint64_t *state);

/*
@brief let randomized 53 bits as a mantissa
*/
double	random_double(double min, double max, uint64_t *state)
{
	const uint64_t	u = (random_uint64(state) >> 11);
	const double	d = (double)u * DOUBLE_INV_SCALE;

	return (min + (max - min) * d);
}

double	random_01(uint64_t *state)
{
	const union u_rand_double	rand_d = {
		.u = random_uint64(state) >> 12 | 0x3FF0000000000000ULL
	};

	return (rand_d.d - 1.0);
}

double	random_minus1_to_1(uint64_t *state)
{
	const union u_rand_double	rand_d = {
		.u = random_uint64(state) >> 12 | 0x4000000000000000ULL
	};

	return (rand_d.d - 3.0);
}

static uint64_t	random_uint64(uint64_t *state)
{
	*state ^= *state << 12;
	*state ^= *state >> 25;
	*state ^= *state << 27;
	return (*state);
}

uint64_t	set_random_seed_from_time(void)
{
	struct timeval	tv;
	uint64_t		seed;

	if (gettimeofday(&tv, NULL))
	{
		seed = RANDOM_SEED_UINT64;
		perror_rt("gettimeofday");
	}
	else
		seed = (uint64_t)((tv.tv_sec ^ tv.tv_usec) ^ RANDOM_SEED_UINT64);
	return (seed);
}
