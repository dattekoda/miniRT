/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:51:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:55:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_match_identifer(void); // test_utilsとかのほうがいいか
int	test_set_ambient(void);
int	test_set_camera(void);
int	test_set_light(void);
int	test_set_objects(void);

int	test_create_world(void)
{
	test_set_ambient();
	test_set_camera();
	test_set_light();
	test_set_objects();
	return (0);
}