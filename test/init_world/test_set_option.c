/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:48:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/26 08:38:58 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include <assert.h>
#include <stddef.h>

int	set_option(const char *options[]);

int	test_set_option(void)
{
	assert((OPT_ARTIFICIAL & OPT_MATERIAL) == 0);
	assert(set_option((const char *[]){"-a", NULL}) == OPT_ARTIFICIAL);
	assert(set_option((const char *[]){"-m", NULL}) == OPT_MATERIAL);
	assert(set_option((const char *[]){"-am", NULL}) == (OPT_ARTIFICIAL | OPT_MATERIAL));
	assert(set_option((const char *[]){"-m", "-a", NULL}) == (OPT_ARTIFICIAL | OPT_MATERIAL));
	assert(set_option((const char *[]){"-a", "-aa", NULL}) == OPT_ARTIFICIAL);

	assert(set_option((const char *[]){"--artificial", NULL}) == OPT_ARTIFICIAL);
	assert(set_option((const char *[]){"--material", NULL}) == OPT_MATERIAL);
	assert(set_option((const char *[]){"--artificial", "--material", NULL}) == (OPT_ARTIFICIAL | OPT_MATERIAL));
	assert(set_option((const char *[]){"--material", "--material", NULL}) == OPT_MATERIAL);
	return (0);
}
