/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_line_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:56:03 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/07 20:00:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include "libft.h"
#include <assert.h>

#define TEST_SCENE_DIR ""

void		read_rt_file(t_list **line_list, const char *file_path);
int			validate_line_list(const t_list *line_list);
static void test_case_validate_line_list(const char **test_case, int expected);

int	test_validate_line_list(void)
{
	static const char	*test_success[] = \
{"./test_scene/success1.rt", "./test_scene/success2.rt", "./test_scene/success3.rt", NULL};
	static const char	*test_failure[] = \
{"./test_scene/failure1.rt", "./test_scene/failure2.rt", "./test_scene/failure3.rt", NULL};
	
	fprintf(stderr, "\n===== test_validate_line list =====\n");
	ft_putendl_fd("\n===== normal case =====\n", STDERR_FILENO);
	test_case_validate_line_list(test_success, SUCCESS);
	ft_putendl_fd("\n===== error case =====\n", STDERR_FILENO);
	test_case_validate_line_list(test_failure, FAILURE);
	return (0);
}

static void	test_case_validate_line_list(const char **test_case, int expected)
{
	t_list	*list;
	size_t	i;

	alarm(5);
	i = 0;
	while (test_case[i])
	{
		read_rt_file(&list, test_case[i]);
		assert(validate_line_list(list) == expected);
	}
	alarm(0);
}

/*
testcase名をディレクトリに応じて取得する関数*/
int	set_file_names(const char *path, char ***test_case_ptr) {
	DIR *dir;
	struct dirent *entry;

	dir = opendir(path);
	if (dir == NULL) {
		perror("opendir");
		return;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		test_case = (char **)realloc(test_case, )
		// ここ途中！！
	}
	closedir(dir);
}