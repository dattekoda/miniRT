/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hitter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:02:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/11 19:41:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hitter.h"
#include <stdio.h>

/*

typedef enum e_element_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	DISK,
	CONE,
	TRIANGLE,
	NOTHING
}	t_element_type;
*/
void	print_hitter(t_hitter *hitter)
{
	static const char *string_table[] = {
		"AMBIENT",
		"CAMERA",
		"LIGHT",
		"SPHERE",
		"PLANE",
		"CYLINDER",
		"DISK",
		"CONE",
		"TRIANGLE",
		"NOTHING"
	};
	printf("%u\n", hitter->type);
	printf("%s\n", string_table[hitter->type]);
}
