/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:22 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 19:37:05 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include <stdlib.h>

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
	t_term*		term;
	t_list*		new_link;

	term = malloc(sizeof(t_term));
	if (term == NULL)
		error_exit(MALLOC_ERR);

	term->parameter = ft_atof(eq_str);
	if (machine->negative == TRUE)
	{
		term->parameter *= -1;
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
	if (ft_atoi_sign(eq_str, &term->exponent) == FAILURE)
		error_exit(UNKNOWN_SYNTAX);
	eq_str = skip_int(eq_str);

	new_link = ft_lstnew(term);
	if (new_link == NULL)
		error_exit(MALLOC_ERR);
	if (machine->right_side == FALSE)
		ft_lstadd_back(&machine->equation->left_terms, new_link);
	else
		ft_lstadd_back(&machine->equation->right_terms, new_link);

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

void	parse_equation(char* eq_str, t_equation* equation)
{
	static t_parse	process[NB_STATES - 1] = {
		space,
		equation_term,
		plus_minus,
		equal_sign
	};
	t_state_machine	machine;

	ft_bzero(&machine, sizeof(t_state_machine));
	machine.equation = equation;
	while (machine.state != END)
	{
		eq_str = process[machine.state](&machine, eq_str);
	}
}
