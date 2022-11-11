/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:04:53 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/11 16:12:40 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"

typedef struct	s_equation_terms
{
	double	l_x2;
	double	l_x1;
	double	l_x0;
	double	r_x2;
	double	r_x1;
	double	r_x0;

}				t_eq_terms;

#endif // MAIN_H
