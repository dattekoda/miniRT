/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_file_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:12:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 01:26:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdbool.h>

bool	is_valid_file_name(const char *file_path);

int	test_is_valid_file_name(void)
{
	assert(validate_file_name("a.rt") == true);
	assert(validate_file_name(" .rt") == true);
	assert(validate_file_name("aaaaaaaaaaaaa.rt") == true);
	assert(validate_file_name("/a.rt") == true);
	assert(validate_file_name("a/a.rt") == true);

	assert(validate_file_name("a") == false);
	assert(validate_file_name("a.rrt") == false);
	assert(validate_file_name("a.rtt") == false);
	assert(validate_file_name(".rt") == false);
	assert(validate_file_name("/.rt") == false);
	assert(validate_file_name("a.r") == false);
	assert(validate_file_name("a.") == false);
	return (0);
}
