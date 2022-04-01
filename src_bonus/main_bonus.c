#include "mlx.h"
#include "parse_bonus.h"
#include "list_bonus.h"
#include "x11_events_bonus.h"
#include "event_bonus.h"

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
