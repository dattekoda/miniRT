/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:30:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 23:45:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_ARR_H
# define HITTER_ARR_H

# include "hitter.h"
# include <stddef.h>

typedef struct s_hitter_arr
{
	t_hitter	**arr;
	double		*left_area_arr;
	double		*right_area_arr;
	size_t		size;
}	t_hitter_arr;

#endif
