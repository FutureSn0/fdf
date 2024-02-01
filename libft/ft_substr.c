/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:17:21 by aapryce           #+#    #+#             */
/*   Updated: 2023/05/09 09:28:30 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sarr;

	i = 0;
	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sarr = (char *)malloc(len + 1);
	if (sarr == NULL)
		return (0);
	while (i < len)
		sarr[i++] = s[start++];
	sarr[i] = '\0';
	return (sarr);
}
