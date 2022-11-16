/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:04:53 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 19:38:17 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"

typedef struct	s_equation
{
	t_list*	left_terms;
	t_list*	right_terms;

}				t_equation;

typedef struct	s_term
{
	double	parameter;
	int		exponent;
}				t_term;

void	solve_equation(t_equation* equation);

#endif // MAIN_H
