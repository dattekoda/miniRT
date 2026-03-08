/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_define_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:15:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_DEFINEBONUS_H
# define MATERIAL_DEFINEBONUS_H

# include "material_bonus.h"

typedef t_material					*(*t_generate_material)(
	t_texture *texture_ptr);
extern const char					*g_material_specifiers[];
extern const t_generate_material	g_gen_material_table[];

#endif
