/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:31:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/10 00:48:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_define_H
# define rt_define_H

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
