/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:23:24 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 17:04:00 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_RT_H
# define UTIL_RT_H

enum
{
	SUCCESS,
	FAILURE,
};

void	err_rt(void);
void	perror_rt(const char *func);

#endif