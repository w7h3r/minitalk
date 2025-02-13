/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:07:48 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/12 22:31:23 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*dtoa(int num)
{
	char	*res;
	int		temp;
	int		digit;

	digit = 0;
	temp = num;
	while (temp > 0)
	{
		temp /= 10;
		digit++;
	}
	res = malloc((digit + 1) * sizeof(char));
	if (!res)
	{
		ft_putstr("Malloc Error!: dtoa()");
		return (NULL);
	}
	res[digit] = '\0';
	while (num > 0)
	{
		res[--digit] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

int		atod(char *str)
{
	int	res;

	if (*str == '-')
		return (-1);
	if (*str == '0')
		return (0);
	res = 0;
	while (*str)
	{
		res = 10 * res + (*str - '0');
		str++;
	}
	return (res);
}

