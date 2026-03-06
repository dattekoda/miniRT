/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:40:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/02/24 14:53:18 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

t_split	construct_split(
				t_axis axis,
				size_t left_size,
				double cost)
{
	t_split	split;

	split.axis = axis;
	split.left_size = left_size;
	split.cost = cost;
	return (split);
}
