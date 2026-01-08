/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:17:14 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/07 20:04:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_RT_H
# define VALIDATE_RT_H

# include <stdbool.h>

int		validate_ambient(char *line);
int		validate_camera(char *line);
int		validate_light(char *line);
int		validate_plane(char *line);
int		validate_sphere(char *line);
int		validate_cylinder(char *line);
int		validate_cone(char *line);
int		validate_triangle(char *line);

#endif
