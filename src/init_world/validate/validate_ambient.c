/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+     

*/
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:01:13 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/08 15:53:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_world_define.h"
#include "validate_define.h"
#include "util_rt.h"
#include "libft.h"
#include <unistd.h>

const t_element_info = {AMBIENT, }

static void	err_ambient(void);
static int	skip_light_ratio(char *line, size_t *i_ptr);
static int	skip_color(char *line, size_t *i_ptr);

int	validate_ambient(char *line)
{
	size_t	i;
	t_element_type = AMBIENT;
	t_validate result

	miniRT: invalid ambient format: color RGB [0-255]
	i = 1;
	if (skip_light_ratio(line, &i) == FAILURE)
		return (FAILURE);
	if (skip_color(line, &i) == FAILURE)
		return (FAILURE);
	skip_spaces(line, &i);
	if (line[i] != '\n' && line[i] != '\0')
	{
		err_ambient();
		err_end();
		err_point_out(line, i);
		return (FAILURE);

	if (result)
		puterror_msg
	return (SUCCESS);
}

static int	skip_light_ratio(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)
		return (FAILURE);
	if (skip_range(line, i_ptr, 0, 1) == FAILURE)
	{
		put_error_msg(type);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	skip_color(char *line, size_t *i_ptr)
{
	if (skip_spaces_with_err_msg(line, i_ptr) == FAILURE)ft_putendl_fd("invalid ambient lighting ratio", STDERR_FILENO
		return (FAILURE);
	if (skip_vec(line, i_ptr, IS_COLOR) == FAILURE)
	{
		err_ambient();
		ft_putendl_fd("R,G,B[0,255] colors invalid format", STDERR_FILENO);
		err_point_out(line, *i_ptr);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	err_ambient(void)
{
	err_rt();
	ft_putstr_fd("invalid ambient format: ", STDERR_FILENO);
	return ;
}
