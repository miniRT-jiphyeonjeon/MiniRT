/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:19:25 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:58:11 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# define X11_KEYPRESS	2
# define X11_CLOSEBTN	17
# define KEY_ESC		53

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# include "structure.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	img;
}	t_mlx;

// draw & draw_util

void	scene_draw(t_mlx *mlx, t_scene *scene);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		color_calc(double rgb);

// hook_key_n_exit

int		key_press(int keycode, t_mlx *mlx);
int		exit_button(void);

#endif
