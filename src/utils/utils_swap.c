/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:53:36 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/19 21:01:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
@brief set appropriate size like double, t_foo... then swap a and b
*/
void	rt_swap(void *a, void *b, size_t size)
{
	unsigned char	*_a;
	unsigned char	*_b;
	unsigned char	tmp;
	size_t			i;

	_a = a;
	_b = b;
	i = 0;
	while (i < size)
	{
		tmp = _a[i];
		_a[i] = _b[i];
		_b[i] = tmp;
		i++;
	}
	return ;
}
