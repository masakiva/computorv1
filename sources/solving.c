/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:54:17 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/11/16 20:02:40 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void	free_content(void* content)
{
	free(content);
}

void	print_terms(t_equation* equation)
{
	t_list*	cur_link;
	t_term*	cur_term;

	cur_link = equation->left_terms;
	while (cur_link != NULL)
	{
		cur_term = (t_term*)cur_link->content;
		printf("left %f * X^%d\n", cur_term->parameter, cur_term->exponent);
		cur_link = cur_link->next;
	}
	cur_link = equation->right_terms;
	while (cur_link != NULL)
	{
		cur_term = (t_term*)cur_link->content;
		printf("right %f * X^%d\n", cur_term->parameter, cur_term->exponent);
		cur_link = cur_link->next;
	}
}

void	reduce_eq_form(t_equation* equation)
{
	t_list*	cur_link_r;
	t_list*	cur_link_l;
	t_term*	cur_term_r;
	t_term*	cur_term_l;

	cur_link_r = equation->right_terms;
	while (cur_link_r != NULL)
	{
		cur_term_r = (t_term*)cur_link_r->content;
		cur_link_l = equation->left_terms;
		while (cur_link_l != NULL) // search a parameter with the same exponent on l side
		{
			cur_term_l = (t_term*)cur_link_l->content;
			if (cur_term_l->exponent == cur_term_r->exponent) // found
			{
				cur_term_l->parameter -= cur_term_r->parameter;
				break ;
			}
			cur_link_l = cur_link_l->next;
		}
		if (cur_link_l == NULL) // not found
		{
			cur_term_l = malloc(sizeof(t_term));
			if (cur_term_l == NULL)
				error_exit(MALLOC_ERR);
			cur_term_l->exponent = cur_term_r->exponent;
			cur_term_l->parameter = cur_term_r->parameter * -1;
			cur_link_l = ft_lstnew(cur_term_l);
			if (cur_link_l == NULL)
				error_exit(MALLOC_ERR);
			ft_lstadd_back(&equation->left_terms, cur_link_l);
		}
		equation->right_terms = cur_link_r->next;
		ft_lstdelone(cur_link_r, free_content);
		cur_link_r = equation->right_terms;
	}
}

void	solve_equation(t_equation* equation)
{
	reduce_eq_form(equation);

	print_terms(equation);
}
