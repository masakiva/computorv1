/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:22 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/11 16:37:48 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include <stdio.h>

char*	space(t_state_machine* machine, char* eq_str)
{
	while (ft_isspace(*eq_str))
		eq_str++;
	if (ft_isdigit(*eq_str))
		machine->state = DIGIT;
	else if (*eq_str == 'X')
		machine->state = UNKNOWN;
	else if (*eq_str == '+' || *eq_str == '-')
		machine->state = PLUS_MINUS;
	else if (*eq_str == '=')
		machine->state = EQUAL_SIGN;
	else
		error_exit(UNKNOWN_SYNTAX);
	return (eq_str);
}

char*	digit(t_state_machine* machine, char* eq_str)
{
	double	parameter;
	int8_t	ret;

	ret = atof_double(eq_str, &parameter);
	printf("%f\n", parameter);
	eq_str = skip_double(eq_str);
	machine->state = SPACE;
	return (eq_str);
}

char*	unknown(t_state_machine* machine, char* eq_str)
{
	machine->state = SPACE;
	return (eq_str);
}

char*	plus_minus(t_state_machine* machine, char* eq_str)
{
	machine->state = SPACE;
	return (eq_str);
}

char*	equal_sign(t_state_machine* machine, char* eq_str)
{
	machine->state = SPACE;
	return (eq_str);
}

void	parse_equation(char* eq_str, t_eq_terms* eq_terms)
{
	static t_parse	process[NB_STATES - 1] = {
		space,
		digit,
		unknown,
		plus_minus,
		equal_sign
	};
	t_state_machine	machine;

	ft_bzero(&machine, sizeof(t_state_machine));
	machine.eq_terms = eq_terms;
	while (machine.state != END)
	{
		eq_str = process[machine.state](&machine, eq_str);
	}
}
