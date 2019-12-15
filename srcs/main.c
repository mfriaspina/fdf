/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:29:59 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/27 19:05:27 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		more(int key, t_fdf *fdf)
{
	if (key == 126)
		move(fdf->point, 'y', -50);
	if (key == 125)
		move(fdf->point, 'y', 50);
	if (key == 123)
		move(fdf->point, 'x', -50);
	if (key == 124)
		move(fdf->point, 'x', 50);
	if (key == 69)
		zoom(fdf->point, 'i', 2);
	if (key == 78)
		zoom(fdf->point, 'o', 2);
	if (key == 87)
		center(fdf->point);
	if (key == 31 || key == 51 || key == 34 || key == 35 || key == 14)
	{
		reset(fdf);
		if (key == 34)
			iso(fdf->point);
		if (key == 35)
			projection(fdf->point);
		if (key == 14)
			exagerate(fdf->point);
	}
}

static int		key_press(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 53)
		freefdf(fdf);
	if (keycode == 88)
		x_rotate(fdf->point, 45);
	if (keycode == 86)
		x_rotate(fdf->point, -45);
	if (keycode == 91)
		y_rotate(fdf->point, 45);
	if (keycode == 84)
		y_rotate(fdf->point, -45);
	if (keycode == 92)
		z_rotate(fdf->point, 45);
	if (keycode == 83)
		z_rotate(fdf->point, -45);
	more(keycode, fdf);
	print(fdf, fdf->point);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 200, 0);
	return (1);
}

void			readfile(t_fdf *fdf)
{
	int		fd;

	fdf->point = NULL;
	fd = open(fdf->file, O_RDONLY);
	if (fd == -1)
	{
		perror("Invalid source_file");
		exit(-1);
	}
	get_point(fd, &(fdf->point));
	get_nexty(fdf->point);
	close(fd);
}

static t_fdf	*fdf_init(char *file)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
	{
		perror("ERR_FDF_INIT");
		exit(0);
	}
	if (!(fdf->mlx = mlx_init()))
	{
		perror("ERR_MLX_INIT");
		exit(0);
	}
	if (!(fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "fdf")))
	{
		perror("ERR_WIN_INIT");
		exit(0);
	}
	if (!(fdf->img = mlx_new_image(fdf->mlx, 1720, 1080)))
		perror("ERR_IMG_INIT");
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->size),
									&(fdf->endian));
	fdf->file = file;
	readfile(fdf);
	return (fdf);
}

int				main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		perror("Usage: ./fdf source_file");
		exit(0);
	}
	fdf = fdf_init(argv[1]);
	print(fdf, fdf->point);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 200, 0);
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
