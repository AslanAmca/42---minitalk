/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:41:15 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 16:19:57 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities/utilities.h"

void	ft_send_signal(int process_id, char *string)
{
	int	bit_index;

	while (*string != '\0')
	{
		bit_index = 0;
		while (bit_index <= 7)
		{
			if (*string & (1 << bit_index))
				kill(process_id, SIGUSR1);
			else
				kill(process_id, SIGUSR2);
			usleep(100);
			bit_index++;
		}
		string++;
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
	if (!ft_only_numeric(argv[1]))
	{
		ft_print_string("Server ID sayısal bir değer olmalıdır.\n");
		return (0);
	}
	server_id = ft_atoi(argv[1]);
	if (server_id <= 0)
	{
		ft_print_string("Server ID 0'dan büyük bir değer olmalıdır.\n");
		return (0);
	}
	ft_send_signal(server_id, argv[2]);
	return (0);
}
