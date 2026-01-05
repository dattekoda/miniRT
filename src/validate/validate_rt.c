/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:05:57 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/05 11:28:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	validate_file_name(const char *argv_one);

int	validate_rt(const char *argv_one)
{
	if (validate_file_name(argv_one))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
