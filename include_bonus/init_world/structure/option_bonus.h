/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:39:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:13:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_BONUS_H
# define OPTION_BONUS_H

enum e_option
{
	OPT_ARTIFICIAL = (1 << 0),
	OPT_MATERIAL = (1 << 1),
	OPT_PPM = (1 << 2),
};

typedef struct s_option
{
	char			*str;
	enum e_option	flag;
}	t_option;

#endif
