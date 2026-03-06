/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:15:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/22 19:28:34 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_DEFINE_H
# define MATERIAL_DEFINE_H

# include "material.h"

typedef t_material					*(*t_generate_material)(
	t_texture *texture_ptr);
extern const char					*g_material_specifiers[];
extern const t_generate_material	g_gen_material_table[];

#endif
