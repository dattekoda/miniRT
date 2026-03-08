/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter_arr_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:30:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_ARRBONUS_H
# define HITTER_ARRBONUS_H

# include "hitter_bonus.h"
# include <stddef.h>

typedef struct s_hitter_arr
{
	t_hitter	**arr;
	double		*left_surface_arr;
	double		*right_surface_arr;
	size_t		size;
}	t_hitter_arr;

// typedef bool	(*t_compar)(const void *lhs, const void *rhs);
typedef int	(*t_compar)(const void *lhs, const void *rhs);

#endif
