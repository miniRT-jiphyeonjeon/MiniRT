/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_matrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:44:28 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:44:28 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3_bonus.h"

t_mat3	mat3_set(t_vec3 vec1, t_vec3 vec2, t_vec3 vec3)
{
	static double	mat[3][3];

	mat[0][0] = vec1.x;
	mat[1][0] = vec1.y;
	mat[2][0] = vec1.z;
	mat[0][1] = vec2.x;
	mat[1][1] = vec2.y;
	mat[2][1] = vec2.z;
	mat[0][2] = vec3.x;
	mat[1][2] = vec3.y;
	mat[2][2] = vec3.z;
	return (mat);
}

t_vec3	mat3_mult_vec3(t_mat3 mat, t_vec3 vec)
{
	t_vec3	res;

	res.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z;
	res.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z;
	res.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z;
	return (res);
}
