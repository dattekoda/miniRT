/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:03:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 12:14:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
// #include "miniRT_struct.h"
#include "utils.h"
#include "libft.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*content;

	content = NULL;
	if (argc != ARG_NUM)
		return (MINIRT_FAILURE);
	if (minirt_strrncmp(argv[1], MINIRT_FMT, 3))
		return (MINIRT_FAILURE);
	if (set_content(&content, argv[1]))
		return (MINIRT_FAILURE);
	if (validate_content())
	ft_putstr_fd(content, STDOUT_FILENO);
	free(content);
	return (MINIRT_SUCCESS);
}
