/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:15:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 16:17:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_define.h"
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
		if (validate_line(argv[i]) == 1)
			validate_flag = FAILURE;
		i++;
	}
	if (validate_flag == 0)
		printf("success\n");
	return (validate_flag);
}
