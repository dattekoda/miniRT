/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:46:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/19 17:54:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "hitter.h"

typedef struct s_texture
{
	t_color	(*texture_value)(const void *self, t_hrec *hrec);
	t_clear	clear;
}	t_texture;

#endif
