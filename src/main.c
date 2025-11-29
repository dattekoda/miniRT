/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:03:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/29 18:20:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_define.h"
#include "miniRT_struct.h"
#include "utils.h"
#include "libft.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

// ft_putstr_fd(content, STDOUT_FILENO);
int	main(int argc, char *argv[])
{
	char	*content;

	content = NULL;
	if (argc != ARG_NUM)
		return (EXIT_FAILURE);
	if (minirt_strrncmp(argv[1], RT_EXTENTION, 3))
		return (EXIT_FAILURE);
	if (set_content(&content, argv[1]))
		return (EXIT_FAILURE);
	if (validate_content(content))
		return (EXIT_FAILURE);
	free(content);
	return (EXIT_SUCCESS);
}
