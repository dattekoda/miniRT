/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:23:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 00:40:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_utils_H
# define rt_utils_H

#include "rt_define.h"
#include <stdio.h> // 後で消す

void	err_rt(void);
void	perror_rt(const char *syscall_fname);

#endif