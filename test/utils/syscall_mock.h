/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_mock.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:37:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 01:45:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSCALL_MOCK_H
# define SYSCALL_MOCK_H

# include <stdbool.h>
enum e_error_syscall {
	NOTHING,
	OPEN,
	READ,
	WRITE,
	MALLOC
};

extern int		_wrap_errno_;
extern enum		e_error_syscall err_syscall;

bool	is_memory_leaked(void);

#endif