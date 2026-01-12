/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:48:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/11 16:32:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

int	set_option(const char *options);

int	test_set_option(void)
{
	assert(set_option("-zppppppp") == 0x00);
	assert(set_option("-pppa") == 0x00);
	assert(set_option("-a") == 0x00);

	assert(set_option("-") == 0x00);
	assert(set_option("ppp") == 0x00);
	assert(set_option("-pppppppppp") == 0x01);
	assert(set_option("-p") == 0x01);
	return (0);
}
