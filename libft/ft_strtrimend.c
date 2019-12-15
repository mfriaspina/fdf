/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:40:54 by mfrias            #+#    #+#             */
/*   Updated: 2019/05/17 12:45:16 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimend(char const *s, char c)
{
	char	*str;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == c)
		len--;
	if (len <= 0)
		len = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
