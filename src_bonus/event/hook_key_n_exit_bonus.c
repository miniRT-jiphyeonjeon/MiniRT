#include <stdlib.h>
#include "mlx.h"
#include "x11_events_bonus.h"
#include "event_bonus.h"

int	key_press(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	exit_button(void)
{
	exit(0);
}
