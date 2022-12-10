/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:40:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 20:05:28 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

# define ARG_OPTIONS	"h"
# define HELP_OPTION	0x01
# define LONG_HELP_OPTION	"help"

# define HELP_MSG	"[computorv1] usage:\n"\
	"Provide a polynomial equation as the only argument of the program.\n"\
	"For example:\n"\
	"\t./computorv1 \"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\"\n"\
	"If the argument is a single dash (`-'), the equation is read from the "\
	"first line in standard input.\n"

enum		e_errcode
{
	MALLOC_ERR,
	WRITE_ERR,
	GNL_ERR,
	_ERRNO_END_,
	MULT_DIV,
	CARET,
	PARENTHESIS,
	ANGLE_BRACKET,
	UNKNOWN_UNKNOWN,
	EXP_OVERFLOW,
	EXP_INVALID,
	TRAILING_ASTERISK,
	TWO_EQUALS,
	INVALID_TERM_BOUND,
	TRAILING_PLUS_MINUS,
	UNKNOWN_SYNTAX,
};

t_byte	retrieve_options(int argc, char **argv, char *op_chars);

int		error_exit(enum e_errcode errcode);

#endif // ERROR_H
