/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:50:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 00:45:21 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	ft_print_string(const char *string)
{
	if (string == 0)
		write(1, "(null)", 6);
	else
	{
		while (*string != '\0')
		{
			ft_print_char(*string);
			string++;
		}
	}
}
