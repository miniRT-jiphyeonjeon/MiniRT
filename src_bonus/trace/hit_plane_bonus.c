/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:46:19 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:48:30 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "trace_bonus.h"
#include "vector3_bonus.h"
#include "libft.h"

static void	plane_uv(t_hit_record *rec)
{
	coordinate_system(&rec->u_dir, &rec->v_dir, rec->normal);
	rec->u = ft_fmod_abs(fmod(vec3_dot(rec->p, rec->u_dir), 1), 1);
	rec->v = ft_fmod_abs(fmod(vec3_dot(rec->p, rec->v_dir), 1), 1);
}

t_bool	hit_plane(t_obj_list objects[], t_ray *ray, t_hit_record *rec)
{
	double		numerator;
	double		denominator;
	double		root;
	t_object	*pl;

	pl = (t_object *)objects->object;
	denominator = vec3_dot(ray->direction, pl->normal);
	if (denominator == 0)
		return (FALSE);
	numerator = -1 * vec3_dot(vec3_minus(ray->origin, pl->center), pl->normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->normal;
	rec->obj = pl;
	face_normal_set(ray, rec);
	plane_uv(rec);
	hit_color_set(rec, objects);
	return (TRUE);
}
