/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:46:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 16:20:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "hitter.h"
# include "vec.h"

typedef struct s_texture
{
	t_color	(*calc_texture_value)(const void *self, t_hrec *hrec);
	t_clear	clear;
}	t_texture;

enum e_texture_idx
{
	SOLID,
	CHECKER,
	BUMP,
	INVALID_TEXTURE_IDX
};

#endif
