/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_file_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:12:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 21:38:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdbool.h>

bool	is_valid_file_name(const char *file_path);

int	test_is_valid_file_name(void)
{
	assert(is_valid_file_name("a.rt") == true);
	assert(is_valid_file_name(" .rt") == true);
	assert(is_valid_file_name("aaaaaaaaaaaaa.rt") == true);
	assert(is_valid_file_name("/a.rt") == true);
	assert(is_valid_file_name("a/a.rt") == true);

	assert(is_valid_file_name("a") == false);
	assert(is_valid_file_name("a.rrt") == false);
	assert(is_valid_file_name("a.rtt") == false);
	assert(is_valid_file_name(".rt") == false);
	assert(is_valid_file_name("/.rt") == false);
	assert(is_valid_file_name("a.r") == false);
	assert(is_valid_file_name("a.") == false);
	return (0);
}
