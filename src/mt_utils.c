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

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
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

