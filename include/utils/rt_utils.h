/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:14:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/22 19:47:38 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include <stddef.h>
# include <stdbool.h>

typedef void	(*t_clear)(void *self);

double	clamp(double x, double min, double max);
// utils_clamp.c

bool	fequal(double a, double b);
// utils_float.c

void	err_rt(char *err_msg);
void	perror_rt(const char *syscall_fname);
// utils_err.c

double	random_double(double min, double max);
double	random_01(void);
double	random_minus1_to_1(void);
void	set_random_seed_from_time(void);
// utils_random.c

void	ft_qsort(char *base, size_t nmemb, size_t size,
				bool (*compar)(const void*, const void*));
// utils_qsort.c

void	clear_hitter(void *self);
void	clear_material(void *self);
void	clear_texture(void *self);
// utils_clear.c

void	ft_swap(void *a, void *b, size_t size);
// utils_swap.c

#endif