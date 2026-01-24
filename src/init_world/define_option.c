/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:27:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/24 18:46:17 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"

const t_option	g_artificial_option = {
	.str = "artificial",
	.flag = OPT_ARTIFICIAL
};

const t_option	g_material_option = {
	.str = "material",
	.flag = OPT_MATERIAL
};
