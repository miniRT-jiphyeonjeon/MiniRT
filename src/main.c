#include "minirt.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "miniRT");

	mlx_loop(mlx_ptr);
	return (0);
} 