/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:26:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 16:52:05 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

bool	is_valid_option(char **options);

int	test_is_valid_option(void)
{
	assert(is_valid_option((char *[]){"-a", NULL}) == true);
	assert(is_valid_option((char *[]){"-aaa", NULL}) == true);
	assert(is_valid_option((char *[]){"-amma", NULL}) == true);
	assert(is_valid_option((char *[]){"-a", "-m", NULL}) == true);
	assert(is_valid_option((char *[]){"-am", NULL}) == true);
	assert(is_valid_option((char *[]){"-ma", NULL}) == true);

	assert(is_valid_option((char *[]){"--artificial", NULL}) == true);
	assert(is_valid_option((char *[]){"--artificial", "--material", NULL}) == true);

	assert(is_valid_option((char *[]){"a", NULL}) == false);
	assert(is_valid_option((char *[]){"-x", NULL}) == false);
	assert(is_valid_option((char *[]){"-artificial", NULL}) == false);
	assert(is_valid_option((char *[]){"--zoo", NULL}) == false);
	assert(is_valid_option((char *[]){"--a", NULL}) == false);
	assert(is_valid_option((char *[]){"--materialX", NULL}) == false);
	assert(is_valid_option((char *[]){"--artificial--material", NULL}) == false);
	return (0);
}
