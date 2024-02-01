/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:44:04 by aapryce           #+#    #+#             */
/*   Updated: 2023/05/05 13:16:04 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!str || !to_find) && len == 0)
		return (NULL);
	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && i + j < len)
			j++;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
		j = 0;
	}
	return (0);
}
