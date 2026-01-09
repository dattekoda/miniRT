/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_line_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:56:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/09 23:23:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_validate.h"
#include "util_rt.h"
#include "libft.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void		read_rt_file(t_list **line_list, const char *file_path);
int			validate_line_list(const t_list *line_list);


int	test_validate_line_list(void)
{
	fprintf(stderr, "\n===== test_validate_line list =====\n");
	test_validate_ambient();

	return (0);
}

int	case_validate_line(const char *test_path)
{
	int		result;
	t_list	*list;

	read_rt_file(&list, test_path);
	result = validate_line_list(list);
	ft_lstclear(&list, free);
	return (result);
}

