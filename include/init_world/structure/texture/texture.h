/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:46:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/27 23:02:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "hit_record.h"
# include "rt_utils.h"
# include "vec.h"

typedef enum e_texture_idx
{
	SOLID,
	CHECKER,
	BUMP,
	INVALID_TEXTURE_IDX
}	t_texture_idx;

/*
@param calc_texture_value not const t_hrec* because update it when bump version
*/
typedef struct s_texture
{
	t_color	(*calc_texture_value)(
		const void *self,
		t_hrec * rec);
}	t_texture;

#endif
