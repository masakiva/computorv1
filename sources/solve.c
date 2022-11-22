/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:54:17 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/22 11:50:29 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

double	get_coeff(int exponent, t_equation* equation)
{
	t_list*	cur_link;
	t_term*	cur_term;

	cur_link = equation->left_terms;
	while (cur_link != NULL)
	{
		cur_term = (t_term*)cur_link->content;
		if (cur_term->exponent == exponent)
			return (cur_term->parameter);
		cur_link = cur_link->next;
	}
	return (0.0);
}

void	get_coefficients(t_equation* equation)
{
	equation->a = get_coeff(2, equation);
	equation->b = get_coeff(1, equation);
	equation->c = get_coeff(0, equation);
}

void	get_discriminant(t_equation* equation)
{
	equation->discriminant = ft_pow(equation->b, 2)
		- 4 * equation->a * equation->c;
}

void	positive_discriminant(t_equation* equation)
{
	double	x1;
	double	x2;

	printf("Discriminant is strictly positive, the two solutions are:\n");
	x1 = (-1 * equation->b - ft_sqrt(equation->discriminant))
		/ (2 * equation->a);
	x2 = (-1 * equation->b + ft_sqrt(equation->discriminant))
		/ (2 * equation->a);
	printf("%f\n%f\n", x1, x2);
}

void	solve_equation(t_equation* equation)
{
	switch (equation->degree)
	{
		case 0:
			break ;
		case 1:
			break ;
		case 2:
			get_coefficients(equation);
			get_discriminant(equation);
			if (equation->discriminant > 0.0)
				positive_discriminant(equation);
			else if (equation->discriminant == 0.0)
				;//null_discriminant();
			else
				;//negative_discriminant();
			break ;
	}
}
