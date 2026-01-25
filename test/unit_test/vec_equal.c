/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:48:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/25 13:30:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_utils.h"
#include <stdbool.h>
#include <stddef.h>

bool	vec3_equal(t_vec3 a, t_vec3 b)
{
	return (length_squared_vec3(sub_vec3(b, a)) < 1e-5);
}
