/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:33:52 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/02 18:02:47 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int8_t	atof_int_part(const char* str, double* nb)
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
	*nb = 0.0;
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

static double	atof_decimal_part(char* str)
{
	double	factor;
	double	decimal_part;

	if (*str != '.')
		return (0.0);
	else
		str++;
	decimal_part = 0.0;
	factor = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		factor *= 10.0;
		if (*str != '0')
			decimal_part += (double)(*str - '0') / factor;
		str++;
	}
	return (decimal_part);
}

double		ft_atof(const char* str)
{
	double	nb;
	int8_t	sign_or_error;

	sign_or_error = atof_int_part(str, &nb);
	if (sign_or_error == 1)
		nb += atof_decimal_part(skip_int((char*)str));
	else if (sign_or_error == -1)
		nb -= atof_decimal_part(skip_int((char*)str));
	return (nb);
}
