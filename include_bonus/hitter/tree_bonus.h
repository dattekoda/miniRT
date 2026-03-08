/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:30:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/08 18:37:21 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEBONUS_H
# define TREEBONUS_H

# include "hitter_bonus.h"

typedef struct s_tree
{
	t_hitter	hitter;
	t_hitter	*lhs;
	t_hitter	*rhs;
}	t_tree;

#endif
