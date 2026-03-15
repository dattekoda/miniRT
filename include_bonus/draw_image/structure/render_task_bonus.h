/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_task_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:01:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 22:02:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TASK_BONUS_H
# define RENDER_TASK_BONUS_H

# include "world_bonus.h"

typedef struct s_render_task
{
	const t_world	*world;
	int				*raw_rgb_color;
	bool			is_phong;
	size_t			begin_y;
	size_t			end_y;
	uint64_t		seed;
}	t_render_task;

#endif