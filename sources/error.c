/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:40:28 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/02 20:20:42 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int		error_exit(enum e_errcode errcode)
{
	const char		*err_msg[] = {
		"Memory allocation failure",
		"Cannot write on standard output",
		"--- separator ---",
		"Unknown syntax",
		"Exponent must be an int",
	};

	ft_putstr_fd("[computorv1] error: ", STDERR_FILENO);
	ft_putstr_fd(err_msg[errcode], STDERR_FILENO);
	if (errcode < _ERRNO_END_)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);

	exit(EXIT_FAILURE);
}
