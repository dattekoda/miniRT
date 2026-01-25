/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skip_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:45:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:43:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "result.h"
#include <assert.h>

t_result	skip_point(const char *line, size_t *line_idx);

int	test_skip_point(void)
{
	size_t		i;

	i = 0;
	assert(skip_point(" 0,0,0", &i).state == SUCCESS && i == 6);
	i = 0;
	assert(skip_point(" 0.0,0.0,0.0 ", &i).state == SUCCESS && i == 12);
	i = 0;
	assert(skip_point(" 0,0,0 ", &i).state == SUCCESS && i == 6);
	i = 0;
	assert(skip_point(" 0.0,0.0   ,   0.0 ", &i).state == SUCCESS && i == 18);
	i = 0;
	assert(skip_point(" 0.0 ,0.0, 0.0 ", &i).state == SUCCESS && i == 14);
	i = 0;
	assert(skip_point(" 0.0,0.0,0.0a ", &i).state == SUCCESS && i == 12);
	i = 0;
	assert(skip_point(" 0.0,0.0,0.0, ", &i).state == SUCCESS && i == 12);
	i = 0;

	assert(skip_point(" 0.0,0.0,a ", &i).state == FAILURE && i == 9);
	i = 0;
	assert(skip_point(" 0.0,,0.0 ", &i).state == FAILURE && i == 5);
	i = 0;
	assert(skip_point(" 0.0a0.0 ", &i).state == FAILURE && i == 4);
	i = 0;
	assert(skip_point(" 0.0,0.0a0.0 ", &i).state == FAILURE && i == 8);
	i = 0;
	assert(skip_point(" 0.0 ,0.0, ,00 ", &i).state == FAILURE && i == 10);
	i = 0;
	assert(skip_point(" 0.0,a,0.0 ", &i).state == FAILURE && i == 5);
	i = 0;
	assert(skip_point("0.0,0.0,0.0 ", &i).state == FAILURE && i == 0);
	return (0);
}
