/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mini_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:23:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/28 17:06:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_init_world(void);
int	test_unit(void);
int	test_integration(void);

int	test_mini_rt(void)
{
	test_unit();
	test_integration();
	return (0);
}
