/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:50:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:13:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_DEFINE_BONUS_H
# define VALIDATE_DEFINE_BONUS_H

# ifndef NORMALZIE_EPSILON
#  define NORMALIZE_EPSILON 1e-3
# endif

typedef enum s_vectype
{
	IS_POINT,
	IS_UNIT,
	IS_COLOR
}	t_vec3type;

#endif
