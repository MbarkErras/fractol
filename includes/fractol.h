/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:32:18 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 07:08:05 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/centropy/includes/centropy.h"
# include <stdio.h>
# include "mlx.h"

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITER 50
# define ZOOM_IN 1.1
# define ZOOM_OUT 0.9
# define INIT_XY 1

void	mandelbrot();
void	julia();
void	tree_index();

# define MANDELBROT 0
# define JULIA 1
# define TREE_INDEX 2


typedef struct	s_complex
{
	long double r;
	long double i;
}				t_complex;

typedef struct	s_xy
{
	int			fractol;
	int			height;
	int			width;
	double    r_max;
	double    r_min;
	double    i_max;
	double    i_min;

	void		*gserver;
	void		*win;
}				t_xy;

# define distance(r, i) r * r + i * i

t_xy	init_renderer(int fractol);
int		rerender_handler(int button, int x, int y, t_xy *xy);
int		convergence(double r, double i);

void    mandelbrot_render_handler(int button, int x, int y, t_xy *xy);
//void    julia_renderer(int button, int x, int y, t_xy *xy);
//void   tree_index_renderer(int button, int x, int y, t_xy *xy);
#endif
