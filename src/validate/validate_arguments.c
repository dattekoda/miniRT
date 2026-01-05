/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:05:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 21:21:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_rt.h"
#include <stdlib.h>

int	validate_file_name(const char *argv_one);

/*
@brief validate function
@param argv_one argv[1]
*/
int	validate_arguments(int argc, char *argv[])
{
	if (argc == 1)
		return (FAILURE);
	if (validate_file_name(argv[1]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
