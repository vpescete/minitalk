/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:59:47 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/11 14:49:39 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send(char c, int bit_counter, int pid)
{
	while (bit_counter < 8)
	{
		if ((c & (1 << bit_counter)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_counter++;
		usleep(1200);
	}
}

void	ft_check_bit(int pid, char *mss)
{
	int	index;
	int	bit_counter;

	index = 0;
	while (mss[index])
	{
		bit_counter = 0;
		ft_send(mss[index], bit_counter, pid); 
		index++;
	}
	
}

void	ft_handling_signal(int i)
{
	(void)i;
	ft_printf("The message has been sent to the server\n");
}

int	main(int ac, char **av)
{
	pid_t	c;

	c = 0;
	if (ac != 3)
	{
		ft_printf("Client Error\n");
		ft_printf("\tcorrect format [%s SERVER_PID MESSAGE]\n", av[0]);
		exit(0);
	}
	c = ft_atoi(av[1]);
	signal(SIGUSR1, &ft_handling_signal);
	ft_check_bit(c, av[2]);
	ft_send('\n', 0, c);
	ft_send('\0', 0, c);
}
