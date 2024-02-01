/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:01:17 by aapryce           #+#    #+#             */
/*   Updated: 2023/04/26 10:45:40 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total;
	size_t	i;
	void	*ptr;

	i = 0;
	total = nitems * size;
	ptr = malloc(total);
	if (nitems == SIZE_MAX && size == SIZE_MAX)
		return (0);
	if (ptr == NULL)
		return (0);
	while (i < total)
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
