#ifndef CJANG_TEST_H
# define CJANG_TEST_H

# define SQUARE_SIZE 300
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

# include "../lib/mlx_mms/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				height;
	int				width;
	unsigned int	*img_info;
	int				bpp;
	int				size_l;
	int				endian;
}t_param;

#endif
