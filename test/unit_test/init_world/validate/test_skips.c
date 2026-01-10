/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_skips.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:41:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/10 20:31:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_skip_spaces(void);
int	test_line_to_value(void);
int	test_skip_range(void);
int	test_skip_point(void);
int	test_skip_unit(void);
int	test_skip_color(void);
int	test_skip_until_end(void);

int	test_skips(void)
{
	test_skip_spaces();
	test_line_to_value();
	test_skip_range();
	test_skip_point();
	test_skip_unit();
	test_skip_color();
	test_skip_until_end();
	return (0);
}

