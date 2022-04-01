#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# define WIN_WIDTH	1280
# define WIN_HEIGHT	1280

# include "structure_bonus.h"

// draw.c

void	scene_draw(t_mlx *mlx, t_scene *scene);
int		color_calc(double rgb);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		my_mlx_pixel_get(t_image *image, int x, int y);

// hook_key_n_exit.c

int		key_press(int keycode, t_mlx *mlx);
int		exit_button(void);

#endif
