/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:29:37 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:29:37 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	color_calc(double rgb)
{
	int	color;

	color = (int)(256 * rgb);
	if (color > 255)
		color = 255;
	return (color);
}
