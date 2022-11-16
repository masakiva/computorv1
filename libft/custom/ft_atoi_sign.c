/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:28:08 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 17:24:01 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_atoi_sign return value depends on the beginning characters of str:
**		-1 if the number begins with '-' (negative or null number)
**		0 if the number does not begin with a digit (error)
**		1 otherwise (positive or null number)
*/

int8_t		ft_atoi_sign(const char* str, int* nb)
{
	int8_t	sign_or_error;

	sign_or_error = 1;
	str = skip_spaces((char*)str);
	if (*str == '-')
	{
		sign_or_error = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	*nb = 0;
	if (*str < '0' || *str > '9')
		sign_or_error = FAILURE;
	while (*str >= '0' && *str <= '9')
	{
		*nb = *nb * 10 + *str - '0';
		str++;
	}
	*nb *= sign_or_error;
	return (sign_or_error);
}
