/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token_to_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:44:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 19:08:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

bool		fequal(double a, double b);
t_result	token_to_value(const char *line, size_t *line_idx, double *d);

int	test_token_to_value(void)
{
	size_t	i;
	double	d;

	i = 0;
	assert(token_to_value("  0  ", &i, &d).state == SUCCESS && i == 3 && fequal(d, 0));
	i = 0;
	assert(token_to_value(" 0.123 ", &i, &d).state == SUCCESS && i == 6 && fequal(d, 0.123));
	i = 0;
	assert(token_to_value("99999 ", &i, &d).state == SUCCESS && i == 5 && fequal(d, 99999));
	i = 0;
	assert(token_to_value(" -0a  ", &i, &d).state == SUCCESS && i == 3 && fequal(d, 0));

	i = 0;
	assert(token_to_value(" a0  ", &i, &d).state == FAILURE && i == 0);
	i = 0;
	assert(token_to_value(" inf  ", &i, &d).state == FAILURE && i == 3);
	i = 0;
	assert(token_to_value(" nan  ", &i, &d).state == FAILURE && i == 3);
	return (0);
}


