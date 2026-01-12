/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:15:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/12 14:23:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include <stdio.h>

int	validate_line(char *line);

int	main(int argc, char *argv[])
{
	int	validate_flag;
	int	i;

	validate_flag = SUCCESS;
	i = 1;
	while (i < argc)
	{
		if (validate_line(argv[i]) == FAILURE)
			validate_flag = FAILURE;
		i++;
	}
	if (validate_flag == 0)
		printf("success\n");
	return (validate_flag);
}
