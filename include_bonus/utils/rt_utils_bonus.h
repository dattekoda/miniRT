/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:14:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 22:15:23 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_BONUS_H
# define RT_UTILS_BONUS_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

typedef void	(*t_clear)(void *self);

union u_rand_double
{
	uint64_t	u;
	double		d;
};

double		clamp(double x, double min, double max);
// utils_clamp.c

bool		fequal(double a, double b);
// utils_float.c

void		err_rt(char *err_msg);
void		perror_rt(const char *syscall_fname);
// utils_err.c

double		random_double(double min, double max, uint64_t *state);
double		random_01(uint64_t *state);
double		random_minus1_to_1(uint64_t *state);
uint64_t	set_random_seed_from_time(void);
// utils_random.c

void		ft_qsort(
				char *base,
				size_t nmemb,
				size_t size,
				int (*compar)(const void*, const void*));
// utils_qsort.c

void		clear_free_hitter(void *self);
void		clear_hitter(void *self);
void		clear_material(void *self);
// utils_clear.c

void		ft_swap(void *a, void *b, size_t size);
// utils_swap.c

#endif