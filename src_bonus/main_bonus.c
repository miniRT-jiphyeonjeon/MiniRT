#include "mlx.h"
#include "parse_bonus.h"
#include "list_bonus.h"
#include "x11_events_bonus.h"
#include "event_bonus.h"
#include <stdio.h>

static void	program_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.width = WIN_WIDTH;
	mlx->img.height = WIN_HEIGHT;
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	mlx->background.img = mlx_xpm_file_to_image(
			mlx->mlx, "./input_bonus/galaxy.xpm", &mlx->background.width, &mlx->background.height);
	mlx->background.addr = mlx_get_data_addr(
			mlx->background.img, &mlx->background.bpp, &mlx->background.line, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
}

int	main(int argv, char **argc)
{
	int				fd;
	t_scene			*scene;
	t_parse_list	*info;
	t_mlx			mlx;

	fd = fd_get(argv, argc);
	info = parse_to_str(fd);
	scene = parse_to_element(info);
	del_obj_lst_parse(&info);
	program_init(&mlx);
	// void	*image_ptr;
	// int		width;
	// int		height;
	// image_ptr = mlx_xpm_file_to_image(mlx.mlx, "./input_bonus/galaxy.xpm", &width, &height);
	// printf("image_ptr %p\n", image_ptr);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, image_ptr, 0, 0);
	scene_draw(&mlx, scene);
	mlx_hook(mlx.win, X11_KEYPRESS, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win, X11_CLOSEBTN, 1L << 2, exit_button, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
