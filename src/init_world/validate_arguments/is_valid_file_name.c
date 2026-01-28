/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:22:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 19:20:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

static bool	is_valid_file_extention(const char *file);

/*
@brief Check if the file name of argument is correct.
@param file_path just argv[1]
*/
bool	is_valid_file_name(const char *file_path)
{
	const char	*rt_file;

	rt_file = ft_strchr(file_path, '/');
	if (rt_file)
		rt_file += 1;
	else
		rt_file = file_path;
	if (!is_valid_file_extention(rt_file))
	{
		err_rt("invalid file name");
		return (false);
	}
	return (true);
}

static bool	is_valid_file_extention(const char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (file[0] == '.')
		return (false);
	if (len < 4 || ft_strcmp(file + len - 3, ".rt"))
		return (false);
	return (true);
}
