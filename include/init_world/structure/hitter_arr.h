/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:30:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/17 21:36:47 by khanadat         ###   ########.fr       */
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
}	t_hitter_arr;

typedef bool	(*t_compare)(const void *lhs, const void *rhs);

#endif
