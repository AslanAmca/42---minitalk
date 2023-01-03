/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:48:11 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 00:45:25 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	ft_print_integer(int number)
{
	if (number == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		ft_print_integer(147483648);
	}
	else if (number < 0)
	{
		ft_print_char('-');
		ft_print_integer(number * -1);
	}
	else if (number < 10)
	{
		ft_print_char(number + '0');
	}
	else
	{
		ft_print_integer(number / 10);
		ft_print_integer(number % 10);
	}
}
