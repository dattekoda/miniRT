/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:01:32 by khanadat          #+#    #+#             */
/*   Updated: 2026/01/28 17:47:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_init_world(void);

int	test_match_identifer(void);
int	test_skip_spaces(void);
int	test_token_to_value(void);
// valiate_line_list
int	test_skip_range(void);
int	test_skip_point(void);
int	test_skip_unit(void);
int	test_skip_color(void);
int	test_skip_until_end(void);
// validate_arguments()
int	test_is_valid_file_name(void);
int	test_is_valid_option(void);

int	test_set_option(void);
int	test_read_rt_file(void);
// create_world()
int	test_get_ambient_data(void);
int	test_get_camera_data(void);
int	test_add_light_radius(void);
int	test_line_to_light(void);

int	test_unit(void)
{
	// utils
	test_match_identifer();
	// validate_arguments
	test_is_valid_file_name();
	test_is_valid_option();
	// validate_line_list(skips)
	test_skip_spaces();
	test_token_to_value();
	test_skip_range();
	test_skip_point();
	test_skip_unit();
	test_skip_color();
	test_skip_until_end();

	test_set_option();
	test_read_rt_file();

	test_get_ambient_data();
	test_get_camera_data();
	
	test_add_light_radius();
	test_line_to_light();
	return (0);
}
