/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/08 16:33:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validate.h"
#include "util_rt.h"
#include "libft.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	test_validate_camera(void)
{
	fprintf(stderr, "\n===== test_validate_camera =====\n");
	ft_putendl_fd("\n===== normal case =====\n", STDERR_FILENO);
	assert(case_validate_line("./test_scene/test_camera/success1.rt") == SUCCESS);
	assert(case_validate_line("./test_scene/test_camera/success2.rt") == SUCCESS);
	assert(case_validate_line("./test_scene/test_camera/success3.rt") == SUCCESS);
	ft_putendl_fd("\n===== error case =====\n", STDERR_FILENO);
	assert(case_validate_line("./test_scene/test_camera/failure1.rt") == FAILURE);
	assert(case_validate_line("./test_scene/test_camera/failure2.rt") == FAILURE);
	assert(case_validate_line("./test_scene/test_camera/failure3.rt") == FAILURE);
	assert(case_validate_line("./test_scene/test_camera/failure4.rt") == FAILURE);
	return (0);
}
