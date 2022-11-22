/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:20:22 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/22 18:20:47 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt_double(double nb)
{
	double	sqrt;
	double	increment;
	int		i;

	sqrt = (double)ft_sqrt_long((long)nb);
	increment = 0.1;
	i = 0;
	while (i < 6)
	{
		while (sqrt * sqrt <= nb)
			sqrt += increment;
		sqrt -= increment;
		increment /= 10;
		i++;
	}
	return (sqrt);
}
