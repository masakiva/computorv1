/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:54:17 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/27 18:31:22 by mvidal-a         ###   ########.fr       */
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

void	degree_0(t_equation* equation)
{
	equation->a = get_coeff(0, equation);

	printf("The boolean solution is:\n");
	if (equation->a == 0.0)
		printf("true\n");
	else
		printf("false\n");
}

void	degree_1(t_equation* equation)
{
	double	x;

	equation->a = get_coeff(1, equation);
	equation->b = get_coeff(0, equation);

	x = (-1 * equation->b) / equation->a;
	printf("The solution is:\n"\
			"%g\n", x);
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
	double	discriminant_sqrt;

	discriminant_sqrt = ft_sqrt_double(equation->discriminant);
	x1 = (-1 * equation->b - discriminant_sqrt)
		/ (2 * equation->a);
	x2 = (-1 * equation->b + discriminant_sqrt)
		/ (2 * equation->a);
	printf("Discriminant is strictly positive, the two solutions are:\n"\
			"%g\n%g\n", x1, x2);
}

void	null_discriminant(t_equation* equation)
{
	double	x;

	x = -1 * equation->b / (2 * equation->a);
	printf("Discriminant is null, there is one solution:\n"\
			"%g\n", x);
}

void	negative_discriminant(t_equation* equation)
{
	double	x_real;
	double	x1_imaginary;
	double	x2_imaginary;

	x_real = -1 * equation->b / (2 * equation->a);
	x2_imaginary = ft_sqrt_double(-1 * equation->discriminant)
		/ (2 * equation->a);
	x1_imaginary = x2_imaginary * -1;
	printf("Discriminant is strictly negative, there are two complex "\
			"solutions:\n");
	if (x2_imaginary < 0)
	{
		printf("%g - %gi\n", x_real, x2_imaginary * -1);
		printf("%g + %gi\n", x_real, x1_imaginary);
	}
	else
	{
		printf("%g + %gi\n", x_real, x2_imaginary);
		printf("%g - %gi\n", x_real, x1_imaginary * -1);
	}
}

void	solve_equation(t_equation* equation)
{
	switch (equation->degree)
	{
		case 0:
			degree_0(equation);
			break ;
		case 1:
			degree_1(equation);
			break ;
		case 2:
			get_coefficients(equation);
			get_discriminant(equation);
			if (equation->discriminant > 0.0)
				positive_discriminant(equation);
			else if (equation->discriminant == 0.0)
				null_discriminant(equation);
			else
				negative_discriminant(equation);
			break ;
		default:
			printf("ERROR, this should never happen!\n");
	}
}
