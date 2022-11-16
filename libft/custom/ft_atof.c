/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:33:52 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 16:37:11 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	atof_decimal_part(char *str)
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

t_bool		ft_atof(char *str, double *nb_f)
{
	int		nb_i;
	int8_t	sign_or_error;

	sign_or_error = ft_atoi_sign(str, &nb_i);
	*nb_f = (double)nb_i;
	if (sign_or_error == 1)
		*nb_f += atof_decimal_part(skip_int(str));
	else if (sign_or_error == -1)
		*nb_f -= atof_decimal_part(skip_int(str));
	else
		return (FAILURE);
	return (SUCCESS);
}
