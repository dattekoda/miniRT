/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:50:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 00:20:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_DEFINE_H
# define VALIDATE_DEFINE_H

# include "define_rt.h"

# ifndef NORMALZIE_EPSILON
#  define NORMALIZE_EPSILON 1e-3
# endif

typedef enum s_vectype
{
	IS_POINT,
	IS_UNIT,
	IS_COLOR
}	t_vectype;

typedef t_result	(*t_skip)(const char *line, size_t *line_idx);

typedef struct s_element_info
{
	char			*identifer;
	size_t			identifier_len;
	char			*format;
	const t_skip	*skip_arr;
}t_element_info;

#endif
