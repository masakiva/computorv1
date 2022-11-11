/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:29:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/11 10:43:30 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char** argv)
{
	t_byte	options;

	if (argc > 1)
	{
		options = retrieve_options(argc, argv, ARG_OPTIONS);
		if (options & HELP_OPTION)
		{
			ft_putstr_fd(HELP_MSG, STDOUT_FILENO);
			return (EXIT_SUCCESS);
		}
	}

	return (EXIT_SUCCESS);
}
