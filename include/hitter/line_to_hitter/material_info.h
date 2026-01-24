/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_info.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:06:36 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/24 17:12:17 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_INFO_H
# define MATERIAL_INFO_H

# include "vec.h"
# include <stddef.h>

typedef struct s_material_info
{
	size_t	mat_idx;
	size_t	tex_idx;
	t_color	color;
}	t_material_info;

#endif