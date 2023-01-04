/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:03:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 04:24:34 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities/utilities.h"

void	ft_print_server_id(int server_id)
{
	ft_print_string("Server ID : ");
	ft_print_integer(server_id);
	ft_print_char('\n');
}

void	ft_receive_signal(int signal, siginfo_t *sig_info, void *context)
{
	static int	bit_index = 0;
	static char	character = 0;

	if (signal == SIGUSR1)
		character = character | 1 << bit_index;
	bit_index++;
	if (bit_index == 8)
	{
		ft_print_char(character);
		bit_index = 0;
		character = 0;
		kill(sig_info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	struct_sigaction;

	struct_sigaction.sa_flags = SA_SIGINFO;
	struct_sigaction.sa_sigaction = ft_receive_signal;
	ft_print_server_id(getpid());
	sigaction(SIGUSR1, &struct_sigaction, NULL);
	sigaction(SIGUSR2, &struct_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
