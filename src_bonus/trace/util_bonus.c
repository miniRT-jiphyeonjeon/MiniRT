/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:51:02 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:51:02 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"

double	root(t_eq eq, t_root_type type)
{
	double	discriminant;
	double	sqrt_d;

	discriminant = eq.half_b * eq.half_b - eq.a * eq.c;
	if (discriminant < 0)
		return (NAN);
	sqrt_d = sqrt(discriminant);
	if (type == ALPHA)
		return ((eq.half_b * (-1) - sqrt_d) / eq.a);
	if (type == BETA)
		return ((eq.half_b * (-1) + sqrt_d) / eq.a);
	return (NAN);
}

void	face_normal_set(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = vec3_dot(ray->direction, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vec3_mult_scalar(rec->normal, -1);
}
