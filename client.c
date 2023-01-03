/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:41:15 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 00:48:52 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities/utilities.h"

void	send_message(int process_id, char *message)
{
	int	bit_index;

	while (*message != '\0')
	{
		bit_index = 0;
		while (bit_index <= 7)
		{
			if (*message & (1 << bit_index))
				kill(process_id, SIGUSR1);
			else
				kill(process_id, SIGUSR2);
			usleep(100);
			bit_index++;
		}
		message++;
	}
}

int	main(int argc, char *argv[])
{
	int	server_id;

	if (argc != 3)
	{
		ft_print_string("Sadece Server ID ve Mesaj girilmelidir.\n");
		return (0);
	}
	if (ft_not_numeric(argv[1]))
	{
		ft_print_string("Server ID sayısal bir değer olmalıdır.\n");
		return (0);
	}
	server_id = ft_atoi(argv[1]);
	if (server_id <= 0)
	{
		ft_print_string("Server ID 0'dan bir değer olmalıdır.\n");
		return (0);
	}
	send_message(server_id, argv[2]);
	return (0);
}
