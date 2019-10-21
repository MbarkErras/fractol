/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:31:26 by merras            #+#    #+#             */
/*   Updated: 2019/10/21 13:29:01 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage()
{
	ft_putendl("./fractol <name>");
	ft_putendl("options:");
	ft_putendl("\tmandelbrot");
	ft_putendl("\tjulia");
	ft_putendl("\ttree_index");
}

void	render_fractal(char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		render_wrapper(MAND);
	else if (!ft_strcmp(name, "julia"))
		render_wrapper(JULI);
	else if (!ft_strcmp(name, "tree_index"))
		render_wrapper(TREE);
	else
		print_usage();
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage();	
		return (0);
	}
	render_fractal(argv[1]);
}
