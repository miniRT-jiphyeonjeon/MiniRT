#ifndef EVENT_H
# define EVENT_H

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

int	key_press(int keycode, t_mlx *mlx);
int	exit_button(void);

#endif