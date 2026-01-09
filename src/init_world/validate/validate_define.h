/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:41:33 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:29:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_DEFINE_H
# define VALIDATE_DEFINE_H

# include <stddef.h>

# define GREEN "\033[92m"
# define RESET "\033[m"

enum e_result
{
	OK,
	ERROR
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

typedef enum s_vectype
{
	IS_POINT,
	IS_UNIT,
	IS_COLOR
}	t_vectype;

typedef t_result	(*t_skip)(const char *line, size_t *line_idx);

typedef struct s_element_info
{
	size_t			identifier_len;
	char			*format;
	const t_skip	*skip_arr;
}	t_element_info;

t_result	construct_result(char *_err_msg);
void		err_point_out(char *line, size_t err_idx);

t_result	skip_point(const char *line, size_t *line_idx);
t_result	skip_unit(const char *line, size_t *line_idx);
t_result	skip_color(const char *line, size_t *line_idx);

t_result	skip_spaces(const char *line, size_t *line_idx);
t_result	skip_until_end(const char *line, size_t *line_idx);

t_result	skip_range(const char *line, size_t *line_idx, \
double min, double max);
t_result	skip_lighting_ratio(const char *line, size_t *line_idx);

int			validate_element(char *line, const t_element_info elem_info);

#endif