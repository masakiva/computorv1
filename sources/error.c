/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:40:28 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 16:26:57 by mvidal-a         ###   ########.fr       */
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
		"The signs *, / and \% are not supported between equation terms "\
			"(only + and - are allowed)",
		"The sign ^ can only follow an X unknown",
		"Usage of parenthesis is not supported",
		"Usage of less-than and greater-than signs is not supported",
		"Equation can contain only one unknown, and it must be named X or x",
		"Exponent must be an int",
		"The sign ^ must be followed by an int",
		"Only one equal sign is allowed",
		"An equation term can only be followed by +, - or =",
		"+ or - signs must be followed by a number or an X unknown",
		"Unknown syntax",
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
