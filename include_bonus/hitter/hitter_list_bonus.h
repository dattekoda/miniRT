/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitter_list_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:58:09 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/15 20:20:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTER_LIST_BONUS_H
# define HITTER_LIST_BONUS_H

# include "hitter_bonus.h"
# include "libft.h"

/*
@brief list
*/
typedef struct s_hitter_list
{
	t_hitter	hitter;
	t_list		*head;
}	t_hitter_list;

#endif
