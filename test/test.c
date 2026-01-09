/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:16:20 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 01:05:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syscall_mock.h"
#include "libft.h"

static int	test(void);
int			test_set_option(void);
int			test_validate_line_list(void);

int	_wrap_errno_ = 0;
enum e_error_syscall	err_syscall = NOTHING;
t_list	dummy_head = (t_list){0};

int	main(void)
{
	return (test());
}

static int	test(void)
{
	test_set_option();
	test_validate_line_list();
	return (0);
}
