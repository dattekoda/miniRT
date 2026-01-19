/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 16:17:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PDF_H
# define LIGHT_PDF_H

# include "pdf.h"
# include "vec.h"
# include "world.h"
# include "libft.h"

typedef struct s_light_pdf
{
	t_pdf			pdf;
	const t_list	*light_list;
	t_point3		p;
}	t_light_pdf;

t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_world *world);

#endif
