/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:14:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 16:09:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include <stdio.h> // delete later 
# include <stdbool.h>

bool	fequal(double a, double b);
// utils_float.c

void	err_rt(char *err_msg);
void	perror_rt(const char *syscall_fname);
// utils_err.c

double	random_double(double min, double max);
int		random_int(int min, int max);
size_t	random_size_t(size_t min, size_t max);
// utils_random.c

void	clear_hitter(void *self);
void	clear_material(void *s);
void	clear_texture(void *s);
// utils_clear.c

void	rt_swap(void *a, void *b, size_t size);
// utils_swap.c

#endif