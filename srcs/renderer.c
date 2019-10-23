/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:26:38 by merras            #+#    #+#             */
/*   Updated: 2019/10/23 22:55:54 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		renderer(t_complex m, void *r)
{
	int		i;
	int		j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			
			if (fractal_iterator(
				(t_complex){(R(r) - R(l)) / WINDOW_WIDTH * i + R(l),
				(R(t) - R(b)) / WINDOW_HEIGHT * (WINDOW_HEIGHT - j) + R(b)},
				m, r))
				mlx_pixel_put(R(mlx_ptr), R(win_ptr), (int)i, (int)j, 0);
			else
				mlx_pixel_put(R(mlx_ptr), R(win_ptr), (int)i, (int)j,
				0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	init_render_hooks(int f)
{
	t_render	r;

	r.fractal = f;
	r.scale = 1;
	r.l = -2;
	r.r = 2;
	r.b = -2;
	r.t = 2;
	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
				"fractol");
	renderer((t_complex){0, 0}, &r);
	mlx_hook(r.win_ptr, 6, 1, mouse_movement_hook, &r);
	mlx_hook(r.win_ptr, 4, 1, mouse_roller_hook, &r);
	mlx_loop(r.mlx_ptr);
}
