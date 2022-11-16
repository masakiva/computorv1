/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:04:53 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 18:55:52 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"

typedef struct	s_equation_terms
{
	double	left[3];
	double	right[3];

}				t_eq_terms;

void	solve_equation(t_eq_terms* eq_terms);

#endif // MAIN_H
