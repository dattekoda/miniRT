/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_line_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:56:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/08 12:29:01 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void		read_rt_file(t_list **line_list, const char *file_path);
int			validate_line_list(const t_list *line_list);
static int	case_validate_line(const char *test_path);

int	test_validate_line_list(void)
{
	fprintf(stderr, "\n===== test_validate_line list =====\n");
	ft_putendl_fd("\n===== normal case =====\n", STDERR_FILENO);
	assert(case_validate_line("./test_scene/success1.rt") == SUCCESS);
	assert(case_validate_line("./test_scene/success2.rt") == SUCCESS);
	assert(case_validate_line("./test_scene/success3.rt") == SUCCESS);
	ft_putendl_fd("\n===== error case =====\n", STDERR_FILENO);
	assert(case_validate_line("./test_scene/failure1.rt") == FAILURE);
	assert(case_validate_line("./test_scene/failure2.rt") == FAILURE);
	assert(case_validate_line("./test_scene/failure3.rt") == FAILURE);
	return (0);
}

static int	case_validate_line(const char *test_path)
{
	int		result;
	t_list	*list;

	// alarm(5);
	read_rt_file(&list, test_path);
	result = validate_line_list(list);
	ft_lstclear(&list, free);
	// alarm(0);
	return (result);
}

// /*
// testcase名をディレクトリに応じて取得する関数*/
// int	set_file_names(const char *path, char ***test_case_ptr)
// {
// 	struct dirent *entry;

// 	dir = opendir(path);
// 	if (dir == NULL) {
// 		perror("opendir");
// 		return;
// 	}
// 	while ((entry = readdir(dir)) != NULL) {
// 		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
// 			continue;
// 		test_case = (char **)realloc(test_case, )
// 		// ここ途中！！
// 	}
// 	closedir(dir);
// }