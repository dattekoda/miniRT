/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:39:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/17 21:41:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"

void	clear_hitter(void *content)
{
	t_hitter	*hitter;

	hitter = (t_hitter *)content;
	hitter->clear(&hitter);
}

void	clear_premitive(void *self)
{
	t_hitter	*hitter;

	hitter = (t_hitter *)self;
	hitter->mat_ptr->clear(self->mat_ptr);
	free(hitter);
}
