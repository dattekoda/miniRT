/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:02:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:54:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_TEXTURE_BONUS_H
# define CHECKER_TEXTURE_BONUS_H

# include "solid_texture_bonus.h"

typedef struct s_checker_texture
{
	t_texture		texture;
	t_solid_texture	even;
	t_solid_texture	odd;
}	t_checker_texture;

#endif