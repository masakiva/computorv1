/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:29:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/22 18:19:18 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <math.h>
#include <limits.h>
int		main(int argc, char** argv)
{
	t_byte		options;
	t_equation	equation;

	long	i = 0;
	while (i > 0)
	{
		if ((long)sqrt(i) != ft_sqrt_long(i))
		{
			printf("i = %ld\n", i);
			return (EXIT_FAILURE);
		}
		i--;
	}
	if (argc > 1)
	{
		ft_bzero(&equation, sizeof(t_equation));
		options = retrieve_options(argc, argv, ARG_OPTIONS);
		if (options & HELP_OPTION)
		{
			if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
				error_exit(WRITE_ERR);
			return (EXIT_SUCCESS);
		}

		parse_equation(argv[1], &equation);
		if (analyze_equation(&equation) == FALSE)
			return (EXIT_SUCCESS);
		solve_equation(&equation);
	}
	else
		if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
			error_exit(WRITE_ERR);

	return (EXIT_SUCCESS);
}
