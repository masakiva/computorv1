/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:40:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 17:45:15 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

# define HELP_MSG	"[computorv1] usage:\n"

enum		e_errcode
{
	MALLOC_ERR,
	WRITE_ERR,
	_ERRNO_END_,
	UNKNOWN_SYNTAX,
	NOT_SUPPORTED,
};

int		error_exit(enum e_errcode errcode);

#endif // ERROR_H
