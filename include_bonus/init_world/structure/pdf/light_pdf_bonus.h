/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:54:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PDF_BONUS_H
# define LIGHT_PDF_BONUS_H

# include "pdf_bonus.h"
# include "vec_bonus.h"
# include "world_bonus.h"
# include "libft.h"

typedef struct s_light_pdf
{
	t_pdf			pdf;
	const t_list	*light_list;
	t_point3		point;
}	t_light_pdf;

t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_list *light_list);

#endif
