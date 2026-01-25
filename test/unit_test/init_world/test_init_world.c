/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:46:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:45:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_validate_arguments(void);
int	test_set_option(void);
int	test_skips(void);

int	test_init_world(void)
{
	test_validate_arguments();
	test_set_option();
	test_skips();
	return (0);
}
