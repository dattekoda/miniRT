/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:30:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/15 12:31:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_ARR_H
# define HITTER_ARR_H

# include "hitter.h"
# include <stddef.h>

typedef struct s_hitter_arr
{
	t_hitter	**arr;
	size_t		size;
	double		surface_area;
}	t_hitter_arr;

#endif
