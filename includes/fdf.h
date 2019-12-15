/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:36:40 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/27 18:59:54 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				end;
	struct s_point	*next;
	struct s_point	*nexty;
}					t_point;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
	char			*file;
	t_point			*point;
}					t_fdf;

void				readfile(t_fdf *fdf);

void				pixel_put(t_fdf *fdf, t_point a, t_point b);
void				line_img(t_fdf *fdf, t_point a, t_point b);
void				print(t_fdf *fdf, t_point *list);
void				menu(t_fdf *fdf);
void				reset(t_fdf *fdf);

t_point				*ft_newpoint(int x, int y, int z);
void				ft_addpoint(t_point **alst, t_point *new);
void				get_point(int fd, t_point **list);
void				get_nexty(t_point *list);

void				projection(t_point *point);
void				iso(t_point *point);
void				x_rotate(t_point *point, int angle);
void				y_rotate(t_point *point, int angle);
void				z_rotate(t_point *point, int angle);

void				exagerate(t_point *point);
void				move(t_point *point, char axis, int distance);
void				zoom(t_point *point, char direction, int magnitude);
void				center(t_point *point);

void				freepoint(t_point *head);
void				freefdf(t_fdf *fdf);

#endif
