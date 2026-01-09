/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:32:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 01:20:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_utils.h"
#include "rt_define.h"
#include "libft.h"
#include <unistd.h>

static int	count_ambient_and_camera(const t_list *line_list);
static int	validate_line(char *line);
static int	match_identifier(const char *line, t_element_info info);
int			validate_element(char *line, const t_element_info elem_info);
static int	validate_invalid_id(char *line);

int	validate_line_list(const t_list *line_list)
{
	int	rev;

	rev = count_ambient_and_camera(line_list);
	while (line_list)
	{
		if (validate_line(line_list->content) == FAILURE)
			rev = FAILURE;
		line_list = line_list->next;
	}
	return (rev);
}

static int	count_ambient_and_camera(const t_list *line_list)
{
	size_t	ambient_count;
	size_t	camera_count;

	ambient_count = 0;
	camera_count = 0;
	while (line_list)
	{
		if (match_identifier(line_list->content, "A", 1))
			ambient_count++;
		if (match_identifier(line_list->content, "C", 1))
			camera_count++;
		line_list = line_list->next;
	}
	if (ambient_count == 1 && camera_count == 1)
		return (SUCCESS);
	if (ambient_count != 1)
		ft_putendl_fd("set only one ambient", STDERR_FILENO);
	if (camera_count != 1)
		ft_putendl_fd("set only one camera", STDERR_FILENO);
	return (FAILURE);
}

static int	match_identifier(const char *line, t_element_info info)
{
	if (ft_strncmp(line, info.id, info.id_len) == 0)
		return (1);
	if (line[info.id_len] == ' ' || line[size] == '\t' || line[size] == '\0')
		return (1);
	return (0);
}

static int	validate_line(char *line)
{
	size_t	i;

	i = 0;
	while (g_info_table[i])
	{
		if (match_identifier(line, g_info_table[i]))
			return (validate_element(line, *g_info_table[i]));
		i++;
	}
	return (validate_invalid_id(line));
}

static int	validate_invalid_id(char *line)
{
	size_t	identifier_idx;

	identifier_idx = 0;
	while (line[identifier_idx] != ' ' && line[identifier_idx] != '\t')
		identifier_idx++;
	err_point_out(line, identifier_idx - 1);
	ft_putendl_fd("invalid identifier", STDERR_FILENO);
	return (1);
}
