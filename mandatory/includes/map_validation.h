/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/09 04:40:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

t_map_dimensions	read_map(t_data *mlx, char *map_path);
void				map_components_init(t_valid_components *map_components);
void				map_dimensions_init(t_map_dimensions *map_dimensions);
void				assign_map_dimensions(t_map_dimensions *map_dimensions,
						t_valid_components map_components);
int					is_valid_map_component(int component);
int					is_valid_component(int component);
int					map_has_minimal_components(
						t_valid_components *map_components);
int					is_rectangule(t_valid_components *map_components);
int					check_is_valid_map(t_valid_components *map_components);
void				check_map_validators(t_valid_components *map_components,
						char *map_line, int is_eof);
void				check_is_surrounded_by_wall(
						t_valid_components *map_components,
						t_map_dimensions current_map_dimensions,
						char component);
void				check_is_rectangule(t_valid_components *map_components,
						t_map_dimensions current_map_dimensions, int is_eof);
void				check_minimal_components(t_valid_components *map_components,
						char component);
void				destroy_map_matrix(t_map_dimensions *map_dimensions);
#endif //MAP_VALIDATION_H