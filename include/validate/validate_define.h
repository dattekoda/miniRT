/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/06 18:55:24 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_DEFINE_H
# define VALIDATE_DEFINE_H

typedef enum s_vectype
{
	IS_POINT,
	IS_UNIT,
	IS_COLOR
}	t_vectype;

// validate_util.c
int	skip_spaces(char **ptr);
int	skip_range(char **ptr, int min, int max);
int	skip_vec(char **ptr, t_vectype type);

// validate_util_err.c
void	err_spaces(void (*f)(void));
void	err_range(void (*f)(void), int min, int max);
void	err_vec(void (*f)(void), t_vectype type);

#endif