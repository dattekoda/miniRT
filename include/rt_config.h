/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:59:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/01/16 17:27:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CONFIG_H
# define RT_CONFIG_H

// camera
# ifndef ASPECT_RATIO
#  define ASPECT_RATIO 1.77777777778 /*  (16.0 / 9.0)  */
# endif

# ifndef LENS_RADIUS
#  define LENS_RADIUS 0.0
# endif

// light
# define LIGHT_RADIUS 100.0

#endif
