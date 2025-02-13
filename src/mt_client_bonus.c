/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:20:28 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/12 22:26:00 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mt_bonus.h"
#include <stddef.h>
#include <signal.h>
#include <unistd.h>

_Bool	g_server_signal = 1;

static void	send_message(int pid, char *message)
{
	char	i;

	i = 7;
	while (*message)
	{
		while (i >= 0)
		{
			if ((*message >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_server_signal == 0)
				pause();
			g_server_signal = 0;
			i--;
		}
		message++;
		i = 7;
	}
}

static void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		g_server_signal = 1;
	else
		g_server_signal = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	siginfo;

	if (argc != 3)
	{
		ft_putstr("Invalid pattern!");
		return (-1);
	}
	siginfo.sa_handler = handle_signal;
	sigemptyset(&siginfo.sa_mask);
	siginfo.sa_flags = 0;
	sigaction(SIGUSR1, &siginfo, NULL);
	sigaction(SIGUSR2, &siginfo, NULL);
	send_message(atod(argv[1]), argv[2]);
}
