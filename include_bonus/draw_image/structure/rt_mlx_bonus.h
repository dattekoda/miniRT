/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:08:10 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLXBONUS_H
# define RT_MLXBONUS_H

# include "hook_var_bonus.h"
# include "rt_img_bonus.h"

typedef struct s_rt_mlx
{
	t_hook_var	var;
	t_rt_img	img;
}	t_rt_mlx;

#endif