/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:04:53 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 16:18:33 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"

typedef struct	s_equation
{
	t_list*	left_terms;
	t_list*	right_terms;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	int		degree;
	t_byte	_pad[4];
}				t_equation;

typedef struct	s_term
{
	double	parameter;
	int		exponent;
	t_byte	_pad[4];
}				t_term;

int		analyze_equation(t_equation* equation);
void	solve_equation(t_equation* equation);

#endif // MAIN_H
