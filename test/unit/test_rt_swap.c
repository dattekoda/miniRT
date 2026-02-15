/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rt_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:19:27 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/15 21:26:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>

void	rt_swap(void *a, void *b, size_t size);

void	test_rt_swap(void)
{
	char	a[] = "aaa";
	char	b[] = "bbb";

	rt_swap(a, b, sizeof(char) * 3);
	assert(memcmp(b, "aaa", sizeof(char) * 3) == 0);
	assert(memcmp(a, "bbb", sizeof(char) * 3) == 0);
}
