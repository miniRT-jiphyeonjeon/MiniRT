/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_n_exit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojekim <hyojekim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:41:54 by hyojekim          #+#    #+#             */
/*   Updated: 2022/04/17 21:41:54 by hyojekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
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
