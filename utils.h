/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:47:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/11/16 12:09:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

// utils_set.c
int	set_content(char **content, const char *file_name);

// utils0.c
int	minirt_strrncmp(const char *s1, const char *s2, size_t n);

#endif