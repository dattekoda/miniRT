/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_line_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:56:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 01:02:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	read_rt_file(t_list **line_list, const char *file_path);
int		validate_line_list(const t_list *line_list);
int		test_validate_ambient(void);
int		test_validate_camera(void);

int	test_validate_line_list(void)
{
	fprintf(stderr, "\n===== test_validate_line list =====\n");
	test_validate_ambient();
	test_validate_camera();
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

