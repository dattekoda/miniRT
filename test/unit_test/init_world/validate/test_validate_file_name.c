/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_file_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:28:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:28:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syscall_mock.h"
#include "util_rt.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

int	validate_file_name(const char *argv_one);

int	test_validate_file_name(void)
{
	fprintf(stderr, "\n===== test_validate_file_name =====\n");
	{
		fprintf(stderr, "--- normal case ---\n");
		assert(validate_file_name("test.rt") == SUCCESS);
		assert(validate_file_name("a.rt") == SUCCESS);
		assert(validate_file_name(" .rt") == SUCCESS);
		assert(validate_file_name("テストテスト.rt") == SUCCESS);
		assert(validate_file_name("a..rt") == SUCCESS);
		assert(validate_file_name("a.txt.rt") == SUCCESS);
	}
	return (0);
}
