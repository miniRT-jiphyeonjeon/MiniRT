/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:41:30 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:41:30 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_bonus.h"
#include "libft.h"

static int	color_calc(double rgb)
{
	return (clamp((int)(256 * rgb), 0, 255));
}

int	color3_to_pixel(t_color3 color)
{
	int	pixel;

	pixel = 0;
	pixel |= color_calc(color.x) << 16;
	pixel |= color_calc(color.y) << 8;
	pixel |= color_calc(color.z);
	return (pixel);
}

int	xpm_pixel_get(t_xpm_image *image, int x, int y)
{
	char	*dst;

	x = clamp(x, 0, image->width - 1);
	y = clamp(y, 0, image->height - 1);
	dst = image->data.addr + (y * image->data.line + x * (image->data.bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
