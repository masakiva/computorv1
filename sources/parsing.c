/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:22 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 19:04:23 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"

char*	space(t_state_machine* machine, char* eq_str)
{
	while (ft_isspace(*eq_str))
		eq_str++;
	if (ft_isdigit(*eq_str))
		machine->state = EQUATION_TERM;
	else if (*eq_str == '+' || *eq_str == '-')
		machine->state = PLUS_MINUS;
	else if (*eq_str == '=')
		machine->state = EQUAL_SIGN;
	else if (*eq_str == '\0')
		machine->state = END;
	else
		error_exit(UNKNOWN_SYNTAX);
	return (eq_str);
}

char*	equation_term(t_state_machine* machine, char* eq_str)
{
	double	parameter;
	int		exponent;

	parameter = ft_atof(eq_str);
	if (machine->negative == TRUE)
	{
		parameter *= -1;
		machine->negative = FALSE;
	}
	eq_str = skip_float(eq_str);
	eq_str = skip_spaces(eq_str);
	if (*eq_str != '*')
		error_exit(UNKNOWN_SYNTAX);
	eq_str++;
	eq_str = skip_spaces(eq_str);
	if (eq_str[0] != 'X' || eq_str[1] != '^')
		error_exit(UNKNOWN_SYNTAX);
	eq_str += 2;
	if (ft_atoi_sign(eq_str, &exponent) == FAILURE)
		error_exit(UNKNOWN_SYNTAX);
	eq_str++;
	if (exponent >= 0 && exponent <= 2)
	{
		if (machine->right_side == FALSE)
			machine->eq_terms->left[exponent] = parameter;
		else
			machine->eq_terms->right[exponent] = parameter;
	}
	else
		error_exit(NOT_SUPPORTED);
	machine->state = SPACE;
	return (eq_str);
}

char*	plus_minus(t_state_machine* machine, char* eq_str)
{
	if (*eq_str == '-')
		machine->negative = TRUE;
	eq_str++;
	machine->state = SPACE;
	return (eq_str);
}

char*	equal_sign(t_state_machine* machine, char* eq_str)
{
	machine->right_side = TRUE;
	eq_str++;
	machine->state = SPACE;
	return (eq_str);
}

void	parse_equation(char* eq_str, t_eq_terms* eq_terms)
{
	static t_parse	process[NB_STATES - 1] = {
		space,
		equation_term,
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
