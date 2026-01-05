/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:48:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 23:05:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

int	set_option(const char *options);

int	test_set_option()
{
	assert(set_option("-zppppppp") == 0);
	assert(set_option("-pppa") == 0);
	assert(set_option("-a") == 0);

	assert(set_option("-") == 0);
	assert(set_option("ppp") == 0);
	assert(set_option("-pppppppppp") == 1);
	assert(set_option("-p") == 1);
	return (0);
}
