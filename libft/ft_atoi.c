/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:54:25 by aapryce           #+#    #+#             */
/*   Updated: 2023/05/05 15:03:14 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_overflowcheck(long long res, int sign)
{
	if (res < 0)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int) sign * res);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (ft_overflowcheck(res, sign));
}
