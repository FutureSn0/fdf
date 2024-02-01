/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:22:32 by aapryce           #+#    #+#             */
/*   Updated: 2023/04/13 13:55:18 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = str;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = (unsigned char) c;
		i++;
	}
	return (ptr);
}
