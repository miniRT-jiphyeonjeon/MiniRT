/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:43:24 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:43:24 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_BONUS_H
# define VECTOR3_BONUS_H

# include "structure_bonus.h"

// vector_set_bonus

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
void		vec3_set(t_vec3 *vec, double x, double y, double z);
void		coordinate_system(t_vec3 *u, t_vec3 *v, t_vec3 w);

// vector_operation1_bonus

t_bool		is_vec_equal(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_plus_scalar(t_vec3 vec, double x, double y, double z);
t_vec3		vec3_plus(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_minus_scalar(t_vec3 vec, double x, double y, double z);
t_vec3		vec3_minus(t_vec3 vec1, t_vec3 vec2);

// vector_operation2_bonus

t_vec3		vec3_mult_scalar(t_vec3 vec, double t);
t_vec3		vec3_mult(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_divide_scalar(t_vec3 vec, double t);
double		vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_cross(t_vec3 vec1, t_vec3 vec2);

// vector_operation3_bonus

double		vec3_length_square(t_vec3 vec);
double		vec3_length(t_vec3 vec);
t_vec3		vec3_unit(t_vec3 vec);
t_vec3		vec3_min(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_up(t_vec3 vec);

// vector_matrix_bonus

t_mat3		mat3_set(t_vec3 vec1, t_vec3 vec2, t_vec3 vec3);
t_vec3		mat3_mult_vec3(t_mat3 mat, t_vec3 vec);

#endif
