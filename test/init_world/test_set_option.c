/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:48:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/25 02:53:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include <assert.h>
#include <stddef.h>

int	set_option(const char *options[]);

int	test_set_option(void)
{
	assert((OPT_ARTIFICIAL & OPT_MATERIAL) == 0);
	const int	all_flag = (OPT_ARTIFICIAL | OPT_MATERIAL);
	assert(set_option((char *[]){"-a", NULL}) == OPT_ARTIFICIAL);
	assert(set_option((char *[]){"-m", NULL}) == OPT_MATERIAL);
	assert(set_option((char *[]){"-am", NULL}) == (OPT_ARTIFICIAL | OPT_MATERIAL));
	assert(set_option((char *[]){"-m", "-a", NULL}) == (OPT_ARTIFICIAL | OPT_MATERIAL));
	assert(set_option((char *[]){"-a", "-aa", NULL}) == OPT_ARTIFICIAL);

	assert(set_option((char *[]){"--artificial", NULL}) == OPT_ARTIFICIAL);
	assert(set_option((char *[]){"--material", NULL}) == OPT_MATERIAL);
	assert(set_option((char *[]){"--artificial", "--material", NULL}) == (OPT_ARTIFICIAL | OPT_MATERIAL));
	assert(set_option((char *[]){"--material", "--material", NULL}) == OPT_MATERIAL);
	return (0);
}
