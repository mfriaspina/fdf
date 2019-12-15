/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:08:35 by mfrias            #+#    #+#             */
/*   Updated: 2019/06/29 16:05:10 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_newpoint(int x, int y, int z)
{
	t_point	*new;

	new = (t_point *)ft_memalloc(sizeof(t_point));
	new->x = x * 16;
	new->y = y * 16;
	new->z = z;
	new->end = 0;
	new->next = NULL;
	new->nexty = NULL;
	return (new);
}

void	ft_addpoint(t_point **alst, t_point *new)
{
	new->next = *alst;
	*alst = new;
}

void	get_point(int fd, t_point **list)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	y = 0;
	while (get_next_line(fd, &str))
	{
		x = 0;
		i = 0;
		while (str[i])
		{
			if (ft_isdigit(str[i]) || str[i] == '-')
			{
				ft_addpoint(list, ft_newpoint(x++, y, ft_atoi(&str[i])));
				i += ft_strsize(&str[i], ' ');
			}
			else
				i++;
		}
		y++;
		ft_strdel(&str);
	}
}

void	get_nexty(t_point *list)
{
	t_point	*next;

	next = list;
	while (list->y != 0)
	{
		if (list->y != list->next->y)
			list->end = 1;
		next = list->next;
		while (list->x != next->x)
			next = next->next;
		list->nexty = next;
		list = list->next;
	}
}
