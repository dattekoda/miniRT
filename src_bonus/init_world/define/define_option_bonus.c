/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:27:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:17:36 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option_bonus.h"
#include <stddef.h>

const t_option	g_artificial_option = {
	.str = "artificial",
	.flag = OPT_ARTIFICIAL
};

const t_option	g_material_option = {
	.str = "material",
	.flag = OPT_MATERIAL
};

const t_option	g_ppm_option = {
	.str = "ppm",
	.flag = OPT_PPM
};

const t_option	*g_option_table[] = {
	&g_artificial_option,
	&g_material_option,
	&g_ppm_option,
	NULL
};
