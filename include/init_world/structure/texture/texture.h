/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:46:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/02 18:48:21 by khanadat         ###   ########.fr       */
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

typedef struct s_texture	t_texture;
/*
@param calc_texture_value not const t_hrec* because update it when bump version
*/
struct s_texture
{
	t_color		(*calc_texture_value)(
				const void *self,
				t_hrec * rec);
	size_t		size;
};

t_texture	*clone_texture(const void *s);

#endif
