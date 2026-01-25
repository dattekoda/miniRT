/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skip_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:28:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:44:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stddef.h>
#include <assert.h>

t_result	skip_color(const char *line, size_t *line_idx);

int	test_skip_color(void)
{
	size_t	i;

	i = 0;
	assert(skip_color(" 0,1,255", &i).state == SUCCESS);
	i = 0;
	assert(skip_color(" 0,256,256", &i).state == FAILURE);
	i = 0;
	assert(skip_color(" -1,0,255", &i).state == FAILURE);
	i = 0;
	assert(skip_color(" -0.01,0,255", &i).state == FAILURE);
	return (0);
}