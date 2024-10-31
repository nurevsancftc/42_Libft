/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuciftci <nuciftci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:59:59 by nuciftci          #+#    #+#             */
/*   Updated: 2024/10/26 18:20:06 by nuciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (sign < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		sign;
	int		numblen;

	number = n;
	sign = 1;
	if (number < 0)
		sign = sign * -1;
	number = sign * number;
	numblen = number_len(number, sign);
	str = (char *)malloc(sizeof(char) * numblen + 1);
	if (!str)
		return (NULL);
	str[numblen] = '\0';
	while (--numblen >= 0)
	{
		str[numblen] = (number % 10) + 48;
		number = number / 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
