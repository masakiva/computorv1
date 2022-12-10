/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:40:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/09 21:51:50 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

# define HELP_MSG	"[computorv1] usage:\n"\
	"Provide a polynomial equation as first argument of the program.\n"\
	"For example:\n"\
	"\t./computorv1 \"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\"\n"

enum		e_errcode
{
	MALLOC_ERR,
	WRITE_ERR,
	_ERRNO_END_,
	MULT_DIV,
	CARET,
	PARENTHESIS,
	ANGLE_BRACKET,
	UNKNOWN_UNKNOWN,
	EXP_OVERFLOW,
	EXP_INVALID,
	TWO_EQUALS,
	INVALID_TERM_BOUND,
	UNKNOWN_SYNTAX,
};

int		error_exit(enum e_errcode errcode);

#endif // ERROR_H
