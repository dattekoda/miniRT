/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_split.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:47:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:49:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEST_SPLIT_H
# define BEST_SPLIT_H

# include <stddef.h>

typedef struct s_best_split
{
	int		axis;
	size_t	left_size;
	double	cost;
}	t_best_split;

#endif
