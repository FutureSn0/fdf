/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:43:00 by aapryce           #+#    #+#             */
/*   Updated: 2023/05/09 09:31:21 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest)
		return (0);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*arr;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	len = end - start + 1;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	ft_strncpy(arr, start, len);
	arr[len] = '\0';
	return (arr);
}
