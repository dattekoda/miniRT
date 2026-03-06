/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:50:47 by khanadat          #+#    #+#             */
/*   Updated: 2026/03/04 15:33:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_TYPE_H
# define ELEMENT_TYPE_H

typedef enum e_element_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	DISK,
	CONE,
	TRIANGLE,
	TREE,
	LIST,
	NOTHING
}	t_element_type;

#endif
