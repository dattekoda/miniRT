/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:03:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/28 17:33:13 by ikawamuk         ###   ########.fr       */
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
		return (MINIRT_FAILURE);
	if (minirt_strrncmp(argv[1], MINIRT_FMT, 3))
		return (MINIRT_FAILURE);
	if (set_content(&content, argv[1]))
		return (MINIRT_FAILURE);
	if (validate_content(content))
		return (MINIRT_FAILURE);
	free(content);
	return (MINIRT_SUCCESS);
}
/*
・ARG_NUMはむしろマジックナンバー「2」のほうが可読性たかいのでは？
・MINIRT_FAILUREよりはEXIT_FAIRUE, EXIT_SUCCESSの標準マクロを使ったほうがいい気がする。
・拡張子はfile extensionなのでRT_EXTENTIONとか？
・int minirt_strrncmp(const char *s1, const char *s2, size_t n)はft_strncmpじゃだめか？
・set_contentはreadよりget_next_line()使って良くはないか？
*/