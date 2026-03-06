/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skip_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:44:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 16:33:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stddef.h>
#include <assert.h>

t_result	skip_spaces(const char *line, size_t *line_idx);

int	test_skip_spaces(void)
{
	size_t		i;

	i = 0;
	assert(skip_spaces("a  ", &i).state == FAILURE && i == 0);
	i = 0;
	assert(skip_spaces("  a  ", &i).state == SUCCESS && i == 2);
	i = 0;
	assert(skip_spaces("       a  ", &i).state == SUCCESS && i == 7);
	i = 0;
	assert(skip_spaces(" \t a\t ", &i).state == SUCCESS && i == 3);
	return (0);
}
