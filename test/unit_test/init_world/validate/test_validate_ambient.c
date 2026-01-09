/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_ambient.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:28:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_rt.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

int	case_validate_line(const char *test_path);

int	test_validate_ambient(void)
{
	fprintf(stderr, "\n===== test_validate_ambient =====\n");
	ft_putendl_fd("\n===== normal case =====\n", STDERR_FILENO);
	assert(case_validate_line("./test_scene/test_ambient/success1.rt") == SUCCESS);
	assert(case_validate_line("./test_scene/test_ambient/success2.rt") == SUCCESS);
	assert(case_validate_line("./test_scene/test_ambient/success3.rt") == SUCCESS);
	ft_putendl_fd("\n===== error case =====\n", STDERR_FILENO);
	assert(case_validate_line("./test_scene/test_ambient/failure1.rt") == FAILURE);
	assert(case_validate_line("./test_scene/test_ambient/failure2.rt") == FAILURE);
	assert(case_validate_line("./test_scene/test_ambient/failure3.rt") == FAILURE);
	assert(case_validate_line("./test_scene/test_ambient/failure4.rt") == FAILURE);
	return (0);
}
