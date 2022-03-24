#include "mlx.h"
#include "parse.h"
#include "x11_events.h"
#include "event.h"

static void	program_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
}

int	main(int argv, char **argc)
{
	int			fd;
	t_scene		*scene;
	t_obj_list	*info;
	t_mlx		mlx;

	fd = fd_get(argv, argc);
	info = info_get(fd);
	scene = parse_to_obj(info);

	program_init(&mlx);
	scene_draw(&mlx);

	mlx_hook(mlx.win, X11_KEYPRESS, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win, X11_CLOSEBTN, 1L << 2, exit_button, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
