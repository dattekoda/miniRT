/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 23:04:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_BONUS_H
# define PDF_BONUS_H

# include "vec_bonus.h"
# include <stdint.h>

/*
@param calc_pdf_value 方向ベクトルに応じた確率密度を計算
@param generate: generate randomized direction following a specific distribution
*/
typedef struct s_pdf
{
	double	(*calc_pdf_value)(const void *self, const t_vec3 *direction);
	t_vec3	(*generate)(const void *self, uint64_t * seed);
}	t_pdf;

#endif
