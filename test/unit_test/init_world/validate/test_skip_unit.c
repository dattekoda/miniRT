/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skip_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:27:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 20:33:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_define.h"
#include <assert.h>

t_result	skip_unit(const char *line, size_t *line_idx);

int	test_skip_unit(void)
{
	size_t		i;

	i = 0;
	assert(skip_unit(" 0.0,1.0,0.0", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 1.0,0.0,0.0", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 0.0,0.0,1.0", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 0.0,-0.8,0.6", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 0.8,0.0,-0.6", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 0.0,0.0,-1.001", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 0.099,1.0,0.0", &i).state == SUCCESS);
	i = 0;
	assert(skip_unit(" 0.0,1.0049,0.0", &i).state == SUCCESS);

	i = 0;
	assert(skip_unit(" 0.0,1.005,0.0", &i).state == FAILURE);
	i = 0;
	assert(skip_unit(" 0.0,1.1,0.0", &i).state == FAILURE);
	i = 0;
	assert(skip_unit(" 0.0,3.0,-2.0", &i).state == FAILURE);
	i = 0;
	assert(skip_unit(" 0.1,1.0,0.0", &i).state == FAILURE);
	return (0);
}
