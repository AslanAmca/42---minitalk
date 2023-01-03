/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:47:27 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 00:51:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities/utilities.h"

void	print_server_id(int server_id)
{
	ft_print_string("Server ID : ");
	ft_print_integer(server_id);
	ft_print_char('\n');
}

void	receive_message(int signal)
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
	print_server_id(getpid());
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	while (1)
		pause();
	return (0);
}
