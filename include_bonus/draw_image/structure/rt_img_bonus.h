/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_img_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:28:34 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/08 18:54:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_IMG_BONUS_H
# define RT_IMG_BONUS_H

typedef struct s_rt_img
{
	void	*id;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_rt_img;

#endif
