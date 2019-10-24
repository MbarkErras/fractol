/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:32:18 by merras            #+#    #+#             */
/*   Updated: 2019/10/24 00:36:41 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/centropy/includes/centropy.h"
# include "mlx.h"

# define WINDOW_WIDTH 250
# define WINDOW_HEIGHT 250

# define INTER 1.1

# define MAX_ITERATIONS 50

# define R(x) (((t_render *)r)->x)

# define MAND 0
# define JULI 1
# define CUBE 2

typedef struct	s_complex
{
	double		im;
	double		re;
}				t_complex;

typedef	struct	s_render
{
	int			fractal;
	void		*mlx_ptr;
	void		*win_ptr;
	double		scale;
	double		l;
	double		r;
	double		t;
	double		b;
}				t_render;

int				fractal_iterator(t_complex c, t_complex m, void *r);

void			init_render_hooks(int f);
void			renderer(t_complex m, void *r);

t_complex		mouse_coordinate_map(int x, int y, void *r);
int				mouse_movement_hook(int x, int y, void *r);
int				mouse_roller_hook(int button, int x, int y, void *r);
int				esc_handler(int keycode, void *r);

t_render		*render_config(t_render *set);

# define COLOR_ONE 0xFFFFFF
# define COLOR_TWO 0xFFC0CB
# define COLOR_THREE 0x800080
# define COLOR_FOUR 0x008B8B

# define IS_COLOR_FOUR(x) (x == 4 ? COLOR_FOUR : 0)
# define IS_COLOR_THREE(x) (x == 3 ? COLOR_THREE : IS_COLOR_FOUR(x))
# define IS_COLOR_TWO(x) (x == 2 ? COLOR_TWO : IS_COLOR_THREE(x))
# define COLOR_PICKER(x) (x == 1 ? COLOR_ONE : IS_COLOR_TWO(x))

#endif
