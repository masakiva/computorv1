/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:20:22 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/27 18:40:41 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	DELTA	0.000001

double	ft_abs(double nb)
{
	return (nb < 0.0 ? nb * -1.0 : nb);
}

//double	sqrt_integer_part(double nb)
//{
//    double	start;
//	double	end;
//    double	mid;
//	double	mid_sq;
//    double	sqrt;
//
//	start = 0.0;
//	end = nb;
//    while (start <= end)
//	{
//        mid = (start + end) / 2.0;
//		mid_sq = mid * mid;
//        if (mid_sq == nb)
//		{
//			sqrt = mid;
//			break ;
//		}
//        if (mid_sq < nb)
//		{
//            start = mid + 1.0;
//            sqrt = mid;
//        }
//        else
//            end = mid - 1.0;
//    }
//	return (sqrt);
//}
//
//double	sqrt_decimal_part(double nb, double sqrt)
//{
//	double	increment;
//	int		i;
//
//	increment = 0.5;
//	i = 0;
//	while (ft_abs((sqrt * sqrt) / nb - 1.0) >= DELTA)
//	{
//		while (sqrt * sqrt <= nb)
//		{
//			sqrt += increment;
//		}
//		sqrt -= increment;
//		increment /= 2.0;
//		i++;
//	}
//	return (sqrt);
//}
//
//double	ft_sqrt_double(double nb)
//{
//	double	sqrt;
//
//	if (nb < 0.0)
//		return (-1.0);
//
//	sqrt = sqrt_integer_part(nb);
//	sqrt = sqrt_decimal_part(nb, sqrt);
//
//	return (sqrt);
//}


// Newton–Raphson method
double	ft_sqrt_double(double nb)
{
    double	guess;
    double	root;
 
	guess = nb;
    while (1)
	{
        root = (guess + (nb / guess)) / 2.0;
 
        if (ft_abs(root / guess - 1.0) < DELTA)
            break;
 
        guess = root;
    }
 
    return (root);
}
