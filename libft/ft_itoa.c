/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:17:30 by aapryce           #+#    #+#             */
/*   Updated: 2023/04/20 13:33:59 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlen(int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0 && base == 10)
		len++;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	const char	*digits;

	len = ft_intlen(n, 10);
	digits = "0123456789";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != '\0')
	{
		if (n > 0)
			str[--len] = digits[n % 10];
		else
			str[--len] = digits[n % 10 * -1];
		n = n / 10;
	}
	return (str);
}
