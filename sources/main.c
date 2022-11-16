/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:29:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 19:17:31 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
int		main(int argc, char** argv)
{
	t_byte		options;
	t_eq_terms	eq_terms;

	if (argc != 1)
	{
		ft_bzero(&eq_terms, sizeof(t_eq_terms));
		options = retrieve_options(argc, argv, ARG_OPTIONS);
		if (options & HELP_OPTION)
		{
			if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
				error_exit(WRITE_ERR);
			return (EXIT_SUCCESS);
		}

		parse_equation(argv[1], &eq_terms);

		solve_equation(&eq_terms);
	}
	else
		if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
			error_exit(WRITE_ERR);

	return (EXIT_SUCCESS);
}
