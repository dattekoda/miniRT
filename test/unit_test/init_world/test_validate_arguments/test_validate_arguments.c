/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_arguments.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:34:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 01:34:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_is_valid_file_name(void);
int	test_is_valid_option(void);

int	test_validate_arguments(void)
{
	test_is_valid_file_name();
	test_is_valid_option();
	return (0);
}
