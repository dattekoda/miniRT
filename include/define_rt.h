/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 23:57:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_RT_H
# define DEFINE_RT_H

#include <stddef.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define GREEN "\033[92m"
# define RESET "\033[m"

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

#endif
