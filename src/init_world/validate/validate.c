/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:39:54 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/09 21:22:39 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
#include "libft.h"
#include <unistd.h>

int			validate_ambient(char *line);
int			validate_camera(char *line);
int			validate_light(char *line);
int			validate_sphere(char *line);

static int	match_identifier(const char *line, const char *id, size_t size);
static int	validate_invalid_id(char *line);

int	validate_line(char *line)
{
	if (match_identifier(line, "A", 1))
		return (validate_ambient(line));
	if (match_identifier(line, "C", 1))
		return (validate_camera(line));
	if (match_identifier(line, "L", 1))
		return (validate_light(line));
	if (match_identifier(line, "sp", 2))
		return (validate_sphere(line));
	return (validate_invalid_id(line));
}

static int	match_identifier(const char *line, const char *id, size_t size)
{
	if (ft_strncmp(line, id, size) == 0 \
&& (line[size] == ' ' || line[size] == '\t' || line[size] == '\0'))
		return (1);
	return (0);
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
