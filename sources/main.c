/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:29:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 20:09:39 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>

char*	read_stdin(void)
{
	char*	line;
	int		ret;

	ret = get_next_line(STDIN_FILENO, &line);
	if (ret == ERROR)
		error_exit(GNL_ERR);
	return (line);
}

int		main(int argc, char** argv)
{
	t_byte		options;
	t_equation	equation;
	char*		input;

	if (argc > 1)
	{
		options = retrieve_options(argc, argv, ARG_OPTIONS);
		if (options & HELP_OPTION)
		{
			if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
				error_exit(WRITE_ERR);
			return (EXIT_SUCCESS);
		}
	}

	if (argc == 2)
	{
		ft_bzero(&equation, sizeof(t_equation));
		if (ft_strcmp(argv[1], "-") == 0)
		{
			input = read_stdin();
			parse_equation(input, &equation);
			free(input);
		}
		else
			parse_equation(argv[1], &equation);
		if (analyze_equation(&equation) == FALSE)
			return (EXIT_SUCCESS);
		solve_equation(&equation);
	}
	else
	{
		if (ft_putstr_fd(HELP_MSG, STDOUT_FILENO) != SUCCESS)
			error_exit(WRITE_ERR);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
