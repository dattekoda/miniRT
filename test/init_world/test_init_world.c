/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:46:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 11:57:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	test_utils(void);
int	test_validate_arguments(void);
int	test_set_option(void);
int	test_is_valid_line_list(void);
int	test_create_world(void);

int	test_init_world(void)
{
	test_validate_arguments();
	test_set_option();
	test_skips();
	test_create_world();
	return (0);
}

int	test_match_identifer(void);

static int	test_utils(void)
{
	test_match_identifer();
	return (0);
}
