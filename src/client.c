/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:38:15 by tmalheir          #+#    #+#             */
/*   Updated: 2024/04/12 12:06:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_msg_sent;

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		g_msg_sent = 1;
}

void	send_byte(char c, pid_t pid)
{
	int	idx;
	int	bit;
	int	signal;

	idx = 0;
	while (idx < 8)
	{
		g_msg_sent = 0;
		bit = (c >> idx) & 1;
		if (bit == 1)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_printf("Error\n");
			exit (1);
		}
		idx++;
		while (g_msg_sent == 0)
			;
	}
}

void	send_msg(char *str, pid_t pid)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		send_byte(str[idx], pid);
		idx++;
	}
	send_byte('\n', pid);
	ft_printf("Mensagem enviada\n");
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_handler = &sig_handler;
	sigemptyset(&act.sa_mask);
	if ((sigaction(SIGUSR1, &act, NULL)) == -1
		|| (sigaction(SIGUSR2, &act, NULL)) == -1)
	{
		ft_putendl_fd("Error in handling signals.", 2);
		return (1);
	}
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("PID must be a positive integer and match server PID.");
		return (1);
	}
	send_msg(argv[2], pid);
	return (0);
}
