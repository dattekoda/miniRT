/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:16:20 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 23:00:39 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syscall_mock.h"
#include "libft.h"

static int	test(void);
int	test_set_option();

int	_wrap_errno_ = 0;
enum e_error_syscall	err_syscall = 0;
t_list	dummy_head = (t_list){0};

int	main(void)
{
	return (test());
}

static int	test(void)
{
	test_set_option();
	return (0);
}
