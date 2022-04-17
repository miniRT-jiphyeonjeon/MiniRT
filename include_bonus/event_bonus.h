/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:50:12 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:50:12 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# define X11_KEYPRESS	2
# define X11_CLOSEBTN	17
# define KEY_ESC		53

# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000

# include "structure_bonus.h"

// draw_bonus & draw_util_bonus

void	scene_draw(t_mlx *mlx, t_scene *scene);
int		color3_to_pixel(t_color3 color);
int		xpm_pixel_get(t_xpm_image *image, int x, int y);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

// hook_key_n_exit_bonus

int		key_press(int keycode, t_mlx *mlx);
int		exit_button(void);

#endif
