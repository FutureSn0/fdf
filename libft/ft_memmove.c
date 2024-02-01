/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:18:46 by aapryce           #+#    #+#             */
/*   Updated: 2023/04/28 10:10:24 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (!dest || !src)
		return (dest);
	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	if (src_ptr < dest_ptr)
		while (n-- > 0)
			*(dest_ptr + n) = *(src_ptr + n);
	else
		while (n-- > 0)
			*(dest_ptr++) = *(src_ptr++);
	return (dest);
}
