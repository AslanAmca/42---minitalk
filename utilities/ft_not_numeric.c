/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:03:27 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 16:21:45 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	ft_only_numeric(char *string)
{
	if (*string == '-' || *string == '+')
		string++;
	while (*string != '\0')
	{
		if (!ft_strchr("0123456789", *string))
			return (0);
		string++;
	}
	return (1);
}
