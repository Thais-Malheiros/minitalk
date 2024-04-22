/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:38:03 by tmalheir          #+#    #+#             */
/*   Updated: 2024/04/12 11:59:58 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	welcome_to_minitalk(void)
{
	ft_printf(" _____                                         ");
	ft_printf("                                     _____\n");
	ft_printf("( ___ )-----------------------------------------", "");
	ft_printf("-----------------------------------( ___ )\n");
	ft_printf(" |   |                                         ", "");
	ft_printf("                                     |   |\n");
	ft_printf(" |   | ooo        ooooo  o8o               o8o ", "");
	ft_printf("     .             oooo  oooo        |   |\n");
	ft_printf(" |   | `88.       .888'  `*                `*  ", "");
	ft_printf("   .o8             `888  `888        |   |\n");
	ft_printf(" |   |  888b     d'888  oooo  ooo. .oo.   oooo ", "");
	ft_printf(" .o888oo  .oooo.    888   888  oooo  |   |\n");
	ft_printf(" |   |  8  `888'   888   888   888   888   888 ", "");
	ft_printf("   888    .oP'888   888   888888.    |   |\n");
	ft_printf(" |   |  8    Y     888   888   888   888   888 ", "");
	ft_printf("   888 . d8(  888   888   888 `88b.  |   |\n");
	ft_printf(" |   | o8o        o888o o888o o888o o888o o888o", "");
	ft_printf("   '888  `Y888''8o o888o o888o o888o |   |\n");
	ft_printf(" |___|                                         ", "");
	ft_printf("                                     |___|\n");
	ft_printf("(_____)-----------------------------------------", "");
	ft_printf("-----------------------------------(_____)\n");
	ft_printf("            ----- Welcome to Minitalk! ------ ");
	ft_printf("The PID number is: %d ------\n\n", getpid());
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	byte;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		byte += 1 << bit;
	else if (signal == SIGUSR2)
		byte += 0 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if ((sigaction(SIGUSR1, &act, NULL)) == -1
		|| (sigaction(SIGUSR2, &act, NULL)) == -1)
	{
		ft_putendl_fd("Error in handling signals.", 2);
		return (1);
	}
	welcome_to_minitalk();
	while (1)
		pause();
	return (0);
}
