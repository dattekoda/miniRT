/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pdf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/20 17:38:44 by khanadat         ###   ########.fr       */
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
	t_pdf				pdf;
	const t_list const	*light_list;
	t_point3			point;
}	t_light_pdf;

t_light_pdf	construct_light_pdf(const t_hrec *hrec, const t_world *world);

#endif
