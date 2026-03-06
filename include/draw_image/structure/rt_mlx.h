/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:08:10 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/10 21:10:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# include "hook_var.h"
# include "rt_img.h"

typedef struct s_rt_mlx
{
	t_hook_var	var;
	t_rt_img	img;
}	t_rt_mlx;

#endif