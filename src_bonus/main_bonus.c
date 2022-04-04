#include "mlx.h"
#include "parse_bonus.h"
#include "list_bonus.h"
#include "x11_events_bonus.h"
#include "event_bonus.h"

static void	background_init(t_mlx *mlx)
{
	mlx->background.data.img = mlx_xpm_file_to_image(mlx->mlx,
			"./input_bonus/galaxy.xpm",
			&mlx->background.width, &mlx->background.height);
	mlx->background.data.addr = mlx_get_data_addr(
			mlx->background.data.img, &mlx->background.data.bpp,
			&mlx->background.data.line, &mlx->background.data.endian);
	mlx->background.ratio_w = (double)mlx->background.width / (double)WIN_WIDTH;
	mlx->background.ratio_h
		= (double)mlx->background.height / (double)WIN_HEIGHT;
}

static void	program_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	background_init(mlx);
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
	scene_draw(&mlx, scene);
	mlx_hook(mlx.win, X11_KEYPRESS, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win, X11_CLOSEBTN, 1L << 2, exit_button, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
