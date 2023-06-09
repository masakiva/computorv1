/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:22 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 20:11:21 by mvidal-a         ###   ########.fr       */
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
		machine->state = DIGIT;
	else if (*eq_str == 'X' || *eq_str == 'x')
		machine->state = UNKNOWN;
	else if (*eq_str == '+' || *eq_str == '-')
		machine->state = PLUS_MINUS;
	else if (*eq_str == '=')
		machine->state = EQUAL_SIGN;
	else if (*eq_str == '\0')
		machine->state = END;
	else if (*eq_str == '*' || *eq_str == '/' || *eq_str == '%')
		error_exit(MULT_DIV);
	else if (*eq_str == '^')
		error_exit(CARET);
	else if (*eq_str == '(')
		error_exit(PARENTHESIS);
	else if (*eq_str == '<' || *eq_str == '>')
		error_exit(ANGLE_BRACKET);
	else if (ft_isalpha(*eq_str) && !ft_isalpha(eq_str[1]))
		error_exit(UNKNOWN_UNKNOWN);
	else
		error_exit(UNKNOWN_SYNTAX);
	return (eq_str);
}

char*	parse_parameter(t_term* term, t_state_machine* machine, char* eq_str)
{
	term->parameter = ft_atof(eq_str);
	if (machine->negative == TRUE)
	{
		term->parameter *= -1;
		machine->negative = FALSE;
	}
	eq_str = skip_float(eq_str);
	return (eq_str);
}


char*	parse_exponent(t_term* term, char* eq_str)
{
	eq_str++;
	if (*eq_str == '^')
	{
		eq_str++;
		if (ft_isint(eq_str) == FAILURE)
			error_exit(EXP_OVERFLOW);
		if (ft_atoi_sign(eq_str, &term->exponent) == FAILURE)
			error_exit(EXP_INVALID);
		eq_str = skip_int(eq_str);
		if (*eq_str == '.')
			error_exit(EXP_INVALID);
	}
	else
		term->exponent = 1;
	return (eq_str);
}

void	add_to_list(t_term* term, t_state_machine* machine)
{
	t_list*		new_link;

	new_link = ft_lstnew(term);
	if (new_link == NULL)
		error_exit(MALLOC_ERR);
	if (machine->right_side == FALSE)
		ft_lstadd_back(&machine->equation->left_terms, new_link);
	else
		ft_lstadd_back(&machine->equation->right_terms, new_link);
}

char*	digit(t_state_machine* machine, char* eq_str)
{
	t_term*		term;

	machine->plus_minus = FALSE;

	term = malloc(sizeof(t_term));
	if (term == NULL)
		error_exit(MALLOC_ERR);

	eq_str = parse_parameter(term, machine, eq_str);
	eq_str = skip_spaces(eq_str);
	if (*eq_str == '+' || *eq_str == '-' || *eq_str == '=' || *eq_str == '\0')
		term->exponent = 0;
	else if (*eq_str != '/' && *eq_str != '%' && *eq_str != '^'
			&& *eq_str != '(' && *eq_str != '<' && *eq_str != '>')
	{
		if (*eq_str == '*')
		{
			eq_str++;
			eq_str = skip_spaces(eq_str);
			if (ft_isdigit(*eq_str) || *eq_str == '-' || *eq_str == '+')
				error_exit(MULT_DIV);
		}
		if (*eq_str != 'X' && *eq_str != 'x')
		{
			if (ft_isalpha(*eq_str))
				error_exit(UNKNOWN_UNKNOWN);
			error_exit(TRAILING_ASTERISK);
		}
		eq_str = parse_exponent(term, eq_str);
		eq_str = skip_spaces(eq_str);
		if (*eq_str != '+' && *eq_str != '-' && *eq_str != '='
				&& *eq_str != '*' && *eq_str != '/' && *eq_str != '%'
				&& *eq_str != '^' && *eq_str != '('
				&& *eq_str != '<' && *eq_str != '>'
				&& *eq_str != '\0')
			error_exit(INVALID_TERM_BOUND);
	}

	add_to_list(term, machine);
	machine->state = SPACE;
	return (eq_str);
}

char*	unknown(t_state_machine* machine, char* eq_str)
{
	t_term*		term;

	machine->plus_minus = FALSE;

	term = malloc(sizeof(t_term));
	if (term == NULL)
		error_exit(MALLOC_ERR);

	eq_str = parse_exponent(term, eq_str);
	eq_str = skip_spaces(eq_str);
	if (*eq_str == '+' || *eq_str == '-' || *eq_str == '=' || *eq_str == '\0')
	{
		term->parameter = 1.0;
		if (machine->negative == TRUE)
		{
			term->parameter *= -1;
			machine->negative = FALSE;
		}
	}
	else if (*eq_str != '/' && *eq_str != '%' && *eq_str != '^'
			&& *eq_str != '(' && *eq_str != '<' && *eq_str != '>')
	{
		if (*eq_str != '*')
			error_exit(UNKNOWN_SYNTAX);
		eq_str++;
		eq_str = skip_spaces(eq_str);
		if (!ft_isdigit(*eq_str) && *eq_str != '-' && *eq_str != '+')
			error_exit(TRAILING_ASTERISK);
		eq_str = parse_parameter(term, machine, eq_str);
		eq_str = skip_spaces(eq_str);
		if (*eq_str != '+' && *eq_str != '-' && *eq_str != '='
				&& *eq_str != '*' && *eq_str != '/' && *eq_str != '%'
				&& *eq_str != '^' && *eq_str != '('
				&& *eq_str != '<' && *eq_str != '>'
				&& *eq_str != '\0')
			error_exit(INVALID_TERM_BOUND);
	}

	add_to_list(term, machine);
	machine->state = SPACE;
	return (eq_str);
}

char*	plus_minus(t_state_machine* machine, char* eq_str)
{
	machine->plus_minus = TRUE;
	if (*eq_str == '-')
	{
		if (machine->negative == TRUE)
			machine->negative = FALSE;
		else
			machine->negative = TRUE;
	}
	eq_str++;
	machine->state = SPACE;
	return (eq_str);
}

char*	equal_sign(t_state_machine* machine, char* eq_str)
{
	if (machine->right_side == TRUE)
		error_exit(TWO_EQUALS);
	if (machine->plus_minus == TRUE)
		error_exit(TRAILING_PLUS_MINUS);
	machine->right_side = TRUE;
	eq_str++;
	machine->state = SPACE;
	return (eq_str);
}

void	parse_equation(char* eq_str, t_equation* equation)
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
	machine.equation = equation;
	while (machine.state != END)
	{
		eq_str = process[machine.state](&machine, eq_str);
	}
	if (machine.plus_minus == TRUE)
		error_exit(TRAILING_PLUS_MINUS);
}
