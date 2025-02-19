/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:20:31 by muokcan           #+#    #+#             */
/*   Updated: 2025/02/16 00:31:05 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mt_bonus.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static char	handle_message(int signal)
{
	static char	c = 0;
	static char	i = 0;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		return (c);
	}
	return (1);
}

static void	handle_signal(int signal, siginfo_t *si, void *context)
{
	(void)context;
	if (handle_message(signal) == '\0')
	{
		kill(si->si_pid, SIGUSR2);
		write(1, "\n", 1);
	}
	else
		kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	siginfo;

	ft_putstr("I'm starving for signals!\nOh by the way, my PID is: ");
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	siginfo.sa_flags = SA_SIGINFO;
	sigemptyset(&siginfo.sa_mask);
	siginfo.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &siginfo, NULL);
	sigaction(SIGUSR2, &siginfo, NULL);
	while (1)
		pause();
	return (0);
}
