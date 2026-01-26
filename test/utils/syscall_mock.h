/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_mock.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:37:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/26 17:24:19 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSCALL_MOCK_H
# define SYSCALL_MOCK_H

# include <stdbool.h>
# include <setjmp.h>
enum e_error_syscall {
	NOTHING,
	OPEN,
	READ,
	WRITE,
	MALLOC
};

extern int		_wrap_errno_;
extern enum		e_error_syscall err_syscall;

extern jmp_buf	g_test_jump_env;
extern int		g_last_exit_status;

bool	is_memory_leaked(void);

#endif