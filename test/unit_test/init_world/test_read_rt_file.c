/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_rt_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:59:51 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 11:28:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syscall_mock.h"
#include "libft.h"
#include "result.h"
#include <assert.h>
#include <stdio.h>

void	read_rt_file(t_list **line_list, const char *file_path);
static bool	is_valid_success1(t_list *list_ptr);

int	test_read_rt_file(void)
{
	t_list	*list_ptr;

	if (setjmp(g_test_jump_env) == 0)
		read_rt_file(&list_ptr, "invalid_path");
	else
		assert(g_last_exit_status == FAILURE);
	if (setjmp(g_test_jump_env) == 0) {
		err_syscall = MALLOC;
		read_rt_file(&list_ptr, "test_scene/test_ambient/success1.rt");
	} else {
		assert(g_last_exit_status == FAILURE);
	}
	if (setjmp(g_test_jump_env) == 0) {
		err_syscall = READ;
		read_rt_file(&list_ptr, "test_scene/test_ambient/success1.rt");
	} else {
		assert(g_last_exit_status == FAILURE);
	}
	err_syscall = 0;
	read_rt_file(&list_ptr, "test_scene/test_ambient/success1.rt");
	assert(is_valid_success1(list_ptr) == false);
	return (0);
}

static bool	is_valid_success1(t_list *list_ptr)
{
	if (ft_strcmp(list_ptr->content, "A 0.5 100,200,255"))
		return (false);
	if (ft_strcmp(list_ptr->next->content, "C -50,0,0 0,0,1 70"))
		return (false);
	if (list_ptr->next->next != NULL)
		return (false);
	return (true);
}
