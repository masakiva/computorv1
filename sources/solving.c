/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:54:17 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 19:15:59 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	solve_equation(t_eq_terms* eq_terms)
{
	int		exp;

	exp = 0;
	printf("Reduced form: ");
	while (exp < 3)
	{
		eq_terms->left[exp] -= eq_terms->right[exp];
		if (eq_terms->left[exp] < 0)
			printf("- %f * X^%d ", eq_terms->left[exp] * -1, exp);
		else
			printf("+ %f * X^%d ", eq_terms->left[exp], exp);
		exp++;
	}
	printf("= 0\n");
}
