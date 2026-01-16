/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:14:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 16:08:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include <stdio.h> // delete later 

int		fequal(double a, double b);

void	err_rt(char *err_msg);
void	perror_rt(const char *syscall_fname);

double	random_double(double min, double max);

#endif