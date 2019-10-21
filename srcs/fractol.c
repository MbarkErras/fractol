/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:31:26 by merras            #+#    #+#             */
/*   Updated: 2019/06/26 03:28:25 by merras           ###   ########.fr       */
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
		mandelbrot();
	/*else if (!ft_strcmp(name, "julia"))
		julia();
	else if (!ft_strcmp(name, "tree_index"))
		tree_index();*/
	else
		print_usage();
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		print_usage();	
		return (0);
	}
	render_fractal(av[1]);
}