#include "cjang_test.h"
#include <math.h>

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

void	scene_circle_set(t_param *par)
{
	unsigned int	color;
	int				idx;
	double			h_ratio;
	double			w_ratio;
	double			x_ratio;
	double			tx;
	double			ty;
	double			r;

	for (int x = 0; x < SQUARE_SIZE; x++)
	{
		for (int y = 0; y < SQUARE_SIZE; y++)
		{
			tx = x - SQUARE_SIZE/2;
			ty = y - SQUARE_SIZE/2;
			r = SQUARE_SIZE / 4;
			if (tx*tx + ty*ty >= r*r)
				mlx_pixel_put(par->mlx_ptr, par->win_ptr, x, y, 0x00555555);
			else
			{
				x_ratio = sqrt(r*r - ty*ty);
				h_ratio = (double)par->height / SQUARE_SIZE * 2;
				w_ratio = (double)par->width / x_ratio / 2;
				idx = par->size_l / 4 * (int)((y - r) * h_ratio) + (int)((x - 2*r + x_ratio) * w_ratio);
				color = par->img_info[idx];
				mlx_pixel_put(par->mlx_ptr, par->win_ptr, x, y, color);
			}
		}
	}
}

int	main(void)
{
	t_param		param;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, SQUARE_SIZE, SQUARE_SIZE, "cjang_test");
	param.img_ptr = mlx_png_file_to_image(param.mlx_ptr, "earth.png", &param.width, &param.height);
	if (param.img_ptr == NULL)
		return (1);
	param.img_info = (unsigned int *)mlx_get_data_addr(param.img_ptr, &param.bpp, &param.size_l, &param.endian);
	// scene_set(&param);
	scene_circle_set(&param);

	// img_print(&param);
	mlx_hook(param.win_ptr, 17, 0, sol_close, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
