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

#include <signal.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr_fd(pid_t n, int fd)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

pid_t	atod(char *str)
{
	pid_t	res;

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
