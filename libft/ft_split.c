/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:11:09 by aapryce           #+#    #+#             */
/*   Updated: 2023/05/05 14:34:10 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	ft_len(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			++res;
			while (*s != '\0' && *s != c)
				++s;
		}
		else
			++s;
	}
	return (res);
}

static size_t	ft_substrlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**ft_free_split(char **s, int len)
{
	while (len--)
		free(s[len]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	res = (char **)malloc(sizeof(char *) * (ft_len(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = ft_substrlen(s, c);
			res[i++] = ft_substr(s, 0, len);
			if (!res[i - 1])
				return (ft_free_split(res, i));
			s = s + len;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
