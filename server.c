/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:59:33 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/11 12:43:45 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static int	value;
	static int	bit_counter;

	(void)context;
	if (signo == SIGUSR1)
		value += 1 << bit_counter;
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &value, 1);
		if (value == '\0')
			kill(info->si_pid, SIGUSR1);
		value = 0;
		bit_counter = 0;
	}
}

void	ft_close(int i)
{
	(void)i;
	ft_printf("\nStopping server...\n");
	exit(0);
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	ft_printf("Starting server...\n");
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	signal(SIGINT, &ft_close);
	sigemptyset(&act.sa_mask);
	while (1)
		pause();
}
