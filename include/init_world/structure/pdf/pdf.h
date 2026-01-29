/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:20:35 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PDF_H
# define PDF_H

# include "vec.h"

/*
@param calc_pdf_value 方向ベクトルに応じた確率密度を計算
@param random_pdf ランダムな方向ベクトルを生成
*/
typedef struct s_pdf
{
	double	(*calc_pdf_value)(const void *self, const t_vec3 *direction);
	t_vec3	(*random_pdf)(const void *self);
}	t_pdf;

#endif
