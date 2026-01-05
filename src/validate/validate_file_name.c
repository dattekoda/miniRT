/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:09:38 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 11:35:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "validate_define.h"
#include "libft.h"
#include <stdlib.h>

static void	err_file_name(void);
static void	err_first_dot(void);
static void	err_file_name_len(void);
static void	err_file_extension(void);

/*
@brief Check if the file name of argument is correct.
@param argv_one just argv[1]
*/
int	validate_file_name(const char *argv_one)
{
	size_t		rt_file_len;
	const char	*rt_file;

	rt_file = ft_strchr(argv_one, '/');
	if (rt_file)
		rt_file += 1;
	else
		rt_file = argv_one;
	if (rt_file[0] == '.')
		return (err_first_dot(), exit_failure);
	rt_file_len = ft_strlen(rt_file);
	if (rt_file_len <= min_rt_file_name)
		return (err_file_name_len(), exit_failure);
	if (ft_strcmp(rt_file + rt_file_len - 3, ".rt"))
		return (err_file_extension(), exit_failure);
	return (exit_success);
}

static void	err_file_name(void)
{
	err_rt();
	ft_putstr_fd(err_msg_file_name, stderr_fileno);
}

static void	err_first_dot(void)
{
	err_file_name();
	ft_putendl_fd("file name starting with '.' is not supported.", \
		stderr_fileno);
}

static void	err_file_name_len(void)
{
	err_file_name();
	ft_putendl_fd("filename needs to be 4 characters or more.", stderr_fileno);
}

static void	err_file_extension(void)
{
	err_file_name();
	ft_putendl_fd("File extension needs to be '.rt'.", STDERR_FILENO);
}
