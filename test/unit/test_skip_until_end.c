/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skip_until_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:45:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/11 16:33:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stddef.h>
#include <assert.h>

t_result	skip_until_end(const char *line, size_t *line_idx);

int	test_skip_until_end(void)
{
	size_t		i;

	i = 0;
	assert(skip_until_end("  ", &i).state == SUCCESS && i == 2);
	i = 0;
	assert(skip_until_end("  \t\n", &i).state == SUCCESS && i == 3);
	i = 0;
	assert(skip_until_end(" \t a\t \n", &i).state == FAILURE && i == 3);
	i = 0;
	assert(skip_until_end("  a  ", &i).state == FAILURE && i == 2);
	return (0);
}
