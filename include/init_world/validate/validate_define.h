/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:53:42 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 14:52:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_DEFINE_H
# define VALIDATE_DEFINE_H

# include <stddef.h>

# ifndef NORMALZIE_EPSILON
#  define NORMALIZE_EPSILON 1e-3
# endif

typedef enum s_vectype
{
	IS_POINT,
	IS_UNIT,
	IS_COLOR
}	t_vectype;

void	skip_spaces(char *line, size_t *i_ptr);
int		skip_spaces_with_err_msg(char *line, size_t *i);
int		skip_range(const char *line, size_t *i_ptr, double min, double max);
int		skip_vec(char *line, size_t *i_ptr, t_vectype type);

void	err_point_out(char *line, size_t err_idx);
void	err_spaces(void);
void	err_end(void);

#endif