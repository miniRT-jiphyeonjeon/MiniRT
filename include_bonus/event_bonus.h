#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1500

# include "structure_bonus.h"

// draw.c

void	scene_draw(t_mlx *mlx, t_scene *scene);
int		color3_to_pixel(t_color3 color);
int		xpm_pixel_get(t_xpm_image *image, int x, int y);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		oversampling(t_xpm_image *image, int x, int y);

// hook_key_n_exit.c

int		key_press(int keycode, t_mlx *mlx);
int		exit_button(void);

#endif
