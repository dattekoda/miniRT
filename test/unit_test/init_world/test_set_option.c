/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:48:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/07 19:22:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

int	set_option(const char *options);

int	test_set_option(void)
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
