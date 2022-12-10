/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:05:23 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 19:31:32 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "main.h"

enum	e_state
{
	SPACE,
	DIGIT,
	UNKNOWN,
	PLUS_MINUS,
	EQUAL_SIGN,
	END,
	NB_STATES,
};

typedef struct	s_state_machine
{
	t_equation*		equation;
	enum e_state	state;
	t_bool			right_side;
	t_bool			negative;
	t_bool			plus_minus;
	t_byte			_pad[1];
}				t_state_machine;

typedef char*	(*t_parse)(t_state_machine *, char *);

void	parse_equation(char* eq_str, t_equation* equation);

// state machine states
char*	character(t_state_machine* machine, char* eq_str);
char*	unknown(t_state_machine* machine, char* eq_str);
char*	digit(t_state_machine* machine, char* eq_str);
char*	plus_minus(t_state_machine* machine, char* eq_str);
char*	equal_sign(t_state_machine* machine, char* eq_str);

#endif // PARSING_H
