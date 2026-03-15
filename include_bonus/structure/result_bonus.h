/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:29:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:13:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_BONUS_H
# define RESULT_BONUS_H

enum e_result
{
	SUCCESS,
	FAILURE,
};

union u_result
{
	int		ok;
	char	*err_msg;
};

typedef struct s_result
{
	enum e_result	state;
	union u_result	value;
}	t_result;

t_result	construct_result(char *_err_msg);
t_result	construct_success_result(void);

#endif
