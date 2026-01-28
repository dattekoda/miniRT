/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:51:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 11:29:19 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_match_identifer(void); // test_utilsとかのほうがいいか
int	test_set_ambient(void);
int	test_set_camera(void);
int	test_set_light(void);
int	test_set_objects(void);


#include <stdio.h>
int	test_create_world(void)
{
	test_set_ambient();
	test_set_camera();
	test_set_light();
	test_set_objects();
	return (0);
}