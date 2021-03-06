/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:31:04 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:32:42 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include "vector3.h"

t_bool	hit_plane(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	double	numerator;
	double	denominator;
	double	root;
	t_plane	*pl;

	pl = (t_plane *)objects->object;
	denominator = vec3_dot(ray->direction, pl->normal);
	if (denominator == 0)
		return (FALSE);
	numerator = -1 * vec3_dot(vec3_minus(ray->origin, pl->point), pl->normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->normal;
	face_normal_set(ray, rec);
	rec->color = objects->color;
	return (TRUE);
}
