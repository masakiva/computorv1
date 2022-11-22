/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:14:08 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/22 18:15:49 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_sqrt_long(long nb)
{
    long	start;
	long	end;
    long	mid;
	long	mid_sq;
    long	sqrt;

	if (nb < 0)
		return (-1);
	start = 0;
	if (nb <= 3037000499)
		end = nb;
	else
		end = 3037000499;
    while (start <= end)
	{
        mid = (start + end) / 2;
		mid_sq = mid * mid;
        if (mid_sq == nb)
		{
			sqrt = mid;
			break ;
		}
        if (mid_sq < nb)
		{
            start = mid + 1;
            sqrt = mid;
        }
        else
            end = mid - 1;
    }
	return (sqrt);
}
