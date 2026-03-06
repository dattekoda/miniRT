/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:21:39 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/06 20:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

static double	g_time;

void	init_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	g_time = (double)start.tv_sec + (double)start.tv_usec * 0.000001;
}

void	print_time(void)
{
	struct timeval	end;
	double			d_end;

	gettimeofday(&end, NULL);
	d_end = (double)end.tv_sec + (double)end.tv_usec * 0.000001;
	printf("time:\t%0.4fs\n", d_end - g_time);
	return ;
}
