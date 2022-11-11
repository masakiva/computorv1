/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:05:23 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/11 16:35:51 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "main.h"

# define ARG_OPTIONS	"h"
# define HELP_OPTION	0x01
# define LONG_HELP_OPTION	"help"

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
	enum e_state	state;
	t_eq_terms*		eq_terms;
	t_byte			pad[4];
}				t_state_machine;

typedef char*	(*t_parse)(t_state_machine *, char *);

t_byte	retrieve_options(int argc, char **argv, char *op_chars);

void	parse_equation(char* eq_str, t_eq_terms* eq_terms);

// state machine states
char*	character(t_state_machine* machine, char* eq_str);
char*	digit(t_state_machine* machine, char* eq_str);
char*	unknown(t_state_machine* machine, char* eq_str);
char*	plus_minus(t_state_machine* machine, char* eq_str);
char*	equal_sign(t_state_machine* machine, char* eq_str);

// utils
int8_t			atof_double(char *str, double *nb_f);

#endif // PARSING_H
