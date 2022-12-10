/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <mvidal-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:54:17 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/10 20:12:01 by mvidal-a         ###   ########.fr       */
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

void	merge_right_to_left(t_equation* equation)
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
		while (cur_link_l != NULL) // search for a parameter with the same exponent on left side
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

void	merge_left_terms(t_list* terms_list)
{
	t_list*	cur_link;
	t_term*	cur_term;
	t_list*	cur_link_2;
	t_list*	cur_link_2_prev;
	t_term*	cur_term_2;

	cur_link = terms_list;
	while (cur_link != NULL)
	{
		cur_term = cur_link->content;
		cur_link_2 = cur_link->next;
		cur_link_2_prev = cur_link;
		while (cur_link_2 != NULL)
		{
			cur_term_2 = cur_link_2->content;
			if (cur_term->exponent == cur_term_2->exponent)
			{
				cur_term->parameter += cur_term_2->parameter;
				cur_link_2_prev->next = cur_link_2->next;
				ft_lstdelone(cur_link_2, free_content);
			}
			cur_link_2_prev = cur_link_2;
			cur_link_2 = cur_link_2->next;
		}
		cur_link = cur_link->next;
	}
}

void	lstremoveone(t_list* link, t_list* prev_link, t_list** lst,
		void (*del)(void*))
{
	if (*lst == link)
		*lst = link->next;
	else
		prev_link->next = link->next;
	ft_lstdelone(link, del);
}

void	remove_null_terms(t_list** terms_list)
{
	t_list*	cur_link;
	t_term*	cur_term;
	t_list*	cur_link_prev;
	t_list*	cur_link_next;

	cur_link = *terms_list;
	cur_link_prev = NULL;
	while (cur_link != NULL)
	{
		cur_term = cur_link->content;
		if (cur_term->parameter == 0.0)
		{
			if (cur_link_prev == NULL && cur_link->next == NULL) // leave one null term
			{
				cur_term->exponent = 0;
				break ;
			}
			else
			{
				cur_link_next = cur_link->next;
				lstremoveone(cur_link, cur_link_prev, terms_list, free_content);
				cur_link = cur_link_next;
			}
		}
		else
		{
			cur_link_prev = cur_link;
			cur_link = cur_link->next;
		}
	}
}

void	sort_terms(t_list* terms_list)
{
	t_list*	cur_link;
	t_term*	cur_term;
	t_list*	cur_link_2;
	t_term*	cur_term_2;
	double	swap_param;
	int		swap_exp;

	cur_link = terms_list;
	while (cur_link != NULL)
	{
		cur_term = cur_link->content;
		cur_link_2 = cur_link->next;
		while (cur_link_2 != NULL)
		{
			cur_term_2 = cur_link_2->content;
			if (cur_term->exponent > cur_term_2->exponent)
			{
				swap_exp = cur_term->exponent;
				cur_term->exponent = cur_term_2->exponent;
				cur_term_2->exponent = swap_exp;
				swap_param = cur_term->parameter;
				cur_term->parameter = cur_term_2->parameter;
				cur_term_2->parameter = swap_param;
			}
			cur_link_2 = cur_link_2->next;
		}
		cur_link = cur_link->next;
	}
}

void	reduce_eq_form(t_equation* equation)
{
	merge_right_to_left(equation);
	merge_left_terms(equation->left_terms);
	remove_null_terms(&equation->left_terms);
	sort_terms(equation->left_terms);
}

void	print_reduced_form(t_equation* equation)
{
	t_list*	cur_link;
	t_term*	cur_term;
	double	cur_param_absolute;

	if (equation->left_terms == NULL)
		return ;
	cur_link = equation->left_terms;
	printf("Reduced form: ");
	while (cur_link != NULL)
	{
		cur_term = (t_term*)cur_link->content;
		cur_param_absolute = cur_term->parameter;
		if (cur_term->parameter < 0.0)
			cur_param_absolute *= -1;
		if (cur_link == equation->left_terms) // first term
		{
			if (cur_term->parameter < 0.0)
				printf("-");
		}
		else if (cur_term->parameter < 0.0)
			printf(" - ");
		else
			printf(" + ");
		if (cur_term->exponent == 0)
			printf("%g", cur_param_absolute);
		else if (cur_param_absolute == 1.0)
		{
			if (cur_term->exponent == 1)
				printf("X");
			else
				printf("X^%d", cur_term->exponent);
		}
		else if (cur_term->exponent == 1)
			printf("%g X", cur_param_absolute);
		else
			printf("%g X^%d", cur_param_absolute, cur_term->exponent);
		cur_link = cur_link->next;
	}
	printf(" = 0\n");
}

void	get_and_print_degree(t_equation* equation)
{
	t_list*	last_link;
	t_term*	highest_term;
	
	last_link = ft_lstlast(equation->left_terms);
	highest_term = last_link->content;
	equation->degree = highest_term->exponent;
	printf("Polynomial degree: %d\n", equation->degree);
}

int		get_lowest_exponent(t_equation* equation)
{
	t_term*	lowest_term;

	lowest_term = equation->left_terms->content;
	return (lowest_term->exponent);
}

int		analyze_equation(t_equation* equation)
{
	if (equation->left_terms == NULL && equation->right_terms == NULL)
		return (FALSE);
	reduce_eq_form(equation);
	print_reduced_form(equation);
	if (get_lowest_exponent(equation) < 0)
	{
		printf("This equation is not a polynomial since it contains a "\
				"negative power of X.\n"\
				"I can only solve polynomials of degree 2 or less.\n");
		return (FALSE);
	}
	get_and_print_degree(equation);
	if (equation->degree > 2)
	{
		printf("The polynomial degree is strictly greater than 2, "\
				"I can't solve.\n");
		return (FALSE);
	}
	return (TRUE);
}
