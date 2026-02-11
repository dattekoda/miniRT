/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:28:34 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/10 21:03:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_img_H
# define RT_img_H

typedef struct s_rt_img
{
	void	*id;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_rt_img;

#endif