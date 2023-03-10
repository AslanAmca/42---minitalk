/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:47:27 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 04:18:21 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities/utilities.h"

void	ft_print_server_id(int server_id)
{
	ft_print_string("Server ID : ");
	ft_print_integer(server_id);
	ft_print_char('\n');
}

void	ft_receive_signal(int signal)
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
	}
}

int	main(void)
{
	ft_print_server_id(getpid());
	signal(SIGUSR1, ft_receive_signal);
	signal(SIGUSR2, ft_receive_signal);
	while (1)
		pause();
	return (0);
}
