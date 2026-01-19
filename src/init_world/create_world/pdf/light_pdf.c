/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:14:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:17:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_pdf.h"

t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_world *world)
{
	t_light_pdf	light_;

	// light_.pdf.value_pdf = value_light_pdf;
	// light_.pdf.random_pdf = random_light_pdf;
	light_.light_list = world->light_list;
	light_.p = hrec->point;
	return (light_);
}
