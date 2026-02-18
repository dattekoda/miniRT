/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:30:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 22:02:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "hitter.h"

typedef struct s_tree
{
	t_hitter	hitter;
	t_hitter	*lhs;
	t_hitter	*rhs;
}	t_tree;

#endif
