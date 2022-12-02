/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:32:47 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/02 20:27:37 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

t_bool	ft_isint(char* str)
{
	size_t	i;
	long	nb;

	str = skip_spaces(str);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (i > 11)
		return (FALSE);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (FALSE);
	return (TRUE);
}

