/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:44:34 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 22:09:26 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "vector3_bonus.h"

t_vec3	vec3_mult_scalar(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec3	vec3_mult(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
}

t_vec3	vec3_divide_scalar(t_vec3 vec, double t)
{
	if (!t)
	{
		ft_write(2, "Error\n:Divider is 0\n");
		exit(1);
	}
	return (vec3_mult_scalar(vec, 1 / t));
}

/*	Vector inner product
	A・B = |A||B|cos⍬ = x1x2 + y1y2 + z1z2
*/
double	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

/*	Vecotr outer product
	A✕B = \vec{n}|A||B|sin⍬ = (y1z1 - z1y2, z1x2 - x1z2, x1y2 - y1x2)
*/
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.y * vec2.z - vec1.z * vec2.y;
	new.y = vec1.z * vec2.x - vec1.x * vec2.z;
	new.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (new);
}
