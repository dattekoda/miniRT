/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:28:34 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 17:58:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_IMG_H
# define RT_IMG_H

typedef struct s_rt_img
{
	void	*id;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}	t_rt_img;

#endif
