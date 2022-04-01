#include "cjang_test.h"

static int	sol_close(t_param *par)
{
	mlx_destroy_window(par->mlx_ptr, par->win_ptr);
	exit(0);
	return (0);
}

void	img_print(t_param *par)
{
	printf("<%d %d %d>\n", par->bpp, par->size_l, par->endian);
	for (int h = 0; h < par->height; h++)
	{
		for (int w = 0; w < par->width; w++)
		{
			printf("[%x]", par->img_info[par->size_l / 4 * h + w]);
		}
		printf("\n");
	}
}

void	scene_set(t_param *par)
{
	unsigned int	color;
	int				idx;
	double			h_ratio;
	double			w_ratio;

	h_ratio = (double)par->height / SQUARE_SIZE;
	w_ratio = (double)par->width / SQUARE_SIZE;
	for (int x = 0; x < SQUARE_SIZE; x++)
	{
		for (int y = 0; y < SQUARE_SIZE; y++)
		{
			idx = par->size_l / 4 * (int)(y * h_ratio) + (int)(x * w_ratio);
			color = par->img_info[idx];
			mlx_pixel_put(par->mlx_ptr, par->win_ptr, x, y, color);
		}
	}
}

int	main(void)
{
	t_param		param;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, SQUARE_SIZE, SQUARE_SIZE, "cjang_test");
	param.img_ptr = mlx_png_file_to_image(param.mlx_ptr, "6by6.png", &param.width, &param.height);
	if (param.img_ptr == NULL)
		return (1);
	param.img_info = (unsigned int *)mlx_get_data_addr(param.img_ptr, &param.bpp, &param.size_l, &param.endian);
	scene_set(&param);

	// img_print(&param);
	mlx_hook(param.win_ptr, 17, 0, sol_close, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
