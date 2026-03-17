/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_threads_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:26:31 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/17 21:07:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result_bonus.h"
#include "world_bonus.h"
#include "rt_define_bonus.h"
#include "vec_utils_bonus.h"
#include "render_task_bonus.h"
#include "libft.h"
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_color			accumulate_sample_pixel_color(
					t_render_task *r_task,
					size_t xi,
					size_t yi);
static int		accumulate_with_threads(
					pthread_t *threads,
					t_render_task *r_tasks,
					long core_num);
static void		*accumulate_routine(void *task_p);
static int		init_render_task(
					t_render_task **r_task,
					t_render_task r_task_param,
					long size);
static int		convert_into_raw_rgb(t_color color);

int	accumulate_raw_rgb_arr(
				int *raw_rgb_arr,
				const t_world *world,
				bool is_phong)
{
	const t_render_task	sample_task
		= (t_render_task){.is_phong = is_phong,
		.raw_rgb_color = raw_rgb_arr, .world = world};
	const long			core_num = sysconf(_SC_NPROCESSORS_ONLN);
	pthread_t			*threads;
	t_render_task		*r_tasks;

	threads = ft_calloc(core_num, sizeof(pthread_t));
	if (!threads)
		return (FAILURE);
	if (init_render_task(&r_tasks, sample_task, core_num))
		return (free(threads), FAILURE);
	if (accumulate_with_threads(threads, r_tasks, core_num))
		return (free(threads), free(r_tasks), FAILURE);
	return (free(threads), free(r_tasks), SUCCESS);
}

static int	accumulate_with_threads(
				pthread_t *threads,
				t_render_task *r_tasks,
				long core_num)
{
	long	threads_idx;
	long	join_idx;
	int		result;

	fprintf(stderr, "%ld threads computing...\n", core_num);
	threads_idx = -1;
	result = SUCCESS;
	while (++threads_idx < core_num)
	{
		if (pthread_create(&threads[threads_idx],
				NULL, accumulate_routine, &r_tasks[threads_idx]))
		{
			result = FAILURE;
			break ;
		}
	}
	join_idx = -1;
	while (++join_idx < threads_idx)
	{
		if (pthread_join(threads[join_idx], NULL))
			return (FAILURE);
	}
	ft_putendl_fd("Done", STDERR_FILENO);
	return (result);
}

static int	init_render_task(
		t_render_task **r_task,
		t_render_task r_task_param,
		long size)
{
	long			i;
	const size_t	rows_per_thread = g_window_height / size;

	*r_task = ft_calloc(size, sizeof(t_render_task));
	if (!*r_task)
		return (FAILURE);
	i = 0;
	while (i < size)
	{
		(*r_task)[i] = r_task_param;
		(*r_task)[i].begin_y = i * rows_per_thread;
		(*r_task)[i].seed = set_random_seed_from_time() * (uint64_t)(i + 1);
		if (i == size - 1)
			(*r_task)[i].end_y = g_window_height;
		else
			(*r_task)[i].end_y = (i + 1) * rows_per_thread;
		i++;
	}
	return (SUCCESS);
}

static void	*accumulate_routine(void *task_p)
{
	t_render_task		*task;
	size_t				yi;
	size_t				xi;
	size_t				x_base;

	task = task_p;
	yi = task->begin_y;
	while (yi < task->end_y)
	{
		x_base = yi * g_window_width;
		xi = 0;
		while (xi < g_window_width)
		{
			task->raw_rgb_color[x_base + xi]
				= convert_into_raw_rgb(
					accumulate_sample_pixel_color(
						task,
						xi,
						yi));
			xi++;
		}
		yi++;
	}
	return (NULL);
}

static int	convert_into_raw_rgb(t_color color)
{
	t_color	gamma_encoded_color;
	int		r;
	int		g;
	int		b;

	gamma_encoded_color = map_vec3(color, sqrt);
	r = (int)round((double)0xFF * clamp(gamma_encoded_color.e[0], 0.0, 1.0));
	g = (int)round((double)0xFF * clamp(gamma_encoded_color.e[1], 0.0, 1.0));
	b = (int)round((double)0xFF * clamp(gamma_encoded_color.e[2], 0.0, 1.0));
	return ((r << 16) | (g << 8) | b);
}

// int	init_threads(pthread_mutex_t **threads, long size)
// {
// 	long	i;

// 	*threads = ft_calloc(size, sizeof(pthread_mutex_t));
// 	if (!*threads)
// 		return (FAILURE);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (pthread_mutex_init((*threads + i), NULL))
// 		{
// 			clear_threads(threads, i);
// 			return (FAILURE);
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// void	clear_threads(pthread_mutex_t **threads, long size)
// {
// 	long	i;

// 	i = 0;
// 	while (i < size)
// 		pthread_mutex_destroy(*threads + i++);
// 	free(*threads);
// 	*threads = NULL;
// }
